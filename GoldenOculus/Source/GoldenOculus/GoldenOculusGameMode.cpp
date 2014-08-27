

#include "GoldenOculus.h"
#include "GoldenOculusGameMode.h"
#include "GoldenOculusPlayerController.h"

AGoldenOculusGameMode::AGoldenOculusGameMode(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	PlayerControllerClass = AGoldenOculusPlayerController::StaticClass();
}


