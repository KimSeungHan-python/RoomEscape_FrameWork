// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnItemBase.generated.h"

class UBoxComponent;
class URotatingMovementComponent;

UCLASS()
class ROOMESCAPE_FRAMEWORK_API ASpawnItemBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnItemBase();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* Coin;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UBoxComponent* CoinCollision;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	URotatingMovementComponent* RotatingMovementComponent;



};
