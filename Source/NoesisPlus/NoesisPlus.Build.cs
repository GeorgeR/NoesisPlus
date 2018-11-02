using UnrealBuildTool;

public class NoesisPlus : ModuleRules
{
	public NoesisPlus(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

	    if (Target.Version.MinorVersion <= 19)
	    {
            PublicIncludePaths.AddRange(
			    new string[] {
				    "NoesisPlus/Public"
			    });

		    PrivateIncludePaths.AddRange(
			    new string[] {
				    "NoesisPlus/Private",
			    });
        }

		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",

			    "Noesis",
                "NoesisRuntime"
			});
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
			});
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{

			});
	}
}
