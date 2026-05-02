// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Engine/EngineTypes.h"
#include "MyCharacter.generated.h"

UCLASS()
class ROOMESCAPE_FRAMEWORK_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()


public:

	// 블루프린트에서 호출만 가능하도록 설정
	UFUNCTION(BlueprintCallable, Category = "Character|Status")
	void Die();

	//UFUNCTION(BlueprintNativeEvent)
	//void Die();
	//virtual void Die_Implementation();

protected:

	AMyCharacter();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/** 쓰러진 후 일정 시간 뒤에 실제로 캐릭터를 파괴하는 함수 */
	void FinishDeath();

private:
	/** 타이머 정보를 저장할 핸들 */
	FTimerHandle DeathTimerHandle;
};
