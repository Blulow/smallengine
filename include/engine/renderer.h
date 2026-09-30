#pragma once

/**
 * Renderer
 * -render() rendering
 * -init() initialize before rendering
 * 
 * -keeps track of delta time
 */

class Renderer {
private:
    unsigned int vbo = 0;
    unsigned int vao = 0;
    unsigned int shaderProgram = 0;

    LARGE_INTEGER frequency;
    LARGE_INTEGER lastTime;
    float deltaTime = 0.0f;

    void timeUpdate();
public:
    void update(float delta);
    void init();
    void render();
};

extern Renderer rdr;