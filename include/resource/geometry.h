#pragma once

class Geometry {
private:
    std::vector<Vector> vertices;
public:
    Geometry();

    std::vector<Vector> getVertices() const;
    std::vector<float> getVerticesFloat() const;
    void appendVertices(int index, std::vector<Vector> _vertices);
    void pushVertices(std::vector<Vector> _vertices);
    void removeVertices(int index, int length);
    void clearVertices();
};