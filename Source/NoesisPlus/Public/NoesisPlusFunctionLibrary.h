#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "NoesisPlusFunctionLibrary.generated.h"

NOESISPLUS_API void NoesisNotifyPropertiesChanged(class UObject*, TArray<FName>&);
NOESISPLUS_API void NoesisNotifyNonInheritedPropertiesChanged(class UObject*);
NOESISPLUS_API void NoesisNotifyNonInheritedPropertiesChangedExcept(class UObject*, TArray<FName>&);

UCLASS()
class NOESISPLUS_API UNoesisPlusFunctionLibrary 
	: public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "NoesisPlus", meta = (HidePin = "Target"))
	static void NotifyPropertiesChanged(UObject* Owner, TArray<FName>& PropertyNames);

	/* PropertyNames should be a comma seperated list */
	UFUNCTION(BlueprintCallable, Category = "NoesisPlus", meta = (HidePin = "Target", DisplayName = "NotifyPropertiesChanged"))
	static void NotifyPropertiesChanged_CSV(UObject* Owner, FName PropertyNames);

	UFUNCTION(BlueprintCallable, Category = "NoesisPlus", meta = (HidePin = "Target"))
	static void NotifyNonInheritedPropertiesChanged(UObject* Owner);

	UFUNCTION(BlueprintCallable, Category = "NoesisPlus", meta = (HidePin = "Target"))
	static void NotifyNonInheritedPropertiesChangedExcept(UObject* Owner, TArray<FName>& PropertyNames);
};