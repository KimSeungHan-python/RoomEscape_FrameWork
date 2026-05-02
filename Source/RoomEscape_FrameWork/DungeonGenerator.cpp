// Fill out your copyright notice in the Description page of Project Settings.


#include "DungeonGenerator.h"
#include "CPP_DungeonRoom1.h"
#include "RoomBase.h"
#include "Components/BoxComponent.h"
#include "ClosingWall.h"
#include "Door.h"
#include "SpawnItemBase.h"
#include "TreasureChestBase.h"
#include "BossRoom.h"
#include "Kismet/GameplayStatics.h"
#include "StarterRoom.h"
#include "MyGameInstance.h"

// Sets default values
ADungeonGenerator::ADungeonGenerator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


}

// Called when the game starts or when spawned
void ADungeonGenerator::BeginPlay()
{
	Super::BeginPlay();

	if (UMyGameInstance* GI = GetGameInstance<UMyGameInstance>())
	{
		switch (GI->StartMode)
		{
		case EStartMode::MainMenu:
			SetSeed();//맨 처음에만 입력을 받음 
			//RuntimeSeed = Seed; // 유저 입력 사용
			break;

		case EStartMode::RestartSame:
			Seed = GI->SavedSeed;
			break;

		case EStartMode::RestartNew:
			Seed = -1;
			break;
		}
	}
	SetSeed();

	SpawnStarterRoom();
	SpawnNextRoom();


}

// Called every frame
void ADungeonGenerator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bDungeonRoomComplete)
	{
		//방이 전부 생성되고 나서 생성이 되어야함.
		while (ItemAmount > 0 && SpawnPoints.Num() > 0)
		{
			SpawnItems();
		}

		while (ChestAmount > 0 && SpawnPoints.Num() > 0)
		{
			SpawnChests();
		}
		CloseUnusedExits();//문 닫기
		SpawnDoors();
		//GetWorld()->GetTimerManager().SetTimer(UnusedHandle, this, &ADungeonGenerator::CloseUnusedExits, 1.0f, false);
		//GetWorld()->GetTimerManager().SetTimer(DoorHandle, this, &ADungeonGenerator::SpawnDoors, 1.0f, false);
		bDungeonRoomComplete = false;
	}

}

void ADungeonGenerator::SetSeed()// Why make this? -> Answer: Same Seed = Same Map
{
	if (Seed == -1)
	{
		Seed = FMath::Rand();
	}

	if (UMyGameInstance* GI = GetGameInstance<UMyGameInstance>())
	{
		GI->SavedSeed = Seed;//Seed값 저장
	}

	RandomStream.Initialize(Seed);
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("%d"), Seed));
}

void ADungeonGenerator::MyFunctionAfterDelay()
{
	float DelayTime = 2.0f; // 
	GetWorldTimerManager().SetTimer(
		TimerHandle,
		this,
		&ADungeonGenerator::SpawnNextRoom,
		DelayTime,
		false // 
	);

}

void ADungeonGenerator::SpawnStarterRoom()
{
	//시작하는 방은 RoomAmount안하고 있음
	AStarterRoom* SpawnedStarterRoom = this->GetWorld()->SpawnActor<AStarterRoom>(StartRoom);
	SpawnedStarterRoom->SetActorLocation(this->GetActorLocation());
	
	SpawnedStarterRoom->ExitPointFolder->GetChildrenComponents(false, Exits);//Get Arrow

	SpawnedStarterRoom->ExitPointFolder->GetChildrenComponents(false, ClosingUnusedExitsList);//Get Arrow
	LatestRoomUnusedExitsList.Append(ClosingUnusedExitsList);

	SpawnedStarterRoom->FloorSpawnPoints->GetChildrenComponents(false, SpawnPoints);
}




