// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_Bridge.h"
#include "Components/ArrowComponent.h"

ACPP_Bridge::ACPP_Bridge()
{
	Exit_Arrow1 = CreateDefaultSubobject<UArrowComponent>(TEXT("Exit_Arrow1"));

	Exit_Arrow1->SetupAttachment(ExitPointFolder);
}
