#pragma once
#include "lipton.h"

DWORD payload1() {
	HDC desk = GetDC(0); HWND wnd = GetDesktopWindow();
	int sw = GetSystemMetrics(0), sh = GetSystemMetrics(1);
	double angle = 0;
	for (;;) {
		desk = GetDC(0);
		for (float i = 0; i < sw + sh; i += 0.99f) {
			int a = sin(angle) * 10;
			BitBlt(desk, i, 0, 1, sh, desk, i, a, SRCCOPY);
			angle += M_PI / 80;
			DeleteObject(&a);DeleteObject(&i);
		}
		ReleaseDC(wnd, desk);
		DeleteDC(desk); DeleteObject(wnd); DeleteObject(&sw); DeleteObject(&sh);DeleteObject(&angle);
	}
}
DWORD payload2() {
	HDC desk = GetDC(0); HWND wnd = GetDesktopWindow();
	int sw = GetSystemMetrics(0), sh = GetSystemMetrics(1);
	for (;;) {
		desk = GetDC(0);
		SetTextColor(desk, RGB(random() % 256, random() % 256, random() % 256));
		TextOutA(desk, random() % sw, random() % sh, "    ", random() % sw);
		TextOutA(desk, 0 - random() % sw, random() % sh, "    ", random() % sw);
		TextOutA(desk, random() % sw, 0 - random() % sh, "    ", random() % sw);
		TextOutA(desk, 0 - random() % sw, 0 - random() % sh, "    ", random() % sw);
		DeleteDC(desk); DeleteObject(&sw); DeleteObject(&sh); DeleteObject(wnd);
	}
}
DWORD payload3() {
	HDC desk = GetDC(0); HWND wnd = GetDesktopWindow();
	int sw = GetSystemMetrics(0), sh = GetSystemMetrics(1);
	BITMAPINFO bmi = { 40, sw, sh, 1, 24 };
	PRGBTRIPLE rgbtriple;
	for (;;) {
		desk = GetDC(0);
		HDC deskMem = CreateCompatibleDC(desk);
		HBITMAP scr = CreateDIBSection(desk, &bmi, 0, (void**)&rgbtriple, 0, 0);
		SelectObject(deskMem, scr);
		BitBlt(deskMem, 0, 0, sw, sh, desk, 0, 0, SRCCOPY);
		for (int i = 0; i < sw * sh; i++) {
			rgbtriple[i].rgbtRed += 5;
			rgbtriple[i].rgbtGreen += 10;
			rgbtriple[i].rgbtBlue += 15;
		}
		BitBlt(desk, 0, 0, sw, sh, deskMem, 0, 0, SRCCOPY);
		ReleaseDC(wnd, desk);
		DeleteDC(desk); DeleteDC(deskMem); DeleteObject(scr); DeleteObject(wnd); DeleteObject(rgbtriple);DeleteObject(&sw); DeleteObject(&sh); DeleteObject(&bmi);
	}
}
DWORD payload4() {
	HDC desk = GetDC(0); HWND wnd = GetDesktopWindow();
	int sw = GetSystemMetrics(0), sh = GetSystemMetrics(1);
	for (;;) {
		desk = GetDC(0);
		HGDIOBJ hObj = CreateSolidBrush(RGB(random() % 256, random() % 256, random() % 256)); SelectObject(desk, hObj);
		BitBlt(desk, random() % 2, random() % 2, sw, sh, desk, random() % 2, random() % 2, MERGECOPY); Sleep(random() % 30);
		ReleaseDC(wnd, desk);
		DeleteDC(desk);DeleteObject(wnd); DeleteObject(hObj); DeleteObject(&sw); DeleteObject(&sh);
	}
}
DWORD payload5() {
	HDC desk = GetDC(0); HWND wnd = GetDesktopWindow();
	int sw = GetSystemMetrics(0), sh = GetSystemMetrics(1), a = 0, b = 0, c = 2, d = 3;
	for (;;) {
		desk = GetDC(0);
		a += c, b += d;
		BitBlt(desk, a, b, a, b, desk, 0, 0, SRCCOPY);
		if (a > sw || a < 0) c = -c;
		if (b > sh || b < 0) c = -c;
		ReleaseDC(wnd, desk);
		DeleteDC(desk);DeleteObject(wnd); DeleteObject(&sw); DeleteObject(&sh); DeleteObject(&a); DeleteObject(&b); DeleteObject(&c); DeleteObject(&d);
	}
}
DWORD payload6() {
	HDC desk = GetDC(0); HWND wnd = GetDesktopWindow();
	int sw = GetSystemMetrics(0), sh = GetSystemMetrics(1);
	for (;;) {
		desk = GetDC(0);
		StretchBlt(desk, -100, -100, sw + 100, sh + 100, desk, sw, 0, -sw, sh, NOTSRCERASE);
		ReleaseDC(wnd, desk);
		DeleteDC(desk);DeleteObject(wnd); DeleteObject(&sw); DeleteObject(&sh);
	}
}
DWORD payload7() {
	HDC desk = GetDC(0); HWND wnd = GetDesktopWindow();
	int sw = GetSystemMetrics(0), sh = GetSystemMetrics(1);
	RECT wRect;
	POINT wPt[3];
	for (;;) {
		desk = GetDC(0);
		GetWindowRect(GetDesktopWindow(), &wRect);
		wPt[0].x = wRect.left + random() % sw;
		wPt[0].y = wRect.top - random() % sh;
		wPt[1].x = wRect.right - random() % sw;
		wPt[1].y = wRect.top + random() % sh;
		wPt[2].x = wRect.left * random() % sw;
		wPt[2].y = wRect.bottom + random() % sh;
		PlgBlt(desk, wPt, desk, 0, 0, sw, sh, 0, 0, 0);
		ReleaseDC(wnd, desk);
		DeleteDC(desk); DeleteObject(wnd); DeleteObject(&sw); DeleteObject(&sh); DeleteObject(&wRect); DeleteObject(&wPt);
	}
}
DWORD payload8() {
	HDC desk = GetDC(0); HWND wnd = GetDesktopWindow();
	int sw = GetSystemMetrics(0), sh = GetSystemMetrics(1);
	double angle = 0;
	for (;;) {
		desk = GetDC(0);
		double x = cos(angle) * 100, y = sin(angle) * 100;
		BitBlt(desk, x, y, sw, sh, desk, 0, 0, SRCCOPY);
		ReleaseDC(wnd, desk);
		DeleteDC(desk); DeleteObject(wnd); DeleteObject(&sw); DeleteObject(&sh);
	}
}
DWORD payload9() {
	HDC desk = GetDC(0); HWND wnd = GetDesktopWindow();
	int sw = GetSystemMetrics(0), sh = GetSystemMetrics(1);
	BITMAPINFO bmi = { 40, sw, sh, 1, 24 };
	PRGBTRIPLE rgbtriple;
	for (;;) {
		desk = GetDC(0);
		HDC deskMem = CreateCompatibleDC(desk);
		HBITMAP scr = CreateDIBSection(desk, &bmi, 0, (void**)&rgbtriple, 0, 0);
		SelectObject(deskMem, scr);
		BitBlt(deskMem, 0, 0, sw, sh, desk, 0, 0, SRCCOPY);
		for (int i = 0; i < sw * sh; i++) {
			int x = i % sw, y = i / sh, t = y ^ y | x;
			rgbtriple[i].rgbtRed += GetRValue(t);
			rgbtriple[i].rgbtGreen += GetGValue(t);
			rgbtriple[i].rgbtBlue += GetBValue(t);
		}
		BitBlt(desk, 0, 0, sw, sh, deskMem, 0, 0, SRCCOPY);
		ReleaseDC(wnd, desk);
		DeleteDC(desk); DeleteDC(deskMem); DeleteObject(scr); DeleteObject(wnd); DeleteObject(rgbtriple);DeleteObject(&sw); DeleteObject(&sh); DeleteObject(&bmi);
	}
}
DWORD payload10() {
	HDC desk = GetDC(0); HWND wnd = GetDesktopWindow();
	int sw = GetSystemMetrics(0), sh = GetSystemMetrics(1);
	for (;;) {
		desk = GetDC(0);
		int radius = 100, rx = rand() % sw, ry = rand() % sh;
		for (int i = 0; i < sw + sh; i++) {
			int x = radius + i * cos(i + radius * 3) + rx, y = radius + i * sin(i + radius * 3) + ry;
			BitBlt(desk, x, y, 100, 100, desk, 0, 0, NOTSRCCOPY); Sleep(3);
			DeleteObject(&x); DeleteObject(&y); DeleteObject(&i);
		}
		ReleaseDC(wnd, desk);
		DeleteDC(desk);  DeleteObject(wnd); DeleteObject(&sw); DeleteObject(&sh); 
	}
}