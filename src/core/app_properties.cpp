#include <iostream>
#include <windows.h>
#include <algorithm>

#include <core/app_properties.h>

AppProperties G_APPPROP;

LPCWSTR AppProperties::getClassName() const {
    return CLASS_NAME;
}

HWND AppProperties::getHWND() const {
    return hwnd;
}

void AppProperties::setHWND(HWND _hwnd) {
    hwnd = _hwnd;
}

HDC AppProperties::getHDC() const {
    return hdc;
}

void AppProperties::setHDC(HDC _hdc) {
    hdc = _hdc;
}

HGLRC AppProperties::getHRC() const {
    return hrc;
}

void AppProperties::setHRC(HGLRC _hrc) {
    hrc = _hrc;
}

std::array<float, 4> AppProperties::getWindowBackgroundColor() const {
    return WINDOW_BACKGROUND_COLOR;
}

void AppProperties::setWindowBackgroundColor(float r, float g, float b, float a) {
    float cr = std::clamp(r, 0.0f, 1.0f);
    float cg = std::clamp(g, 0.0f, 1.0f);
    float cb = std::clamp(b, 0.0f, 1.0f);
    float ca = std::clamp(a, 0.0f, 1.0f);

    WINDOW_BACKGROUND_COLOR = { cr, cg, cb, ca };
}
