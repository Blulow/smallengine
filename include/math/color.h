#pragma once

struct Color {
    float r;
    float g;
    float b;
    float a;

    Color(): r(0.0f), g(0.0f), b(0.0f), a(0.0f) {}
    Color(float rgb): r(rgb), g(rgb), b(rgb), a(1.0f) {}
    Color(Color col, float _a): r(col.r), g(col.g), b(col.b), a(_a) {}
    Color(float _r, float _g, float _b): r(_r), g(_g), b(_b), a(1.0f) {}
    Color(float _r, float _g, float _b, float _a): r(_r), g(_g), b(_b), a(_a) {}

    Color operator+(const Color& other);
    Color operator-(const Color& other);
    Color operator*(const Color& other);
    Color operator*(const float& other);
    Color operator/(const Color& other);
    Color operator/(const float& other);
    bool operator==(const Color& other);
    bool operator!=(const Color& other);
    Color operator+();
    Color operator-();
};