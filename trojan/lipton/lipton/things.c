#pragma once
#include "lipton.h"
DWORD64 random() {
	DWORD64 num = __rdtsc();
	num ^= num << 17;
	num ^= num >> 13;
	num ^= num << 5;
	return num;
}