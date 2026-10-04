#pragma once

struct Vector {
    float x;
    float y;
    float z;

    Vector() : x(0.0f), y(0.0f), z(0.0f) {}
    Vector(float _xyz): x(_xyz), y(_xyz), z(_xyz) {}
    Vector(float _x, float _y, float _z): x(_x), y(_y), z(_z) {}

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

    std::vector<float> getArray() const;
};