

#include "GoldenOculus.h"
#include "GrateActor.h"


AGrateActor::AGrateActor(const class FPostConstructInitializeProperties& PCIP)
: Super(PCIP), GridWidth(100.0f), GridLength(100.0f)
{
	// load unit to be tiled
	static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMeshObj(TEXT("StaticMesh'/Game/Meshes/grate.grate'"));
	if (StaticMeshObj.Object)
		GrateUnit = StaticMeshObj.Object;

	// create mesh component for tiling
	GrateComponent = PCIP.CreateDefaultSubobject<UInstancedStaticMeshComponent>(this, TEXT("GrateComponent"));
	if (GrateComponent != NULL)
	{
		GrateComponent->AttachTo(RootComponent);
		GrateComponent->SetStaticMesh(GrateUnit);

		generateInstances();
	}
}


void AGrateActor::generateInstances()
{
	// tile across
	if (GEngine){
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, FString::Printf(TEXT("X: %f, Y: %f"),
			GrateComponent->Bounds.BoxExtent.X, GrateComponent->Bounds.BoxExtent.Y));
	}
	float unitWidth = 4.0f;
	float unitLength = 10.0f;

	for (int down = 0; down*unitLength < GridLength; down++){
		for (int across = 0; across*unitWidth < GridWidth; across++){
			GrateComponent->AddInstance(FTransform(FVector(across*unitWidth, down*unitLength, 0.0f)));
		}
	}

	if (GEngine){
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, FString::Printf(TEXT("X: %f, Y: %f"),
			GrateComponent->Bounds.BoxExtent.X, GrateComponent->Bounds.BoxExtent.Y));
	}
}

void AGrateActor::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	generateInstances();
}