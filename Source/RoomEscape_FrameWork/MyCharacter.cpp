// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include "MyGameModeBase.h"
#include "Components/CapsuleComponent.h" 
#include "TimerManager.h" 
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/SkeletalMeshComponent.h"




// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AMyCharacter::Die()
{
    UE_LOG(LogTemp, Warning, TEXT("Character Die: Start Ragdoll"));

    // [1] 입력 및 움직임 즉시 차단
    if (Controller)
    {
        Controller->UnPossess(); // 컨트롤러 분리 (입력 차단)
    }
    GetCharacterMovement()->DisableMovement();
    GetCharacterMovement()->StopMovementImmediately();

    // [2] 캡슐 컴포넌트 충돌 비활성화 (시체가 바닥에 묻히지 않게 하기 위해)
    // 래그돌이 바닥을 뚫고 내려가는 것을 방지하기 위해 캡슐 충돌을 끄고 메쉬 충돌만 남깁니다.
    GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);

    // [3] 스켈레탈 메쉬 래그돌(물리 시뮬레이션) 활성화
    if (GetMesh())
    {
        // 메쉬의 모든 뼈(Body)에 대해 물리 시뮬레이션을 켭니다. 이것이 '시뮬레이터' 활용입니다.
        GetMesh()->SetSimulatePhysics(true);
        GetMesh()->SetCollisionProfileName(TEXT("Ragdoll")); // 래그돌 충돌 프리필 설정

        // 시체가 카메라 앞에서 너무 역동적으로 튀지 않게 약간의 저항을 줍니다.
        GetMesh()->SetLinearDamping(0.5f);
        GetMesh()->SetAngularDamping(0.5f);
    }

    // [4] 일정 시간 후 사라지게 만드는 타이머 설정 (예: 3초 후)
    float DisappearDelay = 3.0f; // 3초 뒤 사라짐
    GetWorld()->GetTimerManager().SetTimer(DeathTimerHandle, this, &AMyCharacter::FinishDeath, DisappearDelay, false);
}

void AMyCharacter::FinishDeath()
{
    UE_LOG(LogTemp, Warning, TEXT("Character Die: Disappear and Game Over"));

    // [5] Game Over 호출 (원래 의도하신 부분)
    AMyGameModeBase* GM = Cast<AMyGameModeBase>(GetWorld()->GetAuthGameMode());
    if (GM)
    {
        GM->GameOver();
    }

    // [6] 최종적으로 캐릭터 월드에서 삭제
    Destroy();
}

