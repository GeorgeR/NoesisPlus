#include "NoesisPlusFunctionLibrary.h"
#include "NoesisTypeClass.h"

TMap<UStruct*, TArray<FName>> NonInheritedPropertyMap;

void GetNonInheritedProperties(UStruct* InClass, TArray<FName>& OutProperties)
{
	check(InClass);

	if (NonInheritedPropertyMap.Contains(InClass))
	{
		OutProperties = NonInheritedPropertyMap[InClass];
		return;
	}
	
	NonInheritedPropertyMap.Add(InClass, TArray<FName>());
	for(TFieldIterator<UProperty> Iterator(InClass); Iterator; ++Iterator)
		NonInheritedPropertyMap[InClass].Add((*Iterator)->GetFName());

	return GetNonInheritedProperties(InClass, OutProperties);
}

void NoesisNotifyPropertiesChanged(UObject* Owner, TArray<FName>& PropertyNames)
{
	for(auto& Property : PropertyNames)
		NoesisNotifyPropertyChanged(Owner, Property);
}

void NoesisNotifyNonInheritedPropertiesChanged(UObject* Owner)
{
	check(Owner);

	TArray<FName> PropertyNames;
	GetNonInheritedProperties(Owner->GetClass(), PropertyNames);
	if (PropertyNames.Num() <= 0)
		return;

	for (auto& Property : PropertyNames)
		NoesisNotifyPropertyChanged(Owner, Property);
}

void NoesisNotifyNonInheritedPropertiesChangedExcept(UObject* Owner, TArray<FName>& PropertyNames)
{
	check(Owner);

	TArray<FName> IncludedPropertyNames;
	GetNonInheritedProperties(Owner->GetClass(), IncludedPropertyNames);
	if (IncludedPropertyNames.Num() <= 0)
		return;

	if(PropertyNames.Num() > 0)
	{
		for (auto& Name : PropertyNames)
			if (IncludedPropertyNames.Contains(Name))
				IncludedPropertyNames.Remove(Name);
	}

	for (auto& Property : PropertyNames)
		NoesisNotifyPropertyChanged(Owner, Property);
}

void UNoesisPlusFunctionLibrary::NotifyPropertiesChanged(UObject* Owner, TArray<FName>& PropertyNames)
{
	check(Owner);

	NoesisNotifyPropertiesChanged(Owner, PropertyNames);
}

void UNoesisPlusFunctionLibrary::NotifyPropertiesChanged_CSV(UObject* Owner, FName PropertyNames)
{
	check(Owner);
	
	TArray<FString> Split;
	PropertyNames.ToString().ParseIntoArray(Split, new TCHAR[2]{ ',', ' ' });

	check(Split.Num() > 0);

	TArray<FName> PropertyNames2;
	for (auto& Str : Split)
		PropertyNames2.Add(FName(*Str));

	NotifyPropertiesChanged(Owner, PropertyNames2);
}

void UNoesisPlusFunctionLibrary::NotifyNonInheritedPropertiesChanged(UObject* Owner)
{
	check(Owner);

	NoesisNotifyNonInheritedPropertiesChanged(Owner);
}

void UNoesisPlusFunctionLibrary::NotifyNonInheritedPropertiesChangedExcept(UObject* Owner, TArray<FName>& PropertyNames)
{
	check(Owner);

	NoesisNotifyNonInheritedPropertiesChangedExcept(Owner, PropertyNames);
}