// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainWidget.generated.h"


class UProgressBar;
class UTextBlock;
class UImage;
class UTexture2D;

/**
 * 
 */
UCLASS()
class ROOMESCAPE_FRAMEWORK_API UMainWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	// meta = (BindWidget)은 블루프린트 위젯의 이름과 이 변수 이름이 똑같아야 연결해 주는 마법의 매크로입니다.
	UPROPERTY(meta = (BindWidget))
	UProgressBar* HPBar;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* AmmoText;

	UPROPERTY(meta = (BindWidget))
	UImage* GunImage;

public:
	// 외부(플레이어 캐릭터 등)에서 UI를 업데이트할 때 부를 함수들
	UFUNCTION(BlueprintCallable, Category = "HUD|Status")
	void UpdateHP(float CurrentHP, float MaxHP);

	UFUNCTION(BlueprintCallable, Category = "HUD|Status")
	void UpdateAmmo(int32 CurrentAmmo, int32 MaxAmmo);

	UFUNCTION(BlueprintCallable, Category = "HUD|Status")
	void UpdateGunImage(UTexture2D* NewGunTexture);
};
