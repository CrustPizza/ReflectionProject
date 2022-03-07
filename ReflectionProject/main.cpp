#include <iostream>
#include <Windows.h>
#include <tchar.h>
#include <conio.h>

typedef void (*PrintTest)(void);

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

				temp();

				FreeLibrary(hDll);
			}
		}
	}

	return 0;
}