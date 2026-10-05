#include <iostream>
#include <vector>

#include <glad/gl.h>
#include <glad/wgl.h>

#include <math/vector.h>
#include <entity/mesh.h>

Mesh::Mesh(Geometry _geometry, Material _material): geometry(_geometry), material(_material) {
    init();
}

void Mesh::init() {
    glGenBuffers(1, &vbo);
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, geometry.getVerticesFloat().size() * sizeof(float), geometry.getVerticesFloat().data(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    GLuint vs = glCreateShader(GL_VERTEX_SHADER);
    const char* vsrc = R"(
        #version 410 core\n
        in vec3 pos;\n
        void main() {\n
            gl_Position = vec4(pos.x, pos.y, pos.z, 1.0);\n
        }
        )";
    glShaderSource(vs, 1, &vsrc, nullptr);
    glCompileShader(vs);

    GLuint fs = glCreateShader(GL_VERTEX_SHADER);
    const char* fsrc = R"(
        #version 410 core\n
        out vec4 frag_color;\n
        void main() {\n
            frag_color = vec4(57.0 / 255.0, 169.0 / 255.0, 1.0, 1.0);\n
        }
        )";
    glShaderSource(fs, 1, &fsrc, nullptr);
    glCompileShader(fs);

    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vs);
    glAttachShader(shaderProgram, fs);
    glLinkProgram(shaderProgram);
}

void Mesh::draw() {
    glBindVertexArray(vao);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}