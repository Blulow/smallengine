#pragma once
#include <iostream>
#include <windows.h>

struct AppProperties {
    const int WINDOW_WIDTH = 1000;
    const int WINDOW_HEIGHT = 500;
    
    const float WINDOW_BACKGROUND[4] = { 0.5f, 0.5f, 0.5f, 1.0f };

    LPCWSTR CLASS_NAME = L"SmallEngineClass";
    HWND hwnd = nullptr;
    HDC hdc = nullptr;
    HGLRC hrc = nullptr;
};

extern AppProperties G_APPPROP;