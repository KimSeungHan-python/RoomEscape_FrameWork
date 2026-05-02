// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "EndWidget.generated.h"

//class UButton;
/**
 * 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnEndReGameClicked);
//DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnEndQuitClicked);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnEndNewGameClicked);

UCLASS()
class ROOMESCAPE_FRAMEWORK_API UEndWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
    UPROPERTY(BlueprintAssignable)
    FOnEndReGameClicked DOnReGameClicked;

    //UPROPERTY(BlueprintAssignable)
    //FOnEndQuitClicked DOnQuitClicked;

    UPROPERTY(BlueprintAssignable)
    FOnEndNewGameClicked DOnNewGameClicked;

protected:
    //UEndWidget(); 기본 생성자를 쓰지는 않음 NativeConstruct가 그 역할을 함
    //virtual void NativeConstruct() override;

    UFUNCTION(BlueprintCallable)
    virtual void OnReGameClicked();

    UFUNCTION(BlueprintCallable)
    virtual void OnNewGameClicked();

    UFUNCTION(BlueprintCallable)
    virtual void OnQuitClicked();




    //UPROPERTY(meta = (BindWidget))
    //UButton* RestartButton;

    //UPROPERTY(meta = (BindWidget))
    //UButton* QuitButton;
};
