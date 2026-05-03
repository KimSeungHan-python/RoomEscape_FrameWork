// Fill out your copyright notice in the Description page of Project Settings.


#include "StartWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "MyGameInstance.h"

void UStartWidget::OnGameStartClicked()
{
	if (UMyGameInstance* GI = GetGameInstance<UMyGameInstance>())
	{
		GI->StartMode = EStartMode::RestartNew;
	}
	DOnStartGameClicked.Broadcast();
	//RemoveFromParent();//Widget제거하고 
	//UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()));
}

void UStartWidget::OnQuitClicked()
{
	UKismetSystemLibrary::QuitGame(this, GetWorld()->GetFirstPlayerController(), EQuitPreference::Quit, true);
}
