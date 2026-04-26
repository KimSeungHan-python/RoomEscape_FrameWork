// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_DungeonRoom1.h"
#include "Components/ArrowComponent.h"

ACPP_DungeonRoom1::ACPP_DungeonRoom1()
{
	Exit_Arrow1 = CreateDefaultSubobject<UArrowComponent>(TEXT("Exit_Arrow1"));
	Exit_Arrow2 = CreateDefaultSubobject<UArrowComponent>(TEXT("Exit_Arrow2"));
	Exit_Arrow3 = CreateDefaultSubobject<UArrowComponent>(TEXT("Exit_Arrow3"));

	Exit_Arrow1->SetupAttachment(ExitPointFolder);
	Exit_Arrow2->SetupAttachment(ExitPointFolder);
	Exit_Arrow3->SetupAttachment(ExitPointFolder);
}
