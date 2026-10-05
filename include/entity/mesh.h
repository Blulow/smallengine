#pragma once
#include <resource/geometry.h>
#include <resource/material.h>

class Mesh {
private:
    Geometry geometry;
    Material material;
public:
    Mesh(Geometry _geometry, Material _material);

    void draw();
};