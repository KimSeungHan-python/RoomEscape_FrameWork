// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RoomBase.h"
#include "CPP_Bridge.generated.h"

class UArrowComponent;
/**
 * 
 */
UCLASS()
class ROOMESCAPE_FRAMEWORK_API ACPP_Bridge : public ARoomBase
{
	GENERATED_BODY()
	

public:

	ACPP_Bridge();

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UArrowComponent* Exit_Arrow1;
};
