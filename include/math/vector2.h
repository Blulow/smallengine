#pragma once

struct Vector2 {
    float x;
    float y;

    Vector2() : x(0.0f), y(0.0f) {}
    Vector2(float _xy): x(_xy), y(_xy) {}
    Vector2(float _x, float _y): x(_x), y(_y) {}

    Vector2 operator+(const Vector2& other) const;
    Vector2 operator-(const Vector2& other) const;
    Vector2 operator*(const Vector2& other) const;
    Vector2 operator*(const float other) const;
    Vector2 operator/(const Vector2& other) const;
    Vector2 operator/(const float other) const;
    bool operator==(const Vector2& other) const;
    Vector2 operator+() const;
    Vector2 operator-() const;
};