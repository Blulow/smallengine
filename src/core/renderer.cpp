#include <iostream>
#include <windows.h>
#include <array>

#include <glad/gl.h>
#include <glad/wgl.h>

#include <core/app_properties.h>
#include <core/time.h>
#include <core/renderer.h>

void Renderer::update(float deltaTime) {
    std::cout << deltaTime << "\n";
}

void Renderer::init() {

}

void Renderer::render() {
    glClearColor(G_APPPROP.getWindowBackgroundColor()[0],
        G_APPPROP.getWindowBackgroundColor()[1],
        G_APPPROP.getWindowBackgroundColor()[2],
        G_APPPROP.getWindowBackgroundColor()[3]);
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(shaderProgram);

    G_TIME.timeUpdate();

    update(G_TIME.getDeltaTime());
    glBindVertexArray(vao);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    SwapBuffers(G_APPPROP.getHDC());
}