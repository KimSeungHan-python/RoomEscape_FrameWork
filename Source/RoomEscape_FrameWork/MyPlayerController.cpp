// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "StartWidget.h"
#include "EndWidget.h"
#include "PauseWidget.h"
#include "MyHUD.h"
#include "MyGameInstance.h"
#include "EngineUtils.h" // TActorIterator를 사용하기 위해 필요
#include "Engine/DirectionalLight.h"
#include "Components/LightComponent.h"

AMyPlayerController::AMyPlayerController()
{

}

void AMyPlayerController::BeginPlay()
{
    Super::BeginPlay();

    //PauseWidget 생성하기 
    if (PauseWidgetClass)
    {
        CurrentPauseWidget = CreateWidget<UPauseWidget>(this, PauseWidgetClass);

        if (CurrentPauseWidget)
        {
            CurrentPauseWidget->AddToViewport();
            CurrentPauseWidget->SetVisibility(ESlateVisibility::Hidden);
        }
    }

    GI = Cast<UMyGameInstance>(GetGameInstance());
    ApplySavedBrightness();

}



void AMyPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

    if (UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(InputComponent))
    {
        EIC->BindAction(IA_Pause, ETriggerEvent::Started, this, &AMyPlayerController::TogglePauseMenu);
    }
}

void AMyPlayerController::OnPossess(APawn* aPawn)
{
    Super::OnPossess(aPawn);

    if (ULocalPlayer* LocalPlayer = GetLocalPlayer())
    {
        if (UEnhancedInputLocalPlayerSubsystem* Subsystem = 
            LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
        {
            Subsystem->AddMappingContext(IMC, 0);
        }
    }
}

void AMyPlayerController::OnUnPossess()
{
    Super::OnUnPossess();
}

void AMyPlayerController::ApplySavedBrightness()//밝기 조절 
{
    if (GI)
    {
        float SavedValue = GI->SavedBrightness;
        float NewIntensity = SavedValue * 10.0f;

        for (TActorIterator<ADirectionalLight> It(GetWorld()); It; ++It)
        {
            if (ADirectionalLight* SunLight = *It)
            {
                SunLight->GetLightComponent()->SetIntensity(NewIntensity);
            }
        }
    }
}

void AMyPlayerController::TogglePauseMenu()
{
    //// 위젯이 아직 생성 안 된 경우 → 최초 1회 생성
    //if (!CurrentPauseWidget)
    //{
    //    if (PauseWidgetClass)
    //    {
    //        CurrentPauseWidget = CreateWidget<UPauseWidget>(this, PauseWidgetClass);

    //        if (CurrentPauseWidget)
    //        {
    //            CurrentPauseWidget->AddToViewport();
    //            CurrentPauseWidget->SetVisibility(ESlateVisibility::Hidden);
    //        }
    //    }
    //}

    //if (!CurrentPauseWidget)
    //{
    //    UE_LOG(LogTemp, Warning, TEXT("Return"));
    //    return;
    //}

    // 현재 상태 확인
    if (CurrentPauseWidget->IsVisible())
    {
        UE_LOG(LogTemp, Warning, TEXT("Close"));
        // 닫기
        CurrentPauseWidget->SetVisibility(ESlateVisibility::Hidden);

        SetInputMode(FInputModeGameAndUI());
        SetShowMouseCursor(false);

        //SetPause(false);

        //UGameplayStatics::SetGamePaused(this, false); // 기본적으로 모든 InputAction 막힘
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Open"));

        // 열기
        CurrentPauseWidget->SetVisibility(ESlateVisibility::Visible);


        CurrentPauseWidget->DOnReGameClicked.AddDynamic(this, &AMyPlayerController::HandleRestart);
        CurrentPauseWidget->DOnNewGameClicked.AddDynamic(this, &AMyPlayerController::HandleRestart);

        SetInputMode(FInputModeGameAndUI());
        SetShowMouseCursor(true);

        //UGameplayStatics::SetGamePaused(this, true);
        //SetPause(true);
    }
}

void AMyPlayerController::ShowGameOverUI()
{
    if (GameOverWidgetClass)
    {
        UEndWidget* Widget = CreateWidget<UEndWidget>(this, GameOverWidgetClass);
        if (Widget)
        {
            Widget->AddToViewport();


            Widget->DOnReGameClicked.AddDynamic(this, &AMyPlayerController::HandleRestart);
            Widget->DOnNewGameClicked.AddDynamic(this, &AMyPlayerController::HandleRestart);

            SetShowMouseCursor(true);
            SetInputMode(FInputModeUIOnly());
        }
    }
}

void AMyPlayerController::ShowGameStartUI()
{
    if (GameStartWidgetClass)
    {
        StartWidget = CreateWidget<UStartWidget>(this, GameStartWidgetClass);
        if (StartWidget)
        {
            StartWidget->AddToViewport();


            SetShowMouseCursor(true);
            SetInputMode(FInputModeUIOnly());

            StartWidget->DOnStartGameClicked.AddDynamic(this, &AMyPlayerController::HandleStart);
            //SetPause(true);

        }
    }
}

void AMyPlayerController::HandleRestart()
{
    SetInputMode(FInputModeGameOnly());
    SetShowMouseCursor(false);

    UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()));
}

void AMyPlayerController::HandleStart()
{
    //SetPause(false);

    UE_LOG(LogTemp, Warning, TEXT("StartWidget"));
    SetInputMode(FInputModeGameOnly());
    SetShowMouseCursor(false);
    StartWidget->RemoveFromParent();
    //UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()));

}


