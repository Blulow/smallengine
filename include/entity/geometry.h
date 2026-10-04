#pragma once

class Geometry {
private:
    std::vector<float> vertices;
public:
    Geometry();

    std::vector<float> getVertices() const;
    void appendVertices(int index, std::vector<float> _vertices);
    void removeVertices(int index, int length);
    void clearVertices();
};