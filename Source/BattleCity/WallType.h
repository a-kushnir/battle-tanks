#pragma once

UENUM(BlueprintType)
enum class EWallType : uint8
{
	Brick 	UMETA(DisplayName = "Brick"),
	Stone 	UMETA(DisplayName = "Stone"),
	Tree	UMETA(DisplayName = "Tree"),
	Water	UMETA(DisplayName = "Water"),
	Ice		UMETA(DisplayName = "Ice"),
	Sand	UMETA(DisplayName = "Sand")
};
