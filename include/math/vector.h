#pragma once

struct Vector {
    float x;
    float y;

    Vector() : x(0.0f), y(0.0f) {}
    Vector(float _xy): x(_xy), y(_xy) {}
    Vector(float _x, float _y): x(_x), y(_y) {}

    Vector operator+(const Vector& other) const;
    Vector operator-(const Vector& other) const;
    Vector operator*(const Vector& other) const;
    Vector operator*(const float& other) const;
    Vector operator/(const Vector& other) const;
    Vector operator/(const float& other) const;
    bool operator==(const Vector& other) const;
    bool operator!=(const Vector& other) const;
    Vector operator+() const;
    Vector operator-() const;
};