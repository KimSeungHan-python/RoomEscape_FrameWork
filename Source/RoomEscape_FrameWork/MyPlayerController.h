// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

class UUserWidget;
class UInputMappingContext;
class UInputAction;
class UPauseWidget;
class AHUD;
class AMyHUD;
/**
 * 
 */
UCLASS()
class ROOMESCAPE_FRAMEWORK_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
    void ShowGameOverUI();
    void ShowGameStartUI();

    UFUNCTION()
    void HandleRestart();

protected:
    AMyPlayerController();
    virtual void BeginPlay() override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
    TSubclassOf<class UUserWidget> GameOverWidgetClass;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
    TSubclassOf<class UUserWidget> GameStartWidgetClass;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
    TSubclassOf<class UUserWidget> PauseWidgetClass;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HUD")
    TSubclassOf<class AHUD> HUDWidgetClass;

    UPROPERTY(EditAnywhere, Category = "Input")
    class UInputMappingContext* IMC;

    UPROPERTY(EditAnywhere, Category = "Input")
    class UInputAction* IA_Pause;



    UPauseWidget* CurrentPauseWidget;
    AMyHUD* HUDWidget;


    void TogglePauseMenu();
    virtual void SetupInputComponent() override;
    virtual void OnPossess(APawn* aPawn) override;
    virtual void OnUnPossess() override;
};
