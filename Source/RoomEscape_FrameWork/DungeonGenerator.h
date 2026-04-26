// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DungeonGenerator.generated.h"

class ACPP_DungeonRoom1;

UCLASS()
class ROOMESCAPE_FRAMEWORK_API ADungeonGenerator : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADungeonGenerator();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, Category = "Rooms")
	TSubclassOf<ACPP_DungeonRoom1> StartRoom; // Why TSubClassOf -> Do Thinking

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;



};
