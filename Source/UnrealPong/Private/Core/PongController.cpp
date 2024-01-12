// Copyright Epic Games, Inc. All Rights Reserved.


#include "Core/PongController.h"

#include "Camera/CameraActor.h"
#include "Core/PongPlayer.h"
#include "Kismet/GameplayStatics.h"

void APongController::BeginPlay()
{
	Super::BeginPlay();
}

void APongController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void APongController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAxis("MoveUp", this, &APongController::Move);
}

void APongController::Move(float Amount)
{
	APongPlayer* ControlledPawn = Cast<APongPlayer>(GetPawn());
	if (Amount != 0.f)
	{
		ControlledPawn->AddMovementInput(FVector(1, 0, 0), Amount, true);
	}
}

void APongController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	// setup camera
	TArray<AActor*> CameraArray;
	UGameplayStatics::GetAllActorsOfClass(this, ACameraActor::StaticClass(), CameraArray);
	if (CameraArray.Num() > 0)
	{
		SetViewTargetWithBlend(CameraArray[0]);
	}
}
