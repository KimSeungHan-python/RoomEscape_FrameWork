// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RoomBase.h"
#include "StarterRoom.generated.h"

class UArrowComponent;
/**
 * 
 */
UCLASS()
class ROOMESCAPE_FRAMEWORK_API AStarterRoom : public ARoomBase
{
	GENERATED_BODY()
	
protected:
	AStarterRoom();

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UArrowComponent* Exit_Arrow_1;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UArrowComponent* Exit_Arrow_2;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UArrowComponent* Exit_Arrow_3;

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

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UBoxComponent* BoxCollision_2;
};
