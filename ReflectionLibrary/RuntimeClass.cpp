#include "RuntimeClass.h"

#include <iostream>

RuntimeClass::RuntimeClass()
{

}

RuntimeClass::~RuntimeClass()
{

}

RuntimeClass::Type* RuntimeClass::CreateObject(const std::string& className)
{
	auto result = GetRTClasses().find(className);

	if (result == GetRTClasses().end())
		return nullptr;

	return result->second->CreateObject();
}

RuntimeClass::Type* RuntimeClass::CreateObject()
{
	return nullptr;
}

RuntimeClass::Type* RuntimeClass::GetType()
{
	return nullptr;
}

void RuntimeClass::PrintAll()
{
	int count = 1;

	for (auto& iter : GetRTClasses())
	{
		std::cout << "[" << count++ << "] " << iter.first << std::endl;
	}
}

void RuntimeClass::Release()
{
	for (auto& iter : GetRTClasses())
	{
		if (iter.second != nullptr)
			delete iter.second;
	}

	GetRTClasses().clear();
}