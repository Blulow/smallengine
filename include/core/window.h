#pragma once

class Window {
private:
    Renderer renderer;

    static void* GetWGLProcAddress(const char* name);
    static LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

    int LoadGLDummyWindowThenKill(HINSTANCE hInstance) const;
    int LoadActualWindow(HINSTANCE hInstance, int nCmdShow) const;
public:
    Renderer getRenderer() const;

    int GenerateWindow(HINSTANCE hInstance, int nCmdShow) const;
    int TerminateWindow(HINSTANCE hInstance) const;
};