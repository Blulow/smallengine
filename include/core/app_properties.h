#pragma once
#include <array>

class AppProperties {
private:
    LPCWSTR CLASS_NAME = L"SmallEngineClass";
    HWND hwnd = nullptr;
    HDC hdc = nullptr;
    HGLRC hrc = nullptr;
    
    std::array<float, 4> WINDOW_BACKGROUND_COLOR = { 0.5f, 0.5f, 0.5f, 1.0f };
public:
    LPCWSTR getClassName() const;
    HWND getHWND() const;
    void setHWND(HWND _hwnd);
    HDC getHDC() const;
    void setHDC(HDC _hdc);
    HGLRC getHRC() const;
    void setHRC(HGLRC _hrc);

    const int INIT_WINDOW_WIDTH = 1000;
    const int INIT_WINDOW_HEIGHT = 500;

    std::array<float, 4> getWindowBackgroundColor() const;
    void setWindowBackgroundColor(float r, float g, float b, float a);
};

extern AppProperties G_APPPROP;