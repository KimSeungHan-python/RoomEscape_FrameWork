// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RoomBase.h"
#include "CPP_DungeonRoom2.generated.h"

/**
 * 
 */
UCLASS()
class ROOMESCAPE_FRAMEWORK_API ACPP_DungeonRoom2 : public ARoomBase
{
	GENERATED_BODY()
	
public:
	ACPP_DungeonRoom2();

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UArrowComponent* Exit_Arrow1;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UArrowComponent* Exit_Arrow2;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* ClosingWall;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UArrowComponent* Spawn_Point_1;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UArrowComponent* Spawn_Point_2;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UArrowComponent* Spawn_Point_3;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UArrowComponent* Spawn_Point_4;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UArrowComponent* Spawn_Point_5;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UArrowComponent* Spawn_Point_6;
};
