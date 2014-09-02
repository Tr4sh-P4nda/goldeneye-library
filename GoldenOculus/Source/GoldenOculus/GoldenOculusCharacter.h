

#pragma once

#include "GameFramework/Character.h"
#include "GoldenOculusCharacter.generated.h"

/**
 * 
 */
UCLASS()
class AGoldenOculusCharacter : public ACharacter
{
	GENERATED_UCLASS_BODY()

	virtual void BeginPlay() override;
	
protected:
	virtual void SetupPlayerInputComponent(class UInputComponent* ic) override;
	UFUNCTION()
		void MoveForward(float val);
	UFUNCTION()
		void MoveRight(float val);

public:
	UFUNCTION()
		void OnStartJump();
	UFUNCTION()
		void OnStopJump();

	UFUNCTION()
		void OnStartSprint();
	UFUNCTION()
		void OnStopSprint();
	UPROPERTY()
		float fSprintMultiplier;
};
