// Fill out your copyright notice in the Description page of Project Settings.


#include "SpecialRoom.h"
#include "Components/ArrowComponent.h"
#include "Components/BoxComponent.h"

ASpecialRoom::ASpecialRoom()
{
	PrimaryActorTick.bCanEverTick = true;

	Exit_Arrow_1 = CreateDefaultSubobject<UArrowComponent>(TEXT("Exit_Arrow_1"));
	Exit_Arrow_2 = CreateDefaultSubobject<UArrowComponent>(TEXT("Exit_Arrow_2"));
	Exit_Arrow_3 = CreateDefaultSubobject<UArrowComponent>(TEXT("Exit_Arrow_3"));
	Exit_Arrow_4 = CreateDefaultSubobject<UArrowComponent>(TEXT("Exit_Arrow_4"));

	Floor_1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Floor_1"));
	Floor_2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Floor_2"));
	Floor_3 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Floor_3"));
	Floor_4 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Floor_4"));

	SecondF_Wall_1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SecondF_Wall_1"));
	SecondF_Wall_2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SecondF_Wall_2"));
	SecondF_Wall_3 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SecondF_Wall_3"));
	SecondF_Wall_4 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SecondF_Wall_4"));
	SecondF_Wall_5 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SecondF_Wall_5"));
	SecondF_Wall_6 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SecondF_Wall_6"));
	SecondF_Wall_7 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SecondF_Wall_7"));
	SecondF_Wall_8 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SecondF_Wall_8"));

	ClosingWall_1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ClosingWall_1"));
	ClosingWall_2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ClosingWall_2"));
	ClosingWall_3 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ClosingWall_3"));

	ElevatorCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("ElevatorCollision"));

	Elevator = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Elevator"));

	Exit_Arrow_1->SetupAttachment(ExitPointFolder);
	Exit_Arrow_2->SetupAttachment(ExitPointFolder);
	Exit_Arrow_3->SetupAttachment(ExitPointFolder);
	Exit_Arrow_4->SetupAttachment(ExitPointFolder);

	Floor_1->SetupAttachment(GeometryFolder);
	Floor_2->SetupAttachment(GeometryFolder);
	Floor_3->SetupAttachment(GeometryFolder);
	Floor_4->SetupAttachment(GeometryFolder);

	SecondF_Wall_1->SetupAttachment(GeometryFolder);
	SecondF_Wall_2->SetupAttachment(GeometryFolder);
	SecondF_Wall_3->SetupAttachment(GeometryFolder);
	SecondF_Wall_4->SetupAttachment(GeometryFolder);
	SecondF_Wall_5->SetupAttachment(GeometryFolder);
	SecondF_Wall_6->SetupAttachment(GeometryFolder);
	SecondF_Wall_7->SetupAttachment(GeometryFolder);
	SecondF_Wall_8->SetupAttachment(GeometryFolder);

	ClosingWall_1->SetupAttachment(GeometryFolder);
	ClosingWall_2->SetupAttachment(GeometryFolder);
	ClosingWall_3->SetupAttachment(GeometryFolder);

	Elevator->SetupAttachment(GeometryFolder);
	ElevatorCollision->SetupAttachment(Elevator);
}

void ASpecialRoom::BeginPlay()
{
	Super::BeginPlay();
}

void ASpecialRoom::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
