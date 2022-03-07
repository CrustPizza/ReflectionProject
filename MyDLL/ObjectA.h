#pragma once
#include "../ReflectionProject/RuntimeClass.h"

#ifdef MYDLL_EXPORTS
#define MYDLL_DECLSPEC __declspec(dllexport)
#else
#define MYDLL_DECLSPEC __declspec(dllimport)
#endif

class MYDLL_DECLSPEC ObjectA : public RuntimeClass
{

};

extern "C" MYDLL_DECLSPEC void Print();