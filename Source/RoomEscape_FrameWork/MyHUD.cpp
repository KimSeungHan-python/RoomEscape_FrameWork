// Fill out your copyright notice in the Description page of Project Settings.


#include "MyHUD.h"
#include "MainWidget.h"

void AMyHUD::BeginPlay()
{
	Super::BeginPlay();

	// 에디터에서 MainHUDWidgetClass를 잘 지정했다면 위젯을 생성합니다.
	if (MainWidgetClass)
	{
		MainWidget = CreateWidget<UMainWidget>(GetWorld(), MainWidgetClass);

		if (MainWidget)
		{
			// 생성된 위젯을 플레이어의 화면에 띄웁니다.
			MainWidget->AddToViewport();
		}
	}
}
