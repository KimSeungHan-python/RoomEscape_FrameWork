// Fill out your copyright notice in the Description page of Project Settings.


#include "PauseWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "MyGameInstance.h"
#include "Components/Slider.h"
#include "EngineUtils.h" // TActorIterator를 사용하기 위해 필요
#include "Engine/DirectionalLight.h"
#include "Components/LightComponent.h"

void UPauseWidget::NativeConstruct()
{
    Super::NativeConstruct();

    // 슬라이더가 정상적으로 바인딩 되었다면, 값이 변할 때 OnBrightnessChanged 함수를 실행하도록 연결
    if (BrightnessSlider)
    {
        BrightnessSlider->OnValueChanged.AddDynamic(this, &UPauseWidget::OnBrightnessChanged);

        // 초기 슬라이더 값을 0.5(중간) 정도로 설정
        BrightnessSlider->SetValue(0.1f);
    }
}

void UPauseWidget::OnBrightnessChanged(float Value)
{
    // 슬라이더의 Value는 0.0 ~ 1.0 사이의 값입니다.
    // 이 값을 실제 라이트의 밝기(Intensity) 수치로 변환합니다. (예: 0 ~ 10 조도)
    float NewIntensity = Value * 10.0f; // 최대 밝기를 10으로 가정

    // 현재 맵(World)에 있는 모든 Directional Light를 찾아서 밝기를 조절합니다.
    if (UWorld* World = GetWorld())
    {
        for (TActorIterator<ADirectionalLight> It(World); It; ++It)
        {
            ADirectionalLight* SunLight = *It;
            if (SunLight && SunLight->GetLightComponent())
            {
                SunLight->GetLightComponent()->SetIntensity(NewIntensity);
            }
        }
    }
}


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

