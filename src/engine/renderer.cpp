#include <iostream>
#include <windows.h>
#include <glad/gl.h>
#include <glad/wgl.h>
#include <smallengine/engine/app_properties.h>

AppProperties app;

/**
 * Renderer
 * -render() rendering
 * -init() initialize before rendering
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

    void timeUpdate() {
        LARGE_INTEGER currentTime;
        QueryPerformanceCounter(&currentTime);
        deltaTime = (float)(currentTime.QuadPart - lastTime.QuadPart) / (float)frequency.QuadPart;
        lastTime = currentTime;
    }

public:
    void update(float delta) {

    }

    void init() {

    }

    void render() {
        glClearColor(app.WINDOW_BACKGROUND[0], app.WINDOW_BACKGROUND[1], app.WINDOW_BACKGROUND[2], app.WINDOW_BACKGROUND[3]);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shaderProgram);

        timeUpdate();

        update(deltaTime);
        glBindVertexArray(vao);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        SwapBuffers(app.hdc);
    }
};