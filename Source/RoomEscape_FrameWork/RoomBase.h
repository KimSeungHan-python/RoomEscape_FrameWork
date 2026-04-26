// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RoomBase.generated.h"


class UBoxComponent;
class UArrowComponent;
UCLASS()
class ROOMESCAPE_FRAMEWORK_API ARoomBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARoomBase();

	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(VisibleAnywhere, Category = "Components")
	USceneComponent* DefaultSceneRoot;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	USceneComponent* GeometryFolder;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	USceneComponent* OverlapFolder;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	USceneComponent* ExitPointFolder;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* Cube_1;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* Cube_2;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* Cube_3;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* Cube_4;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* Cube_5;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* Cube_6;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* Cube_7;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* Cube_8;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* Floor;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UBoxComponent* BoxCollision;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UArrowComponent* Arrow;

};
