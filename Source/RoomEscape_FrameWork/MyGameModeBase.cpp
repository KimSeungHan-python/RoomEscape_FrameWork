// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
#include "MyPlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "MyGameInstance.h"
#include "DungeonGenerator.h"
#include "Kismet/KismetSystemLibrary.h"

AMyGameModeBase::AMyGameModeBase()
{

}

void AMyGameModeBase::BeginPlay()
{

    Super::BeginPlay();
    if (UMyGameInstance* GI = GetGameInstance<UMyGameInstance>())
    {
        if (GI->StartMode == EStartMode::MainMenu)
        {
            GameStart(); // UI 띄우기
        }
            //Seed = GI->SavedSeed;//이전 값 기억
            //GameReStart();//굳이 보여줄 필요 없이 그냥 스타트하면 됨 <- 아무것도 안하면 됨

            //Seed = -1; // 랜덤
            //GameRestart();

    }
}

void AMyGameModeBase::GameOver()
{
    AMyPlayerController* PC = Cast<AMyPlayerController>(UGameplayStatics::GetPlayerController(this, 0));//이것도 멤버 변수로 만들기 후에 수정
    if (PC)
    {
        PC->ShowGameOverUI();
    }
}

//void AMyGameModeBase::GamePause()
//{
//    AMyPlayerController* PC = Cast<AMyPlayerController>(UGameplayStatics::GetPlayerController(this, 0));
//    if (PC)
//    {
//        PC->ShowGameClearUI();
//    }
//}

void AMyGameModeBase::GameStart()
{
    AMyPlayerController* PC = Cast<AMyPlayerController>(UGameplayStatics::GetPlayerController(this, 0));
    if (PC)
    {
        PC->ShowGameStartUI();
    }
}

//void AMyGameModeBase::ReStart()
//{
//    UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()));
//}

