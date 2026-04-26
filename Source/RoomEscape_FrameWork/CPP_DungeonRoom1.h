// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RoomBase.h"
#include "CPP_DungeonRoom1.generated.h"

/**
 * 
 */
UCLASS()
class ROOMESCAPE_FRAMEWORK_API ACPP_DungeonRoom1 : public ARoomBase
{
	GENERATED_BODY()

public:

	ACPP_DungeonRoom1();

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UArrowComponent* Exit_Arrow1;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UArrowComponent* Exit_Arrow2;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UArrowComponent* Exit_Arrow3;
	
};
