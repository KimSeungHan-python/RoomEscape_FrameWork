// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyGameInstance.generated.h"

/**
 * 
 */

//UENUM()
enum class EStartMode
{
    MainMenu,     // 처음 실행
    RestartSame,  // 같은 Seed
    RestartNew    // 새로운 Seed
};

UCLASS()
class ROOMESCAPE_FRAMEWORK_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
    EStartMode StartMode = EStartMode::MainMenu;

    int32 SavedSeed = -1;

    // 밝기 값을 저장할 변수 (기본값 1.0)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
    float SavedBrightness = 0.1f;
};