void ADungeonGenerator::SpawnNextRoom()// 방번호랑 (방 전체 화살표 중에 어디로 생길지 랜덤으로 정함 그리고 스포할 수 없으면)
{
	bCanSpawn = true;
	bCanUseSpawnPoints = true;//원하는 곳에 보스룸 만들기 위해

	if (RoomAmount == 1)
	{
		bCanUseSpawnPoints = false;
	}

	// 일반 방을 지정된 개수만큼 만들었고, 아직 스폰할 특수 방이 남았다면?  특수방 순서대로 만들어야  <- 지금은 전체 방 개수를 고려하고 있지않음 이거 생각해서 처리해야함
	if (RoomsSpawnedInCurrentPhase >= RoomsPerPhase && CurrentSpecialRoomIdx < SpecialRoomsToBeSpawned.Num())
	{
		LatestSpawnedRoom = this->GetWorld()->SpawnActor<ARoomBase>(SpecialRoomsToBeSpawned[CurrentSpecialRoomIdx]);
		bIsSpecialRoom = true; // (헤더에 bool 변수 추가 필요)
		//RoomsPerPhase = 0;// 초기화 해줘야함인데 이게 문제는 지금 겹치는경우 쳐내고 있는건데 밑에서 해주자 아니네 취소되고 다시돌아와도 이 조건문이네
	}
	else
	{
		int32 RoomIndex = RandomStream.RandRange(0, RoomsToBeSpawned.Num() - 1);
		LatestSpawnedRoom = this->GetWorld()->SpawnActor<ARoomBase>(RoomsToBeSpawned[RoomIndex]);
		bIsSpecialRoom = false;
	}


	int32 ExitIndex = RandomStream.RandRange(0, Exits.Num() - 1);
	SelectedExitPoint = Exits[ExitIndex];//화살표임 SelectedExitPoint는 

	//if(RoomsToBeSpawned)


	LatestSpawnedRoom->SetActorLocation(SelectedExitPoint->GetComponentLocation()); // why no spawn? <- meshes didn't included
	LatestSpawnedRoom->SetActorRotation(SelectedExitPoint->GetComponentRotation());

	UE_LOG(LogTemp, Warning, TEXT("Spawned Room Name: %s"), *LatestSpawnedRoom->GetName());

	//방 생성을 해줌(위치랑 회전)



	RemoveOverlappingRooms();// 겹치면 삭제하고 다시 만들게 함


	if (bCanSpawn)//이걸 통과해야지 실제로 맵에 생성이 됨
	{
		if (bIsSpecialRoom)
		{
			CurrentSpecialRoomIdx++;
			RoomsSpawnedInCurrentPhase = 0; // 페이즈 초기화
			DoorList.Add(SelectedExitPoint);//특수방 입구만 문 설치
		}//가장큰 단점은 특수방의 개수와 마지막이 겹치는 경우도 이경우는 제대로 체크해야한다. 일단 내가 개발자니까 넘어가고 후에 사용자가 쓸때 못하게 막아야함


		//Items
		if (!bCanUseSpawnPoints) // 이 방식은 RoomAmount가 하나 남았을때인데 다른방식으로 수정해야할듯 조건문을 보스방이라면 
		{
			LatestSpawnedRoom->FloorSpawnPoints->GetChildrenComponents(false, LatestRoomSpawnPoints);
			SpawnPoints.Append(LatestRoomSpawnPoints);//아이템이나 Chest 생성 포인트들
			DoorList.Add(SelectedExitPoint);
		}


		//Doors

		Exits.Remove(SelectedExitPoint);//Previous Point Remove

		if (bLinearDungeon)//여기서 초기화 해주는거지 개꿀 따라시 
		{
			Exits.Empty(); // 새로 생성된 방을 제외하고 이전에 가지고 있던 것들을 없앰, 그래서 ClosingUnusedExitsList가 모든 것을 들고 있게 위임됨.
		}

		LatestRoomUnusedExitsList.Remove(SelectedExitPoint);
		LatestSpawnedRoom->ExitPointFolder->GetChildrenComponents(false, ClosingUnusedExitsList);//아무래도 GetChildrenComponents 두번쨰 인자는 저장공간인듯<- 이거 아닌듯 수정한거 보니까
		LatestRoomUnusedExitsList.Append(ClosingUnusedExitsList);

		TArray<USceneComponent*> LatestRoomExitPoints;
		LatestSpawnedRoom->ExitPointFolder->GetChildrenComponents(false, LatestRoomExitPoints);//생성된 룸에서 방이 생길 수 있는 화살표(들)를 가져옴
		Exits.Append(LatestRoomExitPoints); // I think it also not good Maybe change this for later.

		//Now Logics have overlap Spawning Problem, so it have to be changed
		RoomAmount = RoomAmount - 1;
		UE_LOG(LogTemp, Warning, TEXT("%d"), RoomAmount);

		SpawnedRooms.Add(LatestSpawnedRoom);
	}

	
	if (RoomAmount > 0)
	{
		//SpawnNextRoom();// It is not good in my opinion 재귀이기 때문에
		GetWorld()->GetTimerManager().SetTimer(SpawningRoomHandle, this, &ADungeonGenerator::SpawnNextRoom, 0.01f, false);
	}
	else
	{
		bDungeonRoomComplete = true;
	}


}

void ADungeonGenerator::RemoveOverlappingRooms()// must to understand it!!!! 겹침이 일어나면 마지막에 스폰된 방을 지움 
{
	TArray<USceneComponent*> OverlapBoxComponents;
	LatestSpawnedRoom->OverlapFolder->GetChildrenComponents(false, OverlapBoxComponents);// 마지막 생성된 방의 박스 콜리전을 가져옴, OverlappedRooms에 계속 추가됨 
																					// OverlappedRooms에 가져온 충돌(박스콜리전)을 넣어줌
	//TArray<UPrimitiveComponent*> OverlappingComponents;
	for (USceneComponent* Element : OverlapBoxComponents)
	{
		for (ARoomBase* Room : SpawnedRooms)
		{
			if (Cast<UBoxComponent>(Element)->IsOverlappingActor(Room))
			{
				bCanSpawn = false;
				LatestSpawnedRoom->Destroy();
				if (bLinearDungeon)
				{
					RestartDungeon();
				}
			}
		}

		//Cast<UBoxComponent>(Element)->GetOverlappingComponents(OverlappingComponents); //거기서 실제로 겹침이 일어난 것들을가져옴 // 왜 삭제하는 것이지?
	}

	//for (UPrimitiveComponent* Element : OverlappingComponents)// 왜 삭제하는것이지?
	//{
	//	bCanSpawn = false;//; why do this? -> can't spawn if false
	//	//RoomAmount = RoomAmount + 1;
	//	LatestSpawnedRoom->Destroy();
	//}

}

