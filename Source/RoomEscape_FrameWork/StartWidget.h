// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "StartWidget.generated.h"

/**
 * 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnStartGameClicked);

UCLASS()
class ROOMESCAPE_FRAMEWORK_API UStartWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
    UPROPERTY(BlueprintAssignable)
    FOnStartGameClicked DOnStartGameClicked;

protected:
    //UEndWidget(); 기본 생성자를 쓰지는 않음 NativeConstruct가 그 역할을 함
    //virtual void NativeConstruct() override;

    UFUNCTION(BlueprintCallable)
    virtual void OnGameStartClicked();

    UFUNCTION(BlueprintCallable)
    virtual void OnQuitClicked();



    //UPROPERTY(meta = (BindWidget))
    //UButton* RestartButton;

    //UPROPERTY(meta = (BindWidget))
    //UButton* QuitButton;
};
