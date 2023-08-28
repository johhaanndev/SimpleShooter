// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterAIController.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "ShooterCharacter.h"

void AShooterAIController::BeginPlay()
{
	Super::BeginPlay();
	if (AIBehavior != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIBehavior FOUND"));
		RunBehaviorTree(AIBehavior);

		GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"), GetPawn()->GetActorLocation());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIBehavior not found"));
	}
}

void AShooterAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

bool AShooterAIController::IsDead() const
{
	AShooterCharacter* ControllerCharacter = Cast<AShooterCharacter>(GetPawn());
	if (ControllerCharacter != nullptr)
	{
		return ControllerCharacter->IsDead();
	}

	return true;
}