void ADungeonGenerator::CloseUnusedExits()
{
	for (USceneComponent* Element : LatestRoomUnusedExitsList)
	{
		AClosingWall* LatestClosingWallSpawned = GetWorld()->SpawnActor<AClosingWall>(ClosingWall);

		//FVector RelativeOffset(0, 30, 0); // World Location <-just hard coding
		//FVector WorldOffset = Element->GetComponentRotation().RotateVector(RelativeOffset);

		LatestClosingWallSpawned->SetActorLocation(Element->GetComponentLocation() - Element->GetForwardVector() * 20);//Why WorldOffset?
		LatestClosingWallSpawned->SetActorRotation(FRotator(Element->GetComponentRotation()) + FRotator(0.0f, 90.0f, 0.0f));
	}
}

void ADungeonGenerator::SpawnDoors()
{
	//GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this,&ACharacter::OnBeginOverlap);
	//GetCapsuleComponent()->OnComponentEndOverlap.AddDynamic(this,&ACharacter::OnEndOverlap);
	//Use tag and UFUNCTION()
	//Use Cast<ADoor>
	UE_LOG(LogTemp, Warning, TEXT("Spawn_Door"));
	for (USceneComponent* Element : DoorList)// Player can open door by BeginOverlap
	{
		ADoor* LatestDoorSpawned = GetWorld()->SpawnActor<ADoor>(Door);// How to Change Something can interact or just Open<- Thinking  


		LatestDoorSpawned->SetActorLocation(Element->GetComponentLocation());//Why WorldOffset?
		LatestDoorSpawned->SetActorRotation(FRotator(Element->GetComponentRotation()) + FRotator(0.0f, 90.0f, 0.0f));
		
	}
}

void ADungeonGenerator::SpawnItems()// 나중에 아이템들이 아닌 각 아이템 개수로도 가능할듯
{
	if (ItemAmount > 0)
	{
		USceneComponent* SelectedSpawnPoint;
		int32 SpawnPointIndex = RandomStream.RandRange(0, SpawnPoints.Num() - 1);// 생성된 룸에서 스폰 포인트들
		SelectedSpawnPoint = SpawnPoints[SpawnPointIndex];

		//원한다면 랜덤으로 몇명나올지도 수정 가능/

		int32 SpawnItemIndex = RandomStream.RandRange(0, ItemSpawnList.Num() - 1);//랜덤으로 뽑고 
		ASpawnItemBase* LatestItemSpawned = this->GetWorld()->SpawnActor<ASpawnItemBase>(ItemSpawnList[SpawnItemIndex]);// 소환 
		LatestItemSpawned->SetActorLocation(SelectedSpawnPoint->GetComponentLocation() + FVector(0, 0, 100.0f));

		SpawnPoints.Remove(SelectedSpawnPoint);//왜 . 이지 ->게 아니라

		ItemAmount = ItemAmount - 1;
	}
}

void ADungeonGenerator::SpawnChests()
{
	if (ChestAmount > 0)
	{
		USceneComponent* SelectedSpawnPoint;
		int32 SpawnPointIndex = RandomStream.RandRange(0, SpawnPoints.Num() - 1);// 생성된 룸에서 스폰 포인트들
		SelectedSpawnPoint = SpawnPoints[SpawnPointIndex];

		ATreasureChestBase* LatestChestSpawned = this->GetWorld()->SpawnActor<ATreasureChestBase>(TreasureChestBase);
		LatestChestSpawned->SetActorLocation(SelectedSpawnPoint->GetComponentLocation() + FVector(0, 0, 100.0f));

		SpawnPoints.Remove(SelectedSpawnPoint);//왜 . 이지 ->게 아니라//이거 문제 있음 생각해봐야함

		ChestAmount = ChestAmount - 1;
	}
}

void ADungeonGenerator::SpawnBossRoom()
{
	// 마지막에 생성된 방을 없애고 만들어버림
	// 마지막에 생성된 방을 없애고 있기 때문에 고민을 해야됨. 목표는 마지막 방에는 정해진 아이템이 떨어지게 만들고 싶음
	ABossRoom* BossRoom = this->GetWorld()->SpawnActor<ABossRoom>(BossRoomToBeSpawned);
	
	BossRoom->SetActorLocation(SelectedExitPoint->GetComponentLocation());
	BossRoom->SetActorRotation(SelectedExitPoint->GetComponentRotation());


	LatestSpawnedRoom->Destroy();

}

void ADungeonGenerator::RestartDungeon()
{
	FName CurrentLevel = GetWorld()->GetFName();//이건 뭐냐?
	UGameplayStatics::OpenLevel(GetWorld(), CurrentLevel);
}





