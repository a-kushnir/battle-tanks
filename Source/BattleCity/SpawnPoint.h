#pragma once

#include "SpawnPoint.generated.h"

USTRUCT(BlueprintType, Blueprintable)
struct FSpawnPoint
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector2D Location;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Rotation;

	FSpawnPoint()
	{
		Location = FVector2D(0, 0);
		Rotation = 0;
	}
};
