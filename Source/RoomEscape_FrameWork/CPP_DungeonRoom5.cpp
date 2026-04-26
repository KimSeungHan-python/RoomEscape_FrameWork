// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_DungeonRoom5.h"
#include "Components/ArrowComponent.h"


ACPP_DungeonRoom5::ACPP_DungeonRoom5()
{
	Exit_Arrow1 = CreateDefaultSubobject<UArrowComponent>(TEXT("Exit_Arrow1"));
	ClosingWall1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ClosingWall1"));
	ClosingWall2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ClosingWall2"));

	Exit_Arrow1->SetupAttachment(ExitPointFolder);
	ClosingWall1->SetupAttachment(GeometryFolder);
	ClosingWall2->SetupAttachment(GeometryFolder);
}
