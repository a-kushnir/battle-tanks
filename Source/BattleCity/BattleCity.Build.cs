// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class BattleCity : ModuleRules
{
	public BattleCity(TargetInfo Target)
	{
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });
        PublicDependencyModuleNames.AddRange(new string[] { "Json", "JsonUtilities", "RHI" });

        PrivateDependencyModuleNames.AddRange(new string[] {  });

        // Uncomment if you are using Slate UI
        // PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

        PublicDependencyModuleNames.AddRange(new string[] { "OnlineSubsystem", "OnlineSubsystemUtils" });
        PrivateDependencyModuleNames.AddRange(new string[] { "OnlineSubsystem" });
        DynamicallyLoadedModuleNames.Add("OnlineSubsystemSteam");
	}
}
