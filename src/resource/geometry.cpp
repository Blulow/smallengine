#include <windows.h>
#include <vector>
#include <algorithm>
#include <stdexcept>

#include <glad/gl.h>
#include <glad/wgl.h>

#include <math/vector.h>
#include <resource/geometry.h>

Geometry::Geometry(const std::vector<Vector>& _vertices): vertices(_vertices) {
    glGenBuffers(1, &vbo);
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, getVerticesFloat().size() * sizeof(float), getVerticesFloat().data(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
}

std::vector<Vector> Geometry::getVertices() const {
    return vertices;
}

std::vector<float> Geometry::getVerticesFloat() const {
    std::vector<float> verticesF = {};
    verticesF.reserve(vertices.size() * 2);

    for (const auto& vertex : vertices) {
        std::vector<float> vertexF = vertex.getArray();
        verticesF.insert(verticesF.end(), vertexF.begin(), vertexF.end());
    }

    return verticesF;
}

void Geometry::appendVertices(int index, std::vector<Vector> _vertices) {
    if (index > vertices.size() || index < 0) {
        throw std::runtime_error("Index is out of bounds.");
    }
    vertices.insert(vertices.begin() + index, _vertices.begin(), _vertices.end());
}

void Geometry::pushVertices(std::vector<Vector> _vertices) {
    vertices.insert(vertices.end(), _vertices.begin(), _vertices.end());
}

void Geometry::removeVertices(int index, int length) {
    if (index > vertices.size() || index < 0) {
        throw std::runtime_error("Range between index and length is out of bounds.");
    }
    if (index + length > vertices.size()) {
        vertices.erase(vertices.begin() + index, vertices.end());
    } else {
        vertices.erase(vertices.begin() + index, vertices.begin() + index + length);
    }
}

void Geometry::clearVertices() {
    vertices.clear();
    vertices.shrink_to_fit();
}

void Geometry::draw() const {
    glBindVertexArray(vao);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}