// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_DungeonRoom3.h"
#include "Components/ArrowComponent.h"
ACPP_DungeonRoom3::ACPP_DungeonRoom3()
{
	Exit_Arrow1 = CreateDefaultSubobject<UArrowComponent>(TEXT("Exit_Arrow1"));
	ClosingWall1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ClosingWall1"));
	ClosingWall2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ClosingWall2"));

	Exit_Arrow1->SetupAttachment(ExitPointFolder);
	ClosingWall1->SetupAttachment(GeometryFolder);
	ClosingWall2->SetupAttachment(GeometryFolder);
}
