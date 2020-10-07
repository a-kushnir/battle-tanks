#pragma once

UENUM(BlueprintType)
enum class ETankType : uint8
{
	Basic 	UMETA(DisplayName = "Basic"),
	Fast 	UMETA(DisplayName = "Fast"),
	Power	UMETA(DisplayName = "Power"),
	Armor	UMETA(DisplayName = "Armor"),
	Random	UMETA(DisplayName = "Random"),
	RandomB UMETA(DisplayName = "RandomB")
};
