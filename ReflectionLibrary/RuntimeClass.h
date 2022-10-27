#pragma once
#include <map>
#include <string>
#include <functional>
#include <windows.h>

#define DECLARE_RUNTIME_CLASS(className) \
private: \
	friend RuntimeClass; \
	using Type = className; \
	virtual Type* CreateObject() override { return new Type; } \
	virtual Type* GetType() override { return nullptr; }

#define REGISTER_RUNTIME_CLASS(className) \
	static bool rtclass##className = RuntimeClass::GetInstance()->Register<className>(#className)

template<typename To, typename From>
To* Cast(From* ptr)
{
	return ptr != nullptr ? reinterpret_cast<To*>(ptr) : nullptr;
}

class RuntimeClass
{
	using Type = RuntimeClass;

public:
	RuntimeClass();

	virtual ~RuntimeClass();

	static std::map<std::string, RuntimeClass*>& GetRTClasses()
	{
#ifdef FOR_DLL
		using RTClasses = std::map<std::string, RuntimeClass*>&(*)(void);
		HMODULE hModule = GetModuleHandle(nullptr);
		RTClasses getFn = (RTClasses)GetProcAddress(hModule, "RTClasses");
		return getFn();
#else
		static std::map<std::string, RuntimeClass*> runtimeClasses;
		return runtimeClasses;
#endif
	}

	static RuntimeClass* GetInstance()
	{
#ifdef FOR_DLL
		using RTInstance = RuntimeClass*(*)(void);
		HMODULE hModule = GetModuleHandle(nullptr);
		RTInstance getFn = (RTInstance)GetProcAddress(hModule, "RTInstance");
		return getFn();
#else
		static RuntimeClass instance;
		return &instance;
#endif
	}

	Type* CreateObject(const std::string& className);

	virtual Type* CreateObject();

	virtual Type* GetType();

	void PrintAll();

	static void Release();

	template<class T>
	bool Register(const std::string& className);
};

template<class T>
inline bool RuntimeClass::Register(const std::string& className)
{
	if (GetRTClasses()[className] == nullptr)
	{
		GetRTClasses()[className] = new T;
		return true;
	}

	return false;
}