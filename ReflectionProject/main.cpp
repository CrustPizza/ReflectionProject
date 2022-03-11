#include <iostream>
#include <Windows.h>
#include <tchar.h>
#include <conio.h>

class ObjectA;
class ObjectB;

typedef void (*PrintTest)(void);
typedef ObjectA* (*CreateObjA)();
typedef ObjectB* (*CreateObjB)();
typedef void(*callFunc)(ObjectA*);

#define asd\


class A
{
public:
	size_t GetTypeHash();
public:
	A() : x(100), y(100) {};

	void print(int* _x, int* _y)
	{
		std::cout << "Print" << std::endl;
		std::cout << "Print" << std::endl;

		std::cout << _x << std::endl;
		std::cout << _y << std::endl;

		*_x = 1000;
		*_y = 1000;
	}

	void print2()
	{
		std::cout << "Print" << std::endl;
		std::cout << "Print" << std::endl;
	}

	void print3()
	{
		std::cout << "Print" << std::endl;
		std::cout << "Print" << std::endl;
	}

	void print4()
	{
		std::cout << "Print" << std::endl;
		std::cout << "Print" << std::endl;
	}

	int x;
	int y;
};

int main()
{
	A a;

	void(__thiscall A::*temp3)(int*, int*) = &A::print;
	void(__thiscall * test3)(int*, int*) = reinterpret_cast<void(__thiscall *&)(int*, int*)>(temp3);

	std::cout << &a.x << std::endl;
	std::cout << &a.y << std::endl;

	test3(&(a.x), &(a.y));

	std::cout << a.x << std::endl;
	std::cout << a.y << std::endl;

	//while (true)
	//{
	//	if (_kbhit() != 0)
	//	{
	//		char input = _getch();

	//		if (input == 'q')
	//			break;

	//		HMODULE hDll = LoadLibrary(_T("../Debug/MyDLL.dll"));

	//		if (hDll != nullptr)
	//		{
	//			PrintTest temp = reinterpret_cast<PrintTest>(GetProcAddress(hDll, "Print"));

	//			CreateObjA testa = reinterpret_cast<CreateObjA>(GetProcAddress(hDll, "CreateObjectA"));
	//			CreateObjB testb = reinterpret_cast<CreateObjB>(GetProcAddress(hDll, "CreateObjectB"));
	//			callFunc test = reinterpret_cast<callFunc>(GetProcAddress(hDll, "CallTest"));

	//			ObjectA* tempA = testa();
	//			ObjectB* tempB = testb();

	//			temp();
	//			
	//			test(tempA);
	//			test(reinterpret_cast<ObjectA*>(tempB));

	//			delete tempA;
	//			delete tempB;

	//			FreeLibrary(hDll);
	//		}
	//	}
	//}

	return 0;
}

size_t A::GetTypeHash()
{
	static size_t uP;

	x = 1000;

	return reinterpret_cast<size_t>(&uP);
}