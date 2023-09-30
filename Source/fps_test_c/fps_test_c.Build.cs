// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class fps_test_c : ModuleRules
{
	public fps_test_c(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput" });
	}
}
