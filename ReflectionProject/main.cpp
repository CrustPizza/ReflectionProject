#include <windows.h>
#include <conio.h>
#include <tchar.h>
#include <typeinfo>
#include <iostream>
#include <vector>
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
	struct RuntimeClasses
	{
		std::string name;
		RuntimeClass* ptr;
	};
	std::vector<RuntimeClasses> createdObjects;

	while (true)
	{
		HMODULE hDll = hDll = LoadLibrary(_T("MyDLL.dll"));

		while (true)
		{
			if (hDll != nullptr)
			{
				system("cls");

				std::cout << "Runtime Object List" << std::endl;

				RuntimeClass::GetInstance()->PrintAll();

				std::cout << "----------------------------" << std::endl;

				std::cout << "Created Object List" << std::endl;

				for (int i = 0; i < createdObjects.size(); i++)
					std::cout << "[" << i + 1 << "] " << createdObjects[i].name << ", Pointer Address : " << createdObjects[i].ptr << std::endl;

				std::cout << "----------------------------" << std::endl;

				std::cout << "c : Create Object / r : Reload dll / q : Quit" << std::endl;

				while (_kbhit() == 0);

				char input = _getch();

				if (input == 'q')
				{
					for (int i = 0; i < createdObjects.size(); i++)
						delete createdObjects[i].ptr;

					RuntimeClass::Release();

					FreeLibrary(hDll);

					return 0;
				}

				if (input == 'c')
				{
					std::cout << "Insert Object Name" << std::endl;

					std::string objectName;
					std::cin >> objectName;

					auto objA = RuntimeClass::GetInstance()->CreateObject(objectName);

					if (objA == nullptr)
					{
						std::cout << "Wrong name." << std::endl;
					}
					else
					{
						createdObjects.push_back({ objectName, objA });
					}

					system("pause");
				}

				if (input == 'r')
				{
					for (int i = 0; i < createdObjects.size(); i++)
						delete createdObjects[i].ptr;

					createdObjects.clear();

					RuntimeClass::Release();

					FreeLibrary(hDll);

					system("pause");

					break;
				}
			}
		}
	}


	return 0;
}