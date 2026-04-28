// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnItemBase.h"
#include "Components/BoxComponent.h"
#include "GameFramework/RotatingMovementComponent.h"

// Sets default values
ASpawnItemBase::ASpawnItemBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Coin = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Coin"));
	CoinCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("CoinCollision"));
	RotatingMovementComponent = CreateDefaultSubobject<URotatingMovementComponent>(TEXT("Rotating_Movement_Component"));

	Coin->SetupAttachment(RootComponent);
	CoinCollision->SetupAttachment(Coin);
}

// Called when the game starts or when spawned
void ASpawnItemBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpawnItemBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

