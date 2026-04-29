// Fill out your copyright notice in the Description page of Project Settings.


#include "BossRoom.h"

ABossRoom::ABossRoom()
{
	Closing_Wall_1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Closing_Wall_1"));
	Closing_Wall_2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Closing_Wall_2"));
	Closing_Wall_3 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Closing_Wall_3"));
	RedPlane = CreateDefaultSubobject<UStaticMeshComponent>(TEXT(" RedPlane"));

	Closing_Wall_1->SetupAttachment(GeometryFolder);
	Closing_Wall_2->SetupAttachment(GeometryFolder);
	Closing_Wall_3->SetupAttachment(GeometryFolder);
	RedPlane->SetupAttachment(GeometryFolder);
}
