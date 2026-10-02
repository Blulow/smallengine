#include <iostream>
#include <windows.h>
#include <core/time.h>

Time G_TIME;

Time::Time() {
    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&lastTime);
}

void Time::timeUpdate() {
    LARGE_INTEGER currentTime;
    QueryPerformanceCounter(&currentTime);
    deltaTime = (float)(currentTime.QuadPart - lastTime.QuadPart) / (float)frequency.QuadPart;
    lastTime = currentTime;
}

float Time::getDeltaTime() const {
    return deltaTime;
}