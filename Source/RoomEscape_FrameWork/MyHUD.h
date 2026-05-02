// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MyHUD.generated.h"

class UMainWidget;
/**
 * 
 */
UCLASS()
class ROOMESCAPE_FRAMEWORK_API AMyHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	// 블루프린트에서 우리가 디자인한 위젯을 지정할 수 있도록 열어둡니다.
	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<UMainWidget> MainWidgetClass;

	// 화면에 띄워진 위젯을 저장해 둘 포인터 (나중에 캐릭터가 이 위젯에 접근할 때 씁니다)
	UPROPERTY()
	UMainWidget* MainWidget;

protected:
	virtual void BeginPlay() override;



};
