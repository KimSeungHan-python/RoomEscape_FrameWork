// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RoomBase.h"
#include "DungeonElevatorRoom.generated.h"

/**
 * 
 */
UCLASS()
class ROOMESCAPE_FRAMEWORK_API ADungeonElevatorRoom : public ARoomBase
{
	GENERATED_BODY()

public:
	ADungeonElevatorRoom();

protected:

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UArrowComponent* Exit_Arrow_1;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UArrowComponent* Exit_Arrow_2;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UArrowComponent* Exit_Arrow_3;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UArrowComponent* Exit_Arrow_4;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* Floor_2;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* SecondF_Wall_1;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* SecondF_Wall_2;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* SecondF_Wall_3;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* SecondF_Wall_4;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* SecondF_Wall_5;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* SecondF_Wall_6;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* SecondF_Wall_7;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* SecondF_Wall_8;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* ClosingWall_1;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* ClosingWall_2;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* ClosingWall_3;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* Elevator;
	
};
