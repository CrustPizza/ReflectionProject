#pragma once
//#include "../ReflectionProject/RuntimeClass.h"

#ifdef MYDLL_EXPORTS
#define MYDLL_DECLSPEC __declspec(dllexport)
#else
#define MYDLL_DECLSPEC __declspec(dllimport)
#endif

class MYDLL_DECLSPEC ObjectA
{
public:
	virtual void test();
};

class MYDLL_DECLSPEC ObjectB : public ObjectA
{
public:
	virtual void test();
};

extern "C" MYDLL_DECLSPEC void Print();

extern "C" MYDLL_DECLSPEC ObjectA* CreateObjectA();
extern "C" MYDLL_DECLSPEC ObjectB* CreateObjectB();
extern "C" MYDLL_DECLSPEC void CallTest(ObjectA* obj);