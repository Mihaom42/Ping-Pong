// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PongController.generated.h"

class UPongGameInstance;
/**
 * UnrealPong PlayerController
 */
UCLASS()
class UNREALPONG_API APongController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

	virtual void SetupInputComponent() override;

	virtual void OnPossess(APawn* InPawn) override;

private:
	void Move(float Amount);
};
