#include "BattleCity.h"
#include "LevelFile.h"

#include "Runtime/JsonUtilities/Public/JsonObjectConverter.h"
#include "Runtime/Core/Public/HAL/FileManagerGeneric.h"

bool ULevelFile::SaveLevelData(const FString PackageName, int32 LevelNumber, const FLevelData Data, bool PrettyPrint)
{
	FString fileContent;
	return FJsonObjectConverter::UStructToJsonObjectString(FLevelData::StaticStruct(), &Data, fileContent, 0, 0, 0, NULL, PrettyPrint) &&
		FFileHelper::SaveStringToFile(fileContent, *GetPath(true, PackageName, LevelNumber));
}

bool ULevelFile::LoadLevelData(const FString PackageName, int32 LevelNumber, FLevelData& Data)
{
	FString fileContent;
	return (FFileHelper::LoadFileToString(fileContent, *GetPath(true, PackageName, LevelNumber)) ||
			FFileHelper::LoadFileToString(fileContent, *GetPath(false, PackageName, LevelNumber))) && 
		FJsonObjectConverter::JsonObjectStringToUStruct<FLevelData>(fileContent, &Data, 0, 0);
}

bool ULevelFile::LevelExists(const FString PackageName, int32 LevelNumber)
{
	FFileManagerGeneric FileMgr;
	return FileMgr.FileExists(*GetPath(true, PackageName, LevelNumber)) || 
		   FileMgr.FileExists(*GetPath(false, PackageName, LevelNumber));
}

TArray<FString> ULevelFile::FindLevelPackages(const bool UserLevelsOnly, const bool IncludeBlank)
{
	FFileManagerGeneric FileMgr;
	TArray<FString> FileNames;
	TArray<FString> UniqueFileNames;

	FileMgr.FindFiles(FileNames, *FPaths::Combine(*GetPath(true), TEXT("*")), false, true);
	for (FString fileName : FileNames)
		UniqueFileNames.AddUnique(fileName);

	if (!UserLevelsOnly) {
		FileMgr.FindFiles(FileNames, *FPaths::Combine(*GetPath(false), TEXT("*")), false, true);
		for (FString fileName : FileNames)
			UniqueFileNames.AddUnique(fileName);
	}

	TArray<FString> Result;
	for (FString fileName : UniqueFileNames)
		if (IncludeBlank || HasLevels(fileName, UserLevelsOnly))
			Result.Add(fileName);

	Result.Sort();
	return Result;
};

bool ULevelFile::CreateLevelPackage(const FString PackageName)
{
	FFileManagerGeneric FileMgr;
	return FileMgr.MakeDirectory(*GetPath(true, PackageName), true);
};

bool ULevelFile::DeleteLevelPackage(const FString PackageName)
{
	FFileManagerGeneric FileMgr;
	return FileMgr.DeleteDirectory(*GetPath(true, PackageName), false, true);
};

bool ULevelFile::LevelPackageExists(const FString PackageName)
{
	FFileManagerGeneric FileMgr;
	return FileMgr.DirectoryExists(*GetPath(true, PackageName)) || 
		   FileMgr.DirectoryExists(*GetPath(false, PackageName));
};

TArray<int32> ULevelFile::FindLevels(const FString PackageName, const bool UserLevelsOnly)
{
	FFileManagerGeneric FileMgr;
	TArray<FString> FileNames;
	TArray<int32> LevelNumbers;

	FileMgr.FindFiles(FileNames, *FPaths::Combine(*GetPath(true, PackageName), TEXT("*.lvl")), true, false);
	for (int i = 0; i < FileNames.Num(); i++) {
		FileNames[i].RemoveFromEnd(TEXT(".lvl"));
		if (FileNames[i].IsNumeric()) {
			int32 LevelNumber = FCString::Atoi(*FileNames[i]);
			if (LevelExists(PackageName, LevelNumber)) {
				LevelNumbers.AddUnique(LevelNumber);
			}
		}
	}

	if (!UserLevelsOnly) {
		FileMgr.FindFiles(FileNames, *FPaths::Combine(*GetPath(false, PackageName), TEXT("*.lvl")), true, false);
		for (int i = 0; i < FileNames.Num(); i++) {
			FileNames[i].RemoveFromEnd(TEXT(".lvl"));
			if (FileNames[i].IsNumeric()) {
				int32 LevelNumber = FCString::Atoi(*FileNames[i]);
				if (LevelExists(PackageName, LevelNumber)) {
					LevelNumbers.AddUnique(LevelNumber);
				}
			}
		}
	}

	LevelNumbers.Sort();
	return LevelNumbers;
};

bool ULevelFile::HasLevels(const FString PackageName, const bool UserLevelsOnly)
{
	return FindLevels(PackageName, UserLevelsOnly).Num() > 0;
}

bool ULevelFile::DeleteLevel(const FString PackageName, int32 LevelName)
{
	FFileManagerGeneric FileMgr;
	return FileMgr.Delete(*GetPath(true, PackageName, LevelName), false);
};

FString ULevelFile::GetPath(bool UserDir)
{
	return FPaths::Combine(UserDir ? *FPaths::GameUserDir() : *FPaths::GameContentDir(), TEXT("Maps"));
}

FString ULevelFile::GetPath(bool UserDir, const FString PackageName)
{
	return FPaths::Combine(*GetPath(UserDir), *PackageName);
}

FString ULevelFile::GetPath(bool UserDir, const FString PackageName, int32 LevelNumber)
{
	const FString LevelName = FString::Printf(TEXT("%03d.lvl"), LevelNumber);
	return FPaths::Combine(*GetPath(UserDir, PackageName), *LevelName);
}