#pragma once

#include "WallData.h"
#include "SpawnPoint.h"
#include "TankDataGroup.h"
#include "LevelData.generated.h"

USTRUCT(BlueprintType, Blueprintable)
struct FLevelData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector2D Size;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FSpawnPoint> Players;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FSpawnPoint> Enemies;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector2D Base;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FWallData> Walls;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FTankDataGroup> TankGroups;

	FLevelData() {}
};
