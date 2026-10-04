#include <math/vector.h>

Vector Vector::operator+(const Vector& other) const {
    return Vector(x + other.x, y + other.y);
}

Vector Vector::operator-(const Vector& other) const {
    return Vector(x - other.x, y - other.y);
}

Vector Vector::operator*(const Vector& other) const {
    return Vector(x * other.x, y * other.y);
}

Vector Vector::operator*(const float& other) const {
    return Vector(x * other, y * other);
}

Vector Vector::operator/(const Vector& other) const {
    return Vector(x / other.x, y / other.y);
}

Vector Vector::operator/(const float& other) const {
    return Vector(x / other, y / other);
}

bool Vector::operator==(const Vector& other) const {
    return x == other.x && y == other.y;
}

bool Vector::operator!=(const Vector& other) const {
    return x != other.x && y != other.y;
}

Vector Vector::operator+() const {
    return Vector(x, y);
}

Vector Vector::operator-() const {
    return Vector(-x, -y);
}
