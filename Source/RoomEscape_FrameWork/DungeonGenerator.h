// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DungeonGenerator.generated.h"

class ACPP_DungeonRoom1;
class ARoomBase;
class AClosingWall;
class ADoor;
class ASpawnItemBase;
class ATreasureChestBase;

UCLASS()
class ROOMESCAPE_FRAMEWORK_API ADungeonGenerator : public AActor
{
	GENERATED_BODY()
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Sets default values for this actor's properties
	ADungeonGenerator();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "Rooms")
	TSubclassOf<ACPP_DungeonRoom1> StartRoom; // Why TSubClassOf -> Do Thinking

	UPROPERTY(EditAnywhere, Category = "Rooms")
	TArray<TSubclassOf<ARoomBase>> RoomsToBeSpawned;

	UPROPERTY(EditAnywhere, Category = "UnusedExitWall")
	TSubclassOf<AClosingWall> ClosingWall;

	UPROPERTY(EditAnywhere, Category = "Door")
	TSubclassOf<ADoor> Door;

	UPROPERTY(EditAnywhere, Category = "SpawnItem")
	TSubclassOf<ASpawnItemBase> ItemSpawnBase;

	UPROPERTY(EditAnywhere, Category = "TreasureChest")
	TSubclassOf<ATreasureChestBase> TreasureChestBase;
	
	UPROPERTY(EditAnywhere, Category = "Dungeon Info")
	int32 ItemAmount;

	UPROPERTY(EditAnywhere, Category = "Dungeon Info")
	int32 ChestAmount;

	UPROPERTY(EditAnywhere, Category = "Dungeon Info")
	int32 RoomAmount;

	ARoomBase* LatestSpawnedRoom;

	bool bCanSpawn;

	TArray<USceneComponent*> Exits;

	TArray<USceneComponent*> DoorList;

	TArray<USceneComponent*> SpawnPoints;

	TArray<USceneComponent*> LatestRoomSpawnPoints;


	FRandomStream RandomStream;

	UPROPERTY(EditAnywhere, Category = "Dungeon Info")
	int32 Seed;

	void SetSeed();

	void MyFunctionAfterDelay(); //Temporary function
	FTimerHandle TimerHandle;

	void SpawnStarterRoom();
	void SpawnNextRoom();
	void RemoveOverlappingRooms();
	void CloseUnusedExits();
	void SpawnDoors();
	void SpawnItems();	
	void SpawnChests();



};
