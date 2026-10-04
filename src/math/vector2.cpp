#include <math/vector2.h>

Vector2 Vector2::operator+(const Vector2& other) const {
    return Vector2(x + other.x, y + other.y);
}

Vector2 Vector2::operator-(const Vector2& other) const {
    return Vector2(x - other.x, y - other.y);
}

Vector2 Vector2::operator*(const Vector2& other) const {
    return Vector2(x * other.x, y * other.y);
}

Vector2 Vector2::operator*(const float other) const {
    return Vector2(x * other, y * other);
}

Vector2 Vector2::operator/(const Vector2& other) const {
    return Vector2(x / other.x, y / other.y);
}

Vector2 Vector2::operator/(const float other) const {
    return Vector2(x / other, y / other);
}

bool Vector2::operator==(const Vector2& other) const {
    return x == other.x && y == other.y;
}

Vector2 Vector2::operator+() const {
    return Vector2(x, y);
}

Vector2 Vector2::operator-() const {
    return Vector2(-x, -y);
}
