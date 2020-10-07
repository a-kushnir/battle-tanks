// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "Functions.generated.h"

/**
 * 
 */
UCLASS()
class BATTLECITY_API UFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Configuration")
	static FString GetProjectVersion();

	UFUNCTION(BlueprintCallable, Category = "Viewport")
	static void DisableSplitScreen(AActor* Context, bool Disable);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Configuration")
	static FString GetConfigString(FString Section, FString Key);

	UFUNCTION(BlueprintCallable, Category = "Configuration")
	static void SetConfigString(FString Section, FString Key, FString Value);

	UFUNCTION(BlueprintCallable, Category = "Configuration")
	static void FlushConfig();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Localization")
	static TArray<FString> GetLanguages();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Localization")
	static FString GetLanguageDisplayName(FString Name);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Localization")
	static FString GetCurrentLanguage();

	UFUNCTION(BlueprintCallable, Category = "Localization")
	static bool SetCurrentLanguage(const FString Name);

	UFUNCTION(BlueprintCallable, Category = "Sound")
	static float GetSoundClassVolume(USoundClass* TargetSoundClass);

	UFUNCTION(BlueprintCallable, Category = "Sound")
	static void SetSoundClassVolume(USoundClass* TargetSoundClass, float NewVolume);
};
