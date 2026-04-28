// Fill out your copyright notice in the Description page of Project Settings.


#include "TreasureChestBase.h"

// Sets default values
ATreasureChestBase::ATreasureChestBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Chest = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Chest"));
	Chest->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ATreasureChestBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATreasureChestBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

