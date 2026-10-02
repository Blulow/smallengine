#pragma once

/**
 * Renderer
 * -render() rendering
 * -init() initialize before rendering
 */

class Renderer {
private:
    unsigned int vbo = 0;
    unsigned int vao = 0;
    unsigned int shaderProgram = 0;
public:
    void update(float delta);
    void init();
    void render();
};