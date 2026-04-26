// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_DungeonRoom2.h"
#include "Components/ArrowComponent.h"

ACPP_DungeonRoom2::ACPP_DungeonRoom2()
{
	Exit_Arrow1 = CreateDefaultSubobject<UArrowComponent>(TEXT("Exit_Arrow1"));
	Exit_Arrow2 = CreateDefaultSubobject<UArrowComponent>(TEXT("Exit_Arrow2"));
	ClosingWall= CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ClosingWall"));

	Exit_Arrow1->SetupAttachment(ExitPointFolder);
	Exit_Arrow2->SetupAttachment(ExitPointFolder);
	ClosingWall->SetupAttachment(GeometryFolder);
}
