#include <iostream>
#include <vector>

#include <glad/gl.h>
#include <glad/wgl.h>

#include <math/vector.h>
#include <entity/mesh.h>

Mesh::Mesh(Geometry _geometry, Material _material): geometry(_geometry), material(_material) {
    
}

void Mesh::draw() {
    geometry.draw();
}