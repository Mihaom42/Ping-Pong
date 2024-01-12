// Copyright Epic Games, Inc. All Rights Reserved.


#include "Core/PongGameState.h"

#include "Core/PongGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Net/UnrealNetwork.h"

void APongGameState::IncrementScore_Implementation(int PlayerNumber)
{
	if (PlayerNumber == 1)
	{
		PlayerOneScore++;
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("PlayerOneScore: %i"), PlayerOneScore));
	}
	else if (PlayerNumber == 2)
	{
		PlayerTwoScore++;
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("PlayerTwoScore: %i"), PlayerTwoScore));
	}

	if (PlayerOneScore == ScoreToWin || PlayerTwoScore == ScoreToWin)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, FString::Printf(TEXT("End")));
		AGameModeBase* GameMode = UGameplayStatics::GetGameMode(this);
		if (GameMode)
		{
			APongGameMode* PongGameMode = Cast<APongGameMode>(GameMode);
			if (PongGameMode)
			{
				bGameover = true;
				PongGameMode->EndGame();
			}
		}
	}
}

void APongGameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(APongGameState, PlayerOneScore)
	DOREPLIFETIME(APongGameState, PlayerTwoScore)
	DOREPLIFETIME(APongGameState, bGameover)
}
