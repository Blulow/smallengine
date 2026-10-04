#include <vector>

#include <math/vector.h>

Vector Vector::operator+(const Vector& other) const {
    return Vector(x + other.x, y + other.y, z + other.z);
}

Vector Vector::operator-(const Vector& other) const {
    return Vector(x - other.x, y - other.y, z - other.z);
}

Vector Vector::operator*(const Vector& other) const {
    return Vector(x * other.x, y * other.y, z * other.z);
}

Vector Vector::operator*(const float& other) const {
    return Vector(x * other, y * other, z * other);
}

Vector Vector::operator/(const Vector& other) const {
    return Vector(x / other.x, y / other.y, z / other.z);
}

Vector Vector::operator/(const float& other) const {
    return Vector(x / other, y / other, z / other);
}

bool Vector::operator==(const Vector& other) const {
    return x == other.x && y == other.y && z == other.z;
}

bool Vector::operator!=(const Vector& other) const {
    return x != other.x && y != other.y && z != other.z;
}

Vector Vector::operator+() const {
    return Vector(x, y, z);
}

Vector Vector::operator-() const {
    return Vector(-x, -y, -z);
}

std::vector<float> Vector::getArray() const {
    return {x, y, z};
}
