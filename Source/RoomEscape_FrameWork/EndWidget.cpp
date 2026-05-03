// Fill out your copyright notice in the Description page of Project Settings.


#include "EndWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "MyGameInstance.h"

//UEndWidget::UEndWidget()
//{
//
//}

//void UEndWidget::NativeConstruct()
//{
//
//}

void UEndWidget::OnReGameClicked()
{
    if (UMyGameInstance* GI = GetGameInstance<UMyGameInstance>())
    {
        GI->StartMode = EStartMode::RestartSame;
    }
    DOnReGameClicked.Broadcast();

    //UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()));
}

void UEndWidget::OnNewGameClicked()
{
    if (UMyGameInstance* GI = GetGameInstance<UMyGameInstance>())
    {
        GI->StartMode = EStartMode::RestartNew;
    }
    DOnNewGameClicked.Broadcast();
    //UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()));
}

void UEndWidget::OnQuitClicked()
{
	UKismetSystemLibrary::QuitGame(this, GetWorld()->GetFirstPlayerController(), EQuitPreference::Quit, true);
}
