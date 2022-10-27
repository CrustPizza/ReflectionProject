#include <Windows.h>
#include <iostream>
#include "ObjectA.h"

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		REGISTER_RUNTIME_CLASS(ObjectA);
		REGISTER_RUNTIME_CLASS(ObjectB);
		REGISTER_RUNTIME_CLASS(ObjectC);
		REGISTER_RUNTIME_CLASS(ObjectASDF);
		break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	case DLL_PROCESS_DETACH:
		break;
	}

	return TRUE;
}