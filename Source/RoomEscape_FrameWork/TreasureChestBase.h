// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TreasureChestBase.generated.h"

UCLASS()
class ROOMESCAPE_FRAMEWORK_API ATreasureChestBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATreasureChestBase();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* Chest;


};
