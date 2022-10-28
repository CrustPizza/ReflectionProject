#pragma once
#include "../ReflectionLibrary/RuntimeClass.h"

#pragma comment(lib, "../x64/Debug/ReflectionLibrary.lib")

#ifdef MYDLL_EXPORTS
#define MYDLL_DECLSPEC __declspec(dllexport)
#else
#define MYDLL_DECLSPEC __declspec(dllimport)
#endif

class MYDLL_DECLSPEC ObjectA : public RuntimeClass
{
	DECLARE_RUNTIME_CLASS(ObjectA)

public:
	ObjectA();

	virtual ~ObjectA();

	virtual void test();
};

class MYDLL_DECLSPEC ObjectB : public ObjectA
{
	DECLARE_RUNTIME_CLASS(ObjectB)

public:
	ObjectB();

	virtual ~ObjectB();

	virtual void test();
};

class MYDLL_DECLSPEC ObjectC : public ObjectA
{
	DECLARE_RUNTIME_CLASS(ObjectC)

public:
	ObjectC();

	virtual ~ObjectC();
};

class MYDLL_DECLSPEC ObjectASDF : public ObjectA
{
	DECLARE_RUNTIME_CLASS(ObjectASDF)

public:
	ObjectASDF();

	virtual ~ObjectASDF();
};

class MYDLL_DECLSPEC TestClass : public RuntimeClass
{
	DECLARE_RUNTIME_CLASS(TestClass)

public:
	TestClass();

	virtual ~TestClass();
};

class MYDLL_DECLSPEC Test1Class : public RuntimeClass
{
	DECLARE_RUNTIME_CLASS(Test1Class)

public:
	Test1Class();

	virtual ~Test1Class();
};

class MYDLL_DECLSPEC BadOKM : public RuntimeClass
{
	DECLARE_RUNTIME_CLASS(BadOKM)

public:
	BadOKM();

	virtual ~BadOKM();
};