// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class ROOMESCAPE_FRAMEWORK_API AMyGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	

protected:
	AMyGameModeBase();

	virtual void BeginPlay() override;

public:

	void GameOver();//플레이어에서 호출하고 있음
	//void GamePause();
	void GameStart();
};
