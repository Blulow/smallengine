#include <math/color.h>

Color Color::operator+(const Color& other) {
    return Color(r + other.r, g + other.g, b + other.b, a + other.a);
}

Color Color::operator-(const Color& other) {
    return Color(r - other.r, g - other.g, b - other.b, a - other.a);
}

Color Color::operator*(const Color& other) {
    return Color(r * other.r, g * other.g, b * other.b, a * other.a);
}

Color Color::operator*(const float& other) {
    return Color(r * other, g * other, b * other, a * other);
}

Color Color::operator/(const Color& other) {
    return Color(r / other.r, g / other.g, b / other.b, a / other.a);
}

Color Color::operator/(const float& other) {
    return Color(r / other, g / other, b / other, a / other);
}

bool Color::operator==(const Color& other) {
    return r == other.r && g == other.g && b == other.b && a == other.a;
}

bool Color::operator!=(const Color& other) {
    return r != other.r && g != other.g && b != other.b && a != other.a;
}

Color Color::operator+() {
    return Color(r, g, b, a);
}

Color Color::operator-() {
    return Color(-r, -g, -b, -a);
}
