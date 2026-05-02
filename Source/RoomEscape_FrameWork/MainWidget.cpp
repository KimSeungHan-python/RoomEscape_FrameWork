// Fill out your copyright notice in the Description page of Project Settings.


#include "MainWidget.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"

void UMainWidget::UpdateHP(float CurrentHP, float MaxHP)
{
	if (HPBar)
	{
		// 프로그레스 바는 0.0 ~ 1.0 사이의 비율을 사용합니다.
		float HealthRatio = (MaxHP > 0.0f) ? (CurrentHP / MaxHP) : 0.0f;
		HPBar->SetPercent(HealthRatio);
	}
}

void UMainWidget::UpdateAmmo(int32 CurrentAmmo, int32 MaxAmmo)
{
	if (AmmoText)//알아서 처리해주는데 
	{
		// "30 / 120" 형태로 텍스트를 만들어 적용합니다.
		FString AmmoString = FString::Printf(TEXT("%d / %d"), CurrentAmmo, MaxAmmo);//나쁘지 않음 
		AmmoText->SetText(FText::FromString(AmmoString));
	}
}

void UMainWidget::UpdateGunImage(UTexture2D* NewGunTexture) // 총 바뀔때불러주면 될듯
{
	if (GunImage && NewGunTexture)
	{
		GunImage->SetBrushFromTexture(NewGunTexture);
	}
}