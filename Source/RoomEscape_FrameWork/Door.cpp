// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"
#include "Components/BoxComponent.h"

// Sets default values
ADoor::ADoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Default_Scene_Root"));
	Door = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door"));
	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box_Collision"));

	DefaultSceneRoot->SetupAttachment(RootComponent);
	Door->SetupAttachment(DefaultSceneRoot);
	BoxCollision->SetupAttachment(DefaultSceneRoot);

}

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();
	
	StartLocation = Door->GetRelativeLocation();
}

void ADoor::OpenDoor()
{
	EndLocation = CurrentLocation - FVector(0.0f, 0.0f, 400.0f);// Open by Down 
	bShouldMove = true;
}

void ADoor::CloseDoor()
{
	EndLocation = StartLocation;
	bShouldMove = false;

}

// Called every frame
void ADoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CurrentLocation = Door->GetRelativeLocation();
	if (bShouldMove)
	{
		FVector NewLocation = FMath::VInterpTo(CurrentLocation, EndLocation, DeltaTime, MoveSpeed);
		Door->SetRelativeLocation(NewLocation);
	}
}

