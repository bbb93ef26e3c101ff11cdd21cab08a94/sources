#pragma once
#include "lipton.h"
DWORD sound1() {
    WAVEFORMATEX fmt = { WAVE_FORMAT_PCM, 1, 4000, 4000, 1, 8, 0 };
    HWAVEOUT hwo = 0;
    waveOutOpen(&hwo, WAVE_MAPPER, &fmt, 0, 0, CALLBACK_NULL);
    const int bufsize = 44100 * 30;
    char* wavedata = (char*)LocalAlloc(0, bufsize);
    WAVEHDR hdr = { wavedata, bufsize, 0, 0, 0, 0, 0, 0 };
    waveOutPrepareHeader(hwo, &hdr, sizeof(hdr));
    int wavefrequency = 0; srand(time(0));
    for (;;) {
        for (int i = 0; i < bufsize; i++) {
            wavedata[i] = (char)(((i % 150) / ((float)wavefrequency)) * 100);
            waveOutWrite(hwo, &hdr, sizeof(hdr));
            if (i % (44100 / 4) == 0) {
                wavefrequency = 44100 / ((rand() % 44100) + 1000);
                waveOutWrite(hwo, &hdr, sizeof(hdr)); Sleep(rand() % 2);
            }
        }
    }
}
DWORD sound2() {
    WAVEFORMATEX fmt = { WAVE_FORMAT_PCM, 1, 4000, 4000, 1, 8, 0 };
    HWAVEOUT hwo = 0;
    waveOutOpen(&hwo, WAVE_MAPPER, &fmt, 0, 0, CALLBACK_NULL);
    const int bufsize = 44100 * 30;
    char* wavedata = (char*)LocalAlloc(0, bufsize);
    WAVEHDR hdr = { wavedata, bufsize, 0, 0, 0, 0, 0, 0 };
    waveOutPrepareHeader(hwo, &hdr, sizeof(hdr));
    int wavefrequency = 0; srand(time(0));
    for (;;) {
        for (int i = 0; i < bufsize; i++) {
            wavedata[i] = (char)(((i) / ((float)wavefrequency)) * 100);
            waveOutWrite(hwo, &hdr, sizeof(hdr));
            if (i % (44100 / 4) == 0) {
                wavefrequency = 44100 / ((rand() % 44100) + 1000);
                waveOutWrite(hwo, &hdr, sizeof(hdr)); Sleep(rand() % 2);
            }
        }
    }
}