#pragma once

#include "TankType.h"
#include "TankData.generated.h"

USTRUCT(BlueprintType, Blueprintable)
struct FTankData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ETankType Type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Bonus;

	FTankData()
	{
		Type = ETankType::Basic;
		Bonus = false;
	}
};
