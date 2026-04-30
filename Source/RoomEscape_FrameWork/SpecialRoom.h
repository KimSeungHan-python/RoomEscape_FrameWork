// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RoomBase.h"
#include "SpecialRoom.generated.h"


class UArrowComponent;
class UBoxComponent;
/**
 * 
 */
UCLASS()
class ROOMESCAPE_FRAMEWORK_API ASpecialRoom : public ARoomBase
{
	GENERATED_BODY()

public:
	ASpecialRoom();
	
protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	//UPROPERTY(VisibleAnywhere, Category = "Components")
	//UArrowComponent* Exit_Arrow_1;

	//UPROPERTY(VisibleAnywhere, Category = "Components")
	//UArrowComponent* Exit_Arrow_2;

	//UPROPERTY(VisibleAnywhere, Category = "Components")
	//UArrowComponent* Exit_Arrow_3;

	//UPROPERTY(VisibleAnywhere, Category = "Components")
	//UArrowComponent* Exit_Arrow_4;

	//UPROPERTY(VisibleAnywhere, Category = "Components")
	//UStaticMeshComponent* Floor_1;

	//UPROPERTY(VisibleAnywhere, Category = "Components")
	//UStaticMeshComponent* Floor_2;

	//UPROPERTY(VisibleAnywhere, Category = "Components")
	//UStaticMeshComponent* Floor_3;

	//UPROPERTY(VisibleAnywhere, Category = "Components")
	//UStaticMeshComponent* Floor_4;

	//UPROPERTY(VisibleAnywhere, Category = "Components")
	//UStaticMeshComponent* SecondF_Wall_1;

	//UPROPERTY(VisibleAnywhere, Category = "Components")
	//UStaticMeshComponent* SecondF_Wall_2;

	//UPROPERTY(VisibleAnywhere, Category = "Components")
	//UStaticMeshComponent* SecondF_Wall_3;

	//UPROPERTY(VisibleAnywhere, Category = "Components")
	//UStaticMeshComponent* SecondF_Wall_4;

	//UPROPERTY(VisibleAnywhere, Category = "Components")
	//UStaticMeshComponent* SecondF_Wall_5;

	//UPROPERTY(VisibleAnywhere, Category = "Components")
	//UStaticMeshComponent* SecondF_Wall_6;

	//UPROPERTY(VisibleAnywhere, Category = "Components")
	//UStaticMeshComponent* SecondF_Wall_7;

	//UPROPERTY(VisibleAnywhere, Category = "Components")
	//UStaticMeshComponent* SecondF_Wall_8;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* ClosingWall_1;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* ClosingWall_2;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* ClosingWall_3;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* Elevator;


	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* Platform;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UBoxComponent* ElevatorCollision;

	FVector StartLocation;

	FVector EndLocation;

	bool bShouldMove;

	float MoveSpeed = 10.0f;

	FVector CurrentLocation;
	
};
