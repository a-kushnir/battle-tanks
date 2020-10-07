// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleCity.h"
#include "Functions.h"

FString UFunctions::GetProjectVersion() {
	FString ProjectVersion;
	GConfig->GetString(
		TEXT("/Script/EngineSettings.GeneralProjectSettings"),
		TEXT("ProjectVersion"),
		ProjectVersion,
		GGameIni
	);
	return ProjectVersion;
}

void UFunctions::DisableSplitScreen(AActor* Context, bool Disable)
{
	if (Context) {
		Context->GetWorld()->GetGameViewport()->SetDisableSplitscreenOverride(Disable);
	}
}

FString UFunctions::GetConfigString(FString Section, FString Key)
{
	FString Result;
	GConfig->GetString(*Section, *Key, Result, GGameUserSettingsIni);
	return Result;
}

void UFunctions::SetConfigString(FString Section, FString Key, FString Value)
{
	GConfig->SetString(*Section, *Key, *Value, GGameUserSettingsIni);
}

void UFunctions::FlushConfig()
{
	GConfig->Flush(false, GGameUserSettingsIni);
}


TArray<FString> UFunctions::GetLanguages()
{
	TArray<FString> Result;

	TArray<FCultureRef> Cultures;
	FInternationalization::Get().GetCulturesWithAvailableLocalization(FPaths::GetGameLocalizationPaths(), Cultures, false);

	int numCultures = Cultures.Num();
	for (int i = 0; i < numCultures; i++) {
		Result.Add(Cultures[i].Get().GetName());
	}

	return Result;
}


FString UFunctions::GetLanguageDisplayName(FString Name)
{
	FString Result;

	TArray<FCultureRef> Cultures;
	FInternationalization::Get().GetCulturesWithAvailableLocalization(FPaths::GetGameLocalizationPaths(), Cultures, false);

	int numCultures = Cultures.Num();
	for (int i = 0; i < numCultures; i++)
		if (!Cultures[i].Get().GetName().Compare(Name))
			Result = Cultures[i].Get().GetEnglishName();

	return Result;
}

FString UFunctions::GetCurrentLanguage()
{
	return FInternationalization::Get().GetCurrentCulture().Get().GetName();
}

bool UFunctions::SetCurrentLanguage(const FString Name)
{
	TArray<FCultureRef> Cultures;
	FInternationalization::Get().GetCulturesWithAvailableLocalization(FPaths::GetGameLocalizationPaths(), Cultures, false);

	int numCultures = Cultures.Num();
	for (int i = 0; i < numCultures; ++i)
	{
		if (!Cultures[i].Get().GetName().Compare(Name))
		{
			FInternationalization::Get().SetCurrentCulture(Name);
			return true;
		}
	}

	return false;
}


float UFunctions::GetSoundClassVolume(USoundClass* TargetSoundClass)
{
	return TargetSoundClass ? TargetSoundClass->Properties.Volume : 0.0f;
}

void UFunctions::SetSoundClassVolume(USoundClass* TargetSoundClass, float NewVolume)
{
	if (TargetSoundClass)
		TargetSoundClass->Properties.Volume = NewVolume;
}