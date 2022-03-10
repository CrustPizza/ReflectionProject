#pragma once
#include <map>
#include <string>
//
//using std::map;
//using std::string;
//
//#define DeclareClass(className) \
//private:\
//	static ##className* ##clasNameInstance;\
//public:\
//	virtual const RuntimeClass* GetThisClass() override\
//{\
//	return ##clasNameInstance;\
//}
//
//#define ImplementClass(className) \
//
//class RuntimeClass
//{
//	typedef RuntimeClass*(*Constructor)(void);
//	static map<string, Constructor> classList;
//
//public:
//	static void AddClass(string className, Constructor constructFunction)
//	{
//		classList[className] = constructFunction;
//	}
//};
//
//map<string, RuntimeClass::Constructor> RuntimeClass::classList;