#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "window.h"
#include "shader.h"
#include "rect.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "input.h"
#include "userData.h"
#include "physics.h"
#include "scene.h"
#include "imgui.h"
int main()
{
    // my project variables
    Window window = Window("physicsSim", 800, 600);
    Camera camera;
    Physics physics;
    Scene scene;
    Input input;
    IMGUI imgui = IMGUI(window.window);

    UserData *userData = new UserData(&camera);
    glfwSetWindowUserPointer(window.window, userData);
    glEnable(GL_DEPTH_TEST);
    // my app variables
    Shader shader = Shader("../src/vertShader.glsl", "../src/fragShader.glsl");
    Shader lightShader = Shader("../src/lightShaderV.glsl", "../src/lightShader.glsl");
    Rect light = Rect(1.0, 1.0, 1.0, 0.2, 0.2, 0.2);
    Rect rect = Rect(0, 0, 0, 0.7, 0.7, 0.7);
    // Rect rect2 = Rect(0.5f, 0.8f, 0.7, 0.7);
    // Rect leftWall = Rect(-1.0f, 0.0f, 0.1f, 10.0f);
    // Rect rightWall = Rect(1.0f, 0.0f, 0.1f, 10.0f);
    // Rect upWall = Rect(0.0f, -1.0f, 10.0f, 0.1f);
    // Rect downWall = Rect(0.0f, 1.0f, 10.0f, 0.1f);

    // uncomment this call to draw in wireframe polygons.
    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    // render loop
    while (!glfwWindowShouldClose(window.window))
    {
        physics.update();
        scene.update(&camera);
        imgui.renderStart(&rect, physics.deltaTime);
        // input
        input.processInput(window.window, &camera.cameraPos, &camera.cameraFront, &camera.cameraUp, physics.deltaTime);
        // render
        window.renderStart();
        // rect.model = glm::rotate(rect.model, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));
        // draw our first triangle
        rect.update(physics.deltaTime);
        shader.setUniformVec3f("objectColor", glm::vec3(1.0f, 0.5f, 0.31f));
        shader.setUniformVec3f("lightColor", glm::vec3(1.0f, 1.0f, 1.0f));
        shader.setUniformVec3f("lightPos", glm::vec3(1.0f, 1.0f, 1.0f));
        rect.render(&shader, &scene);

        light.render(&lightShader, &scene);
        // rect2.render(&shader, &scene);
        // leftWall.render(&shader, &scene);
        // rightWall.render(&shader, &scene);
        // upWall.render(&shader, &scene);
        // downWall.render(&shader, &scene);
        // glBindVertexArray(0); // no need to unbind it every time

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        imgui.renderEnd();
        window.renderEnd();
    }

    // optional: de-allocate all resources once they've outlived their purpose:
    glDeleteProgram(shader.ID);

    // glfw: terminate, clearing all previously allocated GLFW resources.
    glfwTerminate();
    delete userData;
    return 0;
}
