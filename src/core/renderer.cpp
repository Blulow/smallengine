#include <iostream>
#include <windows.h>
#include <array>
#include <vector>
#include <optional>

#include <glad/gl.h>
#include <glad/wgl.h>

#include <core/app_properties.h>
#include <core/time.h>
#include <entity/mesh.h>
#include <resource/geometry.h>
#include <resource/material.h>
#include <math/vector.h>
#include <math/color.h>
#include <core/renderer.h>

std::vector<Vector> vertices = {
    Vector(-0.5f, -0.5f, 0.0f),
    Vector(0.5f, -0.5f, 0.0f),
    Vector(0.0f, 0.5f, 0.0f)
};

std::optional<Mesh> mesh;

void Renderer::update(float deltaTime) {
    mesh->draw();
}

void Renderer::init() {
    Geometry geometry(vertices);
    Material material(Color(1.0, 0.0, 0.0, 1.0));
    mesh = Mesh(geometry, material);
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

    SwapBuffers(G_APPPROP.getHDC());
}