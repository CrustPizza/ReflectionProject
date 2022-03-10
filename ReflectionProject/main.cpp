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

int main()
{
	while (true)
	{
		if (_kbhit() != 0)
		{
			char input = _getch();

			if (input == 'q')
				break;

			HMODULE hDll = LoadLibrary(_T("../Debug/MyDLL.dll"));

			if (hDll != nullptr)
			{
				PrintTest temp = reinterpret_cast<PrintTest>(GetProcAddress(hDll, "Print"));

				CreateObjA testa = reinterpret_cast<CreateObjA>(GetProcAddress(hDll, "CreateObjectA"));
				CreateObjB testb = reinterpret_cast<CreateObjB>(GetProcAddress(hDll, "CreateObjectB"));
				callFunc test = reinterpret_cast<callFunc>(GetProcAddress(hDll, "CallTest"));

				ObjectA* tempA = testa();
				ObjectB* tempB = testb();

				temp();
				
				test(tempA);
				test(reinterpret_cast<ObjectA*>(tempB));

				delete tempA;
				delete tempB;

				FreeLibrary(hDll);
			}
		}
	}

	return 0;
}