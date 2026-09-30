#include <iostream>
#include <windows.h>
#include <glad/gl.h>
#include <glad/wgl.h>
#include <engine/app_properties.h>
#include <engine/renderer.h>

Renderer rdr;

void Renderer::timeUpdate() {
    LARGE_INTEGER currentTime;
    QueryPerformanceCounter(&currentTime);
    deltaTime = (float)(currentTime.QuadPart - lastTime.QuadPart) / (float)frequency.QuadPart;
    lastTime = currentTime;
}

void Renderer::update(float delta) {

}

void Renderer::init() {

}

void Renderer::render() {
    glClearColor(app.WINDOW_BACKGROUND[0], app.WINDOW_BACKGROUND[1], app.WINDOW_BACKGROUND[2], app.WINDOW_BACKGROUND[3]);
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(shaderProgram);

    timeUpdate();

    update(deltaTime);
    glBindVertexArray(vao);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    SwapBuffers(app.hdc);
}