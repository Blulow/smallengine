#pragma once

class Geometry {
private:
    std::vector<Vector> vertices;
public:
    Geometry();

    std::vector<Vector> getVertices() const;
    void appendVertices(int index, std::vector<Vector> _vertices);
    void removeVertices(int index, int length);
    void clearVertices();
};