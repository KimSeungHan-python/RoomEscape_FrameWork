// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PauseWidget.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPauseReGameClicked);
//DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPauseQuitClicked);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPauseNewGameClicked);
//class UButton;
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
protected:
    //UPauseWidget(); 기본 생성자를 쓰지는 않음 NativeConstruct가 그 역할을 함
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
