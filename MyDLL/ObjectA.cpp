#include "ObjectA.h"
#include <iostream>

using std::cout;
using std::endl;

MYDLL_DECLSPEC void Print()
{
	cout << "DLL Print2\n";
}

MYDLL_DECLSPEC ObjectA* CreateObjectA()
{
	return new ObjectA;
}

MYDLL_DECLSPEC ObjectB* CreateObjectB()
{
	return new ObjectB;
}

MYDLL_DECLSPEC void CallTest(ObjectA* obj)
{
	obj->test();
}

void ObjectA::test()
{
	cout << "Test A" << endl;
}

void ObjectB::test()
{
	cout << "Test B" << endl;
}