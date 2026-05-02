// Fill out your copyright notice in the Description page of Project Settings.


#include "PauseWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "MyGameInstance.h"

void UPauseWidget::OnReGameClicked()
{
    if (UMyGameInstance* GI = GetGameInstance<UMyGameInstance>())
    {
        GI->StartMode = EStartMode::RestartSame;
    }

    DOnReGameClicked.Broadcast();

    UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()));
}

void UPauseWidget::OnQuitClicked()
{
    UKismetSystemLibrary::QuitGame(this, GetWorld()->GetFirstPlayerController(), EQuitPreference::Quit, true);

}

void UPauseWidget::OnNewGameClicked()
{
    if (UMyGameInstance* GI = GetGameInstance<UMyGameInstance>())
    {
        GI->StartMode = EStartMode::RestartNew;
    }
    DOnNewGameClicked.Broadcast();
    UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()));
}

void UPauseWidget::OnResumeClicked()
{
    RemoveFromParent();

    if (APlayerController* PC = GetWorld()->GetFirstPlayerController())
    {
        PC->SetPause(false);
        PC->SetInputMode(FInputModeGameOnly());
        PC->bShowMouseCursor = false;
    }
}

