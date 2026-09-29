#include <iostream>
#include <windows.h>
#include <glad/gl.h>
#include <glad/wgl.h>
#include <smallengine/engine/app_properties.h>
#include <smallengine/engine/renderer.h>

AppProperties app; // fetch app properties
Renderer rdr; // fetch renderer

void* GetWGLProcAddress(const char* name) {
    void* p = (void*)wglGetProcAddress(name);
    if (p == 0 || p == (void*)0x1 || p == (void*)0x2 || p == (void*)0x3 || p == (void*)-1) {
        HMODULE module = LoadLibraryA("opengl32.dll");
        p = (void*)GetProcAddress(module, name);
    }
    return p;
}

// main message handling
LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch(msg) {
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
    }

    return DefWindowProc(hwnd, msg, wParam, lParam);
}

int LoadGLDummyWindowThenKill(HINSTANCE hInstance) {
    const char* DCLASS_NAME = "A";

    WNDCLASSEX dwc{};
    dwc.cbSize = sizeof(WNDCLASSEX);
    dwc.lpfnWndProc = DefWindowProc;
    dwc.hInstance = hInstance;
    dwc.lpszClassName = DCLASS_NAME;
    RegisterClassEx(&dwc);

    HWND dhwnd = CreateWindowEx(0, DCLASS_NAME, "", WS_OVERLAPPEDWINDOW,
        0, 0, 0, 0,
        nullptr, nullptr, hInstance, nullptr);
    
    HDC dhdc = GetDC(dhwnd);

    PIXELFORMATDESCRIPTOR dpfd{};
    dpfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
    dpfd.nVersion = 1;
    dpfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    dpfd.iPixelType = PFD_TYPE_RGBA;
    dpfd.cColorBits = 32;
    dpfd.cDepthBits = 24;
    dpfd.cStencilBits = 8;

    int dpf = ChoosePixelFormat(dhdc, &dpfd);
    SetPixelFormat(dhdc, dpf, &dpfd);

    HGLRC dhrc = wglCreateContext(dhdc);
    wglMakeCurrent(dhdc, dhrc);

    if (!gladLoadGL((GLADloadfunc)GetWGLProcAddress)) {
        return -1;
    }
    if (!gladLoadWGL(dhdc, (GLADloadfunc)GetWGLProcAddress)) {
        return -1;
    }

    wglMakeCurrent(nullptr, nullptr);
    wglDeleteContext(dhrc);
    ReleaseDC(dhwnd, dhdc);
    DestroyWindow(dhwnd);
    UnregisterClass(DCLASS_NAME, hInstance);

    return 0;
}

int LoadActualWindow(HINSTANCE hInstance, int nCmdShow) {
    const int SCREEN_WIDTH = GetSystemMetrics(SM_CXSCREEN);
    const int SCREEN_HEIGHT = GetSystemMetrics(SM_CYSCREEN);

    WNDCLASSEX wc{};
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = app.CLASS_NAME;
    RegisterClassEx(&wc);

    app.hwnd = CreateWindowEx(0, app.CLASS_NAME, "Small Engine",
        WS_OVERLAPPEDWINDOW | WS_VISIBLE,
        (SCREEN_WIDTH - app.WINDOW_WIDTH) / 2, (SCREEN_HEIGHT - app.WINDOW_HEIGHT) / 2,
        app.WINDOW_WIDTH, app.WINDOW_HEIGHT,
        nullptr, nullptr, hInstance, nullptr);
    ShowWindow(app.hwnd, nCmdShow);

    app.hdc = GetDC(app.hwnd);

    const int pixelAttribs[] = {
        WGL_DRAW_TO_WINDOW_ARB, GL_TRUE,
        WGL_SUPPORT_OPENGL_ARB, GL_TRUE,
        WGL_DOUBLE_BUFFER_ARB, GL_TRUE,
        WGL_PIXEL_TYPE_ARB, WGL_TYPE_RGBA_ARB,
        WGL_COLOR_BITS_ARB, 32,
        WGL_DEPTH_BITS_ARB, 24,
        WGL_STENCIL_BITS_ARB, 8,
        0
    };

    int pf = 0;
    UINT nFormats = 0;
    wglChoosePixelFormatARB(app.hdc, pixelAttribs, nullptr, 1, &pf, &nFormats);

    PIXELFORMATDESCRIPTOR pfd = {};
    DescribePixelFormat(app.hdc, pf, sizeof(pfd), &pfd);

    SetPixelFormat(app.hdc, pf, &pfd);

    const int contextAttribs[] = {
        WGL_CONTEXT_MAJOR_VERSION_ARB, 4,
        WGL_CONTEXT_MINOR_VERSION_ARB, 6,
        WGL_CONTEXT_PROFILE_MASK_ARB, WGL_CONTEXT_CORE_PROFILE_BIT_ARB,
        0
    };

    app.hrc = wglCreateContextAttribsARB(app.hdc, 0, contextAttribs);
    if (!wglMakeCurrent(app.hdc, app.hrc)) {
        return -1;
    }

    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow) {
    if (LoadGLDummyWindowThenKill(hInstance) < 0) {
        std::cerr << "Failed to instantiate OpenGL extensions\n";
        return -1;
    }

    if (LoadActualWindow(hInstance, nCmdShow) < 0) {
        std::cerr << "Failed to create window with modern OpenGL\n";
        return -1;
    }

    rdr.init();

    // main rendering
    MSG msg{};
    while (msg.message != WM_QUIT) {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        } else {
            rdr.render();
        }
    }

    wglMakeCurrent(nullptr, nullptr);
    wglDeleteContext(app.hrc);
    ReleaseDC(app.hwnd, app.hdc);
    DestroyWindow(app.hwnd);
    UnregisterClass(app.CLASS_NAME, hInstance);
    return 0;
}
