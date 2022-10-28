#include "ObjectA.h"
#include <iostream>
#include <windows.h>

using std::cout;
using std::endl;

REGISTER_RUNTIME_CLASS(ObjectA);
REGISTER_RUNTIME_CLASS(ObjectB);
REGISTER_RUNTIME_CLASS(ObjectC);
REGISTER_RUNTIME_CLASS(ObjectASDF);
REGISTER_RUNTIME_CLASS(TestClass);
REGISTER_RUNTIME_CLASS(Test1Class);
REGISTER_RUNTIME_CLASS(BadOKM);

ObjectA::ObjectA()
{
	cout << "Create A" << endl;
}

ObjectA::~ObjectA()
{
	cout << "Delete A" << endl;
}

void ObjectA::test()
{
	cout << "Test A" << endl;
}

ObjectB::ObjectB()
{
	cout << "Create B" << endl;
}

ObjectB::~ObjectB()
{
	cout << "Delete B" << endl;
}

void ObjectB::test()
{
	cout << "Test B" << endl;
}

ObjectC::ObjectC()
{
	cout << "Create C" << endl;
}

ObjectC::~ObjectC()
{
	cout << "Delete C" << endl;
}

ObjectASDF::ObjectASDF()
{
	cout << "Create ASDF" << endl;
}

ObjectASDF::~ObjectASDF()
{
	cout << "Delete ASDF" << endl;
}

TestClass::TestClass()
{
	cout << "Create TestClass" << endl;
}

TestClass::~TestClass()
{
	cout << "Delete TestClass" << endl;
}

Test1Class::Test1Class()
{
	cout << "Create Test1Class" << endl;
}

Test1Class::~Test1Class()
{
	cout << "Delete Test1Class" << endl;
}

BadOKM::BadOKM()
{
	cout << "Create BadOKM" << endl;
}

BadOKM::~BadOKM()
{
	cout << "Delete BadOKM" << endl;
}