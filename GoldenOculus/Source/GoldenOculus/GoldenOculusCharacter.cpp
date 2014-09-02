

#include "GoldenOculus.h"
#include "GoldenOculusCharacter.h"


AGoldenOculusCharacter::AGoldenOculusCharacter(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	// initialize movement speeds
	CharacterMovement->MaxWalkSpeed = 450.f;
	fSprintMultiplier = 2.0f;
}

void AGoldenOculusCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (GEngine){
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("We are using GoldenOculusCharacter"));
	}
}

void AGoldenOculusCharacter::SetupPlayerInputComponent(UInputComponent* ic)
{
	// set up key bindings

	// movement
	ic->BindAxis("MoveForward", this, &AGoldenOculusCharacter::MoveForward);
	ic->BindAxis("MoveRight", this, &AGoldenOculusCharacter::MoveRight);
	ic->BindAxis("Turn", this, &AGoldenOculusCharacter::AddControllerYawInput);
	ic->BindAxis("LookUp", this, &AGoldenOculusCharacter::AddControllerPitchInput);

	// sprint
	ic->BindAction("EnableSprint", IE_Pressed, this, &AGoldenOculusCharacter::OnStartSprint);
	ic->BindAction("EnableSprint", IE_Released, this, &AGoldenOculusCharacter::OnStopSprint);

	// jump
	ic->BindAction("Jump", IE_Pressed, this, &AGoldenOculusCharacter::OnStartJump);
	ic->BindAction("Jump", IE_Released, this, &AGoldenOculusCharacter::OnStopJump);
}


void AGoldenOculusCharacter::MoveForward(float val)
{
	if (Controller != NULL && val != 0.0f)
	{
		// get forward direction
		FRotator rotation = Controller->GetControlRotation();

		// limit pitch when walking or falling
		if (CharacterMovement->IsMovingOnGround() || CharacterMovement->IsFalling()){
			rotation.Pitch = 0.0f;
		}

		// add movement in that direction
		const FVector direction = FRotationMatrix(rotation).GetScaledAxis(EAxis::X);
		AddMovementInput(direction, val);
	}
}

void AGoldenOculusCharacter::MoveRight(float val)
{
	if (Controller != NULL && val != 0.0f)
	{
		// get forward direction
		FRotator rotation = Controller->GetControlRotation();

		// add movement in that direction
		const FVector direction = FRotationMatrix(rotation).GetScaledAxis(EAxis::Y);
		AddMovementInput(direction, val);
	}
}


void AGoldenOculusCharacter::OnStartJump()
{
	bPressedJump = true;
}

void AGoldenOculusCharacter::OnStopJump()
{
	bPressedJump = false;
}


void AGoldenOculusCharacter::OnStartSprint()
{
	CharacterMovement->MaxWalkSpeed *= fSprintMultiplier;
}

void AGoldenOculusCharacter::OnStopSprint()
{
	CharacterMovement->MaxWalkSpeed /= fSprintMultiplier;
}