#include <windows.h>
#include <conio.h>
#include <tchar.h>
#include <typeinfo>
#include <iostream>
#include "../MyDLL/ObjectA.h"

extern "C"
{
	__declspec(dllexport) RuntimeClass* RTInstance()
	{
		return RuntimeClass::GetInstance();
	}

	__declspec(dllexport) std::map<std::string, RuntimeClass*>& RTClasses()
	{
		return RuntimeClass::GetRTClasses();
	}
}

int main()
{
	while (true)
	{
		if (_kbhit() != 0)
		{
			char input = _getch();

			if (input == 'q')
				break;

			HMODULE hDll = LoadLibrary(_T("MyDLL.dll"));

			if (hDll != nullptr)
			{
				auto objA = RuntimeClass::GetInstance()->CreateObject("ObjectA");
				auto objB = RuntimeClass::GetInstance()->CreateObject("ObjectB");

				std::cout << typeid(objA->GetType()).name() << std::endl;
				std::cout << typeid(objB).name() << std::endl;

				RuntimeClass::GetInstance()->PrintAll();

				delete objA;
				delete objB;

				RuntimeClass::Release();

				FreeLibrary(hDll);
			}
		}
	}

	return 0;
}