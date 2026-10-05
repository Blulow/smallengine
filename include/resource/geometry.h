#pragma once

class Vector;

class Geometry {
private:
    GLuint vbo = 0;
    GLuint vao = 0;

    std::vector<Vector> vertices;
public:
    Geometry(const std::vector<Vector>& vertices = {});

    std::vector<Vector> getVertices() const;
    std::vector<float> getVerticesFloat() const;
    void appendVertices(int index, std::vector<Vector> _vertices);
    void pushVertices(std::vector<Vector> _vertices);
    void removeVertices(int index, int length);
    void clearVertices();
    
    void draw() const;
};