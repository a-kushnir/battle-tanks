#pragma once

#include "TankData.h"
#include "TankDataGroup.generated.h"

USTRUCT(BlueprintType, Blueprintable)
struct FTankDataGroup
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FTankData Data;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Count;

	FTankDataGroup()
	{
		Data = FTankData();
		Count = 0;
	}
};
