#include <windows.h>
#include <vector>
#include <algorithm>
#include <stdexcept>

#include <entity/geometry.h>

Geometry::Geometry() {

}

std::vector<float> Geometry::getVertices() const {
    return vertices;
}

void Geometry::appendVertices(int index, std::vector<float> _vertices) {
    if (index > vertices.size() || index < 0) {
        throw std::runtime_error("Index is out of bounds.");
    }
    vertices.insert(vertices.begin() + index, _vertices.begin(), _vertices.end());
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