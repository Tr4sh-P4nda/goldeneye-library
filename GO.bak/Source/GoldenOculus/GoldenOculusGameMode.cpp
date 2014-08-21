

#include "GoldenOculus.h"
#include "GoldenOculusGameMode.h"

AGoldenOculusGameMode::AGoldenOculusGameMode(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	// set the default pawn
	static ConstructorHelpers::FObjectFinder<UBlueprint> PlayerPawnObject(TEXT("Blueprint'/Game/Blueprints/PlayerBP.PlayerBP'"));
	if (PlayerPawnObject.Object != NULL)
		DefaultPawnClass = (UClass*)PlayerPawnObject.Object->GeneratedClass;
}

void AGoldenOculusGameMode::BeginPlay()
{
	Super::BeginPlay();

	if(GEngine){
		GEngine->AddOnScreenDebugMessage(-1,5.f, FColor::Yellow, TEXT("HELLO WORLD"));
	}
}
