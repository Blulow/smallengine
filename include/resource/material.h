#pragma once
#include <math/color.h>

class Color;

class Material {
private:
    GLuint shaderProgram = 0;
public:
    Material(Color _albedo = Color(1.0));

    Color albedo;
};