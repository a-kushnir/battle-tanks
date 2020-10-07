#pragma once

#include "LevelData.h"
#include "LevelFile.generated.h"

UCLASS()
class BATTLECITY_API ULevelFile : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Level Packages")
	static bool SaveLevelData(const FString PackageName, int32 LevelNumber, const FLevelData Data, bool PrettyPrint = false);

	UFUNCTION(BlueprintCallable, Category = "Level Packages")
	static bool LoadLevelData(const FString PackageName, int32 LevelNumber, FLevelData& Data);

	UFUNCTION(BlueprintCallable, Category = "Level Packages")
	static bool LevelExists(const FString PackageName, int32 LevelNumber);

	UFUNCTION(BlueprintCallable, Category = "Level Packages")
	static TArray<FString> FindLevelPackages(const bool UserLevelsOnly, const bool IncludeBlank);

	UFUNCTION(BlueprintCallable, Category = "Level Packages")
	static bool CreateLevelPackage(const FString PackageName);

	UFUNCTION(BlueprintCallable, Category = "Level Packages")
	static bool DeleteLevelPackage(const FString PackageName);

	UFUNCTION(BlueprintCallable, Category = "Level Packages")
	static bool LevelPackageExists(const FString PackageName);

	UFUNCTION(BlueprintCallable, Category = "Level Packages")
	static TArray<int32> FindLevels(const FString PackageName, const bool UserLevelsOnly);

	UFUNCTION(BlueprintCallable, Category = "Level Packages")
	static bool DeleteLevel(const FString PackageName, int32 LevelName);

private:
	static FString GetPath(bool UserDir);
	static FString GetPath(bool UserDir, const FString PackageName);
	static FString GetPath(bool UserDir, const FString PackageName, int32 LevelNumber);

	static bool HasLevels(const FString PackageName, const bool UserLevelsOnly);
};
