#pragma once

#include "WallType.h"
#include "WallData.generated.h"

USTRUCT(BlueprintType, Blueprintable)
struct FWallData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector2D Location;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EWallType Type;

	FWallData(FVector2D location, EWallType type)
	{ 
		Location = location;
		Type = type;
	}

	FWallData() {
		Location = FVector2D(0, 0);
		Type = EWallType::Brick;
	}
};
