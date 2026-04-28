// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_DungeonRoom4.h"
#include "Components/ArrowComponent.h"

ACPP_DungeonRoom4::ACPP_DungeonRoom4()
{
	Exit_Arrow1 = CreateDefaultSubobject<UArrowComponent>(TEXT("Exit_Arrow1"));
	ClosingWall1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ClosingWall1"));
	ClosingWall2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ClosingWall2"));

	Exit_Arrow1->SetupAttachment(ExitPointFolder);
	ClosingWall1->SetupAttachment(GeometryFolder);
	ClosingWall2->SetupAttachment(GeometryFolder);

	Spawn_Point_1 = CreateDefaultSubobject<UArrowComponent>(TEXT("Spawn_Point_1"));
	Spawn_Point_2 = CreateDefaultSubobject<UArrowComponent>(TEXT("Spawn_Point_2"));
	Spawn_Point_3 = CreateDefaultSubobject<UArrowComponent>(TEXT("Spawn_Point_3"));
	Spawn_Point_4 = CreateDefaultSubobject<UArrowComponent>(TEXT("Spawn_Point_4"));
	Spawn_Point_5 = CreateDefaultSubobject<UArrowComponent>(TEXT("Spawn_Point_5"));
	Spawn_Point_6 = CreateDefaultSubobject<UArrowComponent>(TEXT("Spawn_Point_6"));

	Spawn_Point_1->SetupAttachment(FloorSpawnPoints);
	Spawn_Point_2->SetupAttachment(FloorSpawnPoints);
	Spawn_Point_3->SetupAttachment(FloorSpawnPoints);
	Spawn_Point_4->SetupAttachment(FloorSpawnPoints);
	Spawn_Point_5->SetupAttachment(FloorSpawnPoints);
	Spawn_Point_6->SetupAttachment(FloorSpawnPoints);
}
