#include "ObjectA.h"
#include <iostream>
#include <windows.h>

using std::cout;
using std::endl;

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