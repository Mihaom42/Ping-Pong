// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/Character.h"
#include "PongPlayer.generated.h"

class UBoxComponent;
class UCapsuleComponent;
class UFloatingPawnMovement;
class UCameraComponent;

UCLASS()
class UNREALPONG_API APongPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APongPlayer();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UStaticMeshComponent* GetStaticMeshComponent() const { return StaticMeshComponent; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "PongPlayer|Components")
	UStaticMeshComponent* StaticMeshComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "PongPlayer|Components")
	UBoxComponent* BoxComponent;
};
