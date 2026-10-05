#include <glad/gl.h>
#include <glad/wgl.h>

#include <resource/material.h>

Material::Material(Color _albedo): albedo(_albedo) {
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