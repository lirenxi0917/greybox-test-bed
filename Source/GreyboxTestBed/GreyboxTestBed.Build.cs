// GreyboxTestBed.Build.cs
// Unreal Engine 5 module definition for the greybox movement test bed.

using UnrealBuildTool;

public class GreyboxTestBed : ModuleRules
{
	public GreyboxTestBed(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"GameFramework",
			"NavigationSystem"
		});

		PrivateDependencyModuleNames.AddRange(new string[]
		{
			"Slate",
			"SlateCore"
		});
	}
}
