#include <windows.h>
static ULONGLONG r, n;
INT randy() { return n = r, n ^= 0x8ebf635bee3c6d25, n ^= n << 5 | n >> 26, n *= 0xf3e05ca5c43e376b, r = n, n & 0x7fffffff;}

DWORD
WINAPI
helly1(
   LPVOID lpParam
) {
	HDC hdcScreen = GetDC(0);
	INT w = GetSystemMetrics(0), h = GetSystemMetrics(1);
	for (INT i = 0;; i++) {
		INT(a) = randy() % w, b = randy() % h;
		BitBlt(hdcScreen, a, b, 200, 200, hdcScreen, a + randy() % 21 - 10, b + randy() % 21 - 10, !(randy() & 3) ? 0xEE0086 : 0xCC0020);
	}
}

DWORD
WINAPI
helly2(
   LPVOID lpParam
) {
	INT nTicks = GetTickCount();
	INT w = GetSystemMetrics(0), h = GetSystemMetrics(1);
	RGBQUAD* rgbData = (RGBQUAD*)VirtualAlloc(NULL, (w * h + w) * sizeof(RGBQUAD), MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
	for (INT i = 0;; i++, i %= 3) {
		if (!1)RedrawWindow(0, 0, 0, 133);
		HDC hdcScreen = GetDC(0), hdcMem = CreateCompatibleDC(hdcScreen); 
		HBITMAP hbm = CreateBitmap(w, h, 1, 32, rgbData);
		SelectObject(hdcMem, hbm);
		BitBlt(hdcMem, 0, 0, w, h, hdcScreen, 0, 0, 0x330008);
		GetBitmapBits(hbm, w * h * 4, rgbData);
		INT nVortex = 0;
		BYTE rgbBits = 0;
		if ((GetTickCount() - nTicks) > 60000)
			rgbBits = randy() & 0xFF;
		for (INT i = 0; w * h > i; i++) {
			if (i % h == 0 && randy() % 100 == 0)
				nVortex = randy() % 50;
			((BYTE*)(rgbData + i))[nVortex % 3] += ((BYTE*)(rgbData + i + nVortex))[nVortex] ^ rgbBits;
		}
		SetBitmapBits(hbm, w * h * 4, rgbData);
		BitBlt(hdcScreen, randy() % 3 - 1, randy() % 3 - 1, w, h, hdcMem, 0, 0, 0xCC0020);
		DeleteObject(hbm); DeleteObject(hdcMem);DeleteObject(hdcScreen);
	}
}

int main(HINSTANCE(a), HINSTANCE(b), LPSTR(c), int(d))
{
       CreateThread(0, 0, helly1, 0, 0, 0);
       CreateThread(0, 0, helly2, 0, 0, 0);
       Sleep(INFINITE);
}
