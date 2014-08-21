

#pragma once

#include "GameFramework/Actor.h"
#include "GrateActor.generated.h"

/**
 * 
 */
UCLASS()
class GOLDENOCULUS_API AGrateActor : public AStaticMeshActor
{
	GENERATED_UCLASS_BODY()

	UPROPERTY()
		UStaticMesh* GrateUnit;

	UPROPERTY()
		TSubobjectPtr<UInstancedStaticMeshComponent> GrateComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = General)
		float GridWidth;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = General)
		float GridLength;

	UFUNCTION()
		void generateInstances();

	void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
};
