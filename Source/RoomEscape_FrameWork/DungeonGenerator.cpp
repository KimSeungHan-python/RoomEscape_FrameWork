// Fill out your copyright notice in the Description page of Project Settings.


#include "DungeonGenerator.h"
#include "CPP_DungeonRoom1.h"
#include "RoomBase.h"
#include "Components/BoxComponent.h"
#include "ClosingWall.h"
#include "Door.h"

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


	SpawnStarterRoom();
	SpawnNextRoom();
	FTimerHandle UnusedHandle;
	FTimerHandle DoorHandle;

	SetSeed();

	GetWorld()->GetTimerManager().SetTimer(UnusedHandle, this, &ADungeonGenerator::CloseUnusedExits, 1.0f, false);
	GetWorld()->GetTimerManager().SetTimer(DoorHandle, this, &ADungeonGenerator::SpawnDoors, 1.0f, false);
	//MyFunctionAfterDelay();
}

void ADungeonGenerator::SetSeed()// Why make this? -> Answer: Same Seed = Same Map
{
	int32 Results;
	if (Seed == -1)
	{
		Results = FMath::Rand();
	}
	else
	{
		Results = Seed;
	}
	RandomStream.Initialize(Results);
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("%d"), Results));
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
	ACPP_DungeonRoom1* SpawnedStarterRoom = this->GetWorld()->SpawnActor<ACPP_DungeonRoom1>(StartRoom);
	SpawnedStarterRoom->SetActorLocation(this->GetActorLocation());
	
	SpawnedStarterRoom->ExitPointFolder->GetChildrenComponents(false, Exits);//Get Arrow
}

void ADungeonGenerator::SpawnNextRoom()
{
	bCanSpawn = true;

	int32 RoomIndex = RandomStream.RandRange(0, RoomsToBeSpawned.Num() - 1);
	int32 ExitIndex = RandomStream.RandRange(0, Exits.Num() - 1);
	USceneComponent* SelectedExitPoint = Exits[ExitIndex];

	//if(RoomsToBeSpawned)
	LatestSpawnedRoom = this->GetWorld()->SpawnActor<ARoomBase>(RoomsToBeSpawned[RoomIndex]);


	if (LatestSpawnedRoom)
	{
		LatestSpawnedRoom->SetActorLocation(SelectedExitPoint->GetComponentLocation()); // why no spawn? <- meshes didn't included
		LatestSpawnedRoom->SetActorRotation(SelectedExitPoint->GetComponentRotation());

		UE_LOG(LogTemp, Warning, TEXT("Spawned Room Name: %s"), *LatestSpawnedRoom->GetName());

		DoorList.Add(SelectedExitPoint);//Set Door SelectedExitPoint


		RemoveOverlappingRooms();



		if (bCanSpawn)
		{
			Exits.Remove(SelectedExitPoint);//Previous Point Remove

			TArray<USceneComponent*> LatestRoomExitPoints;
			LatestSpawnedRoom->ExitPointFolder->GetChildrenComponents(false, LatestRoomExitPoints);//Change Arrow Components from Next Room
			Exits.Append(LatestRoomExitPoints); // I think it also not good Maybe change this for later.

			//Now Logics have overlap Spawning Problem, so it have to be changed
		}

		RoomAmount = RoomAmount - 1;
		if (RoomAmount > 0)
		{
			SpawnNextRoom();// It is not good in my opinion
		}
	}


}

void ADungeonGenerator::RemoveOverlappingRooms()// must to understand it!!!!
{
	TArray<USceneComponent*> OverlappedRooms;
	LatestSpawnedRoom->OverlapFolder->GetChildrenComponents(false, OverlappedRooms);// Box Collision

	TArray<UPrimitiveComponent*> OverlappingComponents;
	for (USceneComponent* Element : OverlappedRooms)
	{
		Cast<UBoxComponent>(Element)->GetOverlappingComponents(OverlappingComponents);
	}

	for (UPrimitiveComponent* Element : OverlappingComponents)
	{
		bCanSpawn = false;//; why do this?
		RoomAmount = RoomAmount + 1;
		LatestSpawnedRoom->Destroy();
	}

}

void ADungeonGenerator::CloseUnusedExits()
{
	for (USceneComponent* Element : Exits)
	{
		AClosingWall* LatestClosingWallSpawned = GetWorld()->SpawnActor<AClosingWall>(ClosingWall);

		FVector RelativeOffset(00.0f, -70.0f, 320.0f); // World Location <-just hard coding
		//FVector WorldOffset = Element->GetComponentRotation().RotateVector(RelativeOffset);

		LatestClosingWallSpawned->SetActorLocation(Element->GetComponentLocation() + RelativeOffset);//Why WorldOffset?
		LatestClosingWallSpawned->SetActorRotation(FRotator(Element->GetComponentRotation()) + FRotator(0.0f, 90.0f, 0.0f));
	}
}

void ADungeonGenerator::SpawnDoors()
{
	//GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this,&ACharacter::OnBeginOverlap);
	//GetCapsuleComponent()->OnComponentEndOverlap.AddDynamic(this,&ACharacter::OnEndOverlap);
	//Use tag and UFUNCTION()
	//Use Cast<ADoor>
	for (USceneComponent* Element : DoorList)// Player can open door by BeginOverlap
	{
		ADoor* LatestDoorSpawned = GetWorld()->SpawnActor<ADoor>(Door);// How to Change Something can interact or just Open<- Thinking  

		FVector RelativeOffset(00.0f, -70.0f, 320.0f); // World Location <-just hard coding
		//FVector WorldOffset = Element->GetComponentRotation().RotateVector(RelativeOffset);

		LatestDoorSpawned->SetActorLocation(Element->GetComponentLocation() + RelativeOffset);//Why WorldOffset?
		LatestDoorSpawned->SetActorRotation(FRotator(Element->GetComponentRotation()) + FRotator(0.0f, 90.0f, 0.0f));
	}
}



// Called every frame
void ADungeonGenerator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

