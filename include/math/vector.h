#pragma once

struct Vector {
    float x;
    float y;

    () : x(0.0f), y(0.0f) {}
    (float _xy): x(_xy), y(_xy) {}
    (float _x, float _y): x(_x), y(_y) {}

     operator+(const & other) const;
     operator-(const & other) const;
     operator*(const & other) const;
     operator*(const float other) const;
     operator/(const & other) const;
     operator/(const float other) const;
    bool operator==(const & other) const;
     operator+() const;
     operator-() const;
};