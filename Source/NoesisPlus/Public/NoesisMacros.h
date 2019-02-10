#pragma once

#define NS_DECLARE_PROPERTY(PropertyType, PropertyName)										\
	static const Noesis::DependencyProperty* PropertyName##Property;						\
	const PropertyType Get##PropertyName() const;											\
	void Set##PropertyName(PropertyType PropertyName);		

#define NS_DEFINE_PROPERTY(ClassName, PropertyType, PropertyName)							\
	const DependencyProperty* ClassName::PropertyName##Property;							\
	const PropertyType ClassName::Get##PropertyName() const									\
	{																						\
		return Noesis::DependencyObject::GetValue<PropertyType>(PropertyName##Property);				\
	}																						\
	void ClassName::Set##PropertyName(PropertyType PropertyName)							\
	{																						\
		Noesis::DependencyObject::SetValue<PropertyType>(PropertyName##Property, PropertyName);		\
	}

#define NS_DECLARE_PROPERTY_STR(PropertyName)												\
	static const Noesis::DependencyProperty* PropertyName##Property;						\
	const char* Get##PropertyName() const;													\
	void Set##PropertyName(const char* PropertyName);		

#define NS_DEFINE_PROPERTY_STR(ClassName, PropertyName)										\
	const DependencyProperty* ClassName::PropertyName##Property;							\
	const char* ClassName::Get##PropertyName() const										\
	{																						\
		return Noesis::DependencyObject::GetValue<NsString>(PropertyName##Property).c_str();\
	}																						\
	void ClassName::Set##PropertyName(const char* PropertyName)								\
	{																						\
		Noesis::DependencyObject::SetValue<NsString>(PropertyName##Property, PropertyName);	\
	}

#define NS_DECLARE_PROPERTY_ENUM(PropertyType, PropertyName)															\
	static const Noesis::DependencyProperty* PropertyName##Property;													\
	const PropertyType Get##PropertyName() const;																		\
	void Set##PropertyName(PropertyType PropertyName);		

#define NS_DEFINE_PROPERTY_ENUM(ClassName, PropertyType, PropertyName)													\
	const DependencyProperty* ClassName::PropertyName##Property;														\
	const PropertyType ClassName::Get##PropertyName() const																\
	{																													\
		return static_cast<PropertyType>(Noesis::DependencyObject::GetValue<int>(PropertyName##Property));				\
	}																													\
	void ClassName::Set##PropertyName(PropertyType PropertyName)														\
	{																													\
		Noesis::DependencyObject::SetValue<int>(PropertyName##Property, static_cast<int>(PropertyName));				\
	}
