#pragma once
#include <resource/geometry.h>
#include <resource/material.h>

class Mesh {
private:
    Geometry geometry;
    Material material;

    GLuint vbo = 0;
    GLuint vao = 0;
    GLuint shaderProgram = 0;

    void init();
public:
    Mesh(Geometry _geometry, Material _material);

    void draw();
};