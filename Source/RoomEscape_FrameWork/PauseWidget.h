// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PauseWidget.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPauseReGameClicked);
//DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPauseQuitClicked);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPauseNewGameClicked);
//class UButton;
class USlider;
class UMyGameInstance;
class APlayerController;
/**
 * 
 */
UCLASS()
class ROOMESCAPE_FRAMEWORK_API UPauseWidget : public UUserWidget
{
	GENERATED_BODY()

public:
    UPROPERTY(BlueprintAssignable)
    FOnPauseReGameClicked DOnReGameClicked;

    //UPROPERTY(BlueprintAssignable)
    //FOnPauseQuitClicked DOnQuitClicked;

    UPROPERTY(BlueprintAssignable)
    FOnPauseNewGameClicked DOnNewGameClicked;

    // UI 디자이너에 추가할 슬라이더 바인딩
    UPROPERTY(meta = (BindWidget))
    USlider* BrightnessSlider;

    UPROPERTY()
    UMyGameInstance* GI;

    UPROPERTY()
    APlayerController* PC;

protected:

    // 위젯이 생성될 때 C++와 BP를 연결해주는 초기화 함수
    virtual void NativeConstruct() override;
    //UPauseWidget(); 기본 생성자를 쓰지는 않음 NativeConstruct가 그 역할을 함
    

    // 슬라이더 값이 변경될 때 호출될 함수
    UFUNCTION(BlueprintCallable)
    void OnBrightnessChanged(float Value);

    UFUNCTION(BlueprintCallable)
    void ApplyChangedBrightness(float Value);

    //virtual void NativeConstruct() override;

    UFUNCTION(BlueprintCallable)
    virtual void OnReGameClicked();

    UFUNCTION(BlueprintCallable)
    virtual void OnQuitClicked();

    UFUNCTION(BlueprintCallable)
    virtual void OnNewGameClicked();

    UFUNCTION(BlueprintCallable)
    void OnResumeClicked();

    //UPROPERTY(meta = (BindWidget))
    //UButton* ReGameButton;

    //UPROPERTY(meta = (BindWidget))
    //UButton* QuitButton;

    //UPROPERTY(meta = (BindWidget))
    //UButton* ResumeButton;
};
