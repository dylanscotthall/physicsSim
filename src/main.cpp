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
#include "gameObject.h"

int main()
{
    // my project variables
    Window window = Window("physicsSim", 800, 600);
    Camera camera;
    Physics physics;
    Scene scene;
    IMGUI imgui = IMGUI(window.window);

    UserData *userData = new UserData(&camera);
    glfwSetWindowUserPointer(window.window, userData);
    glEnable(GL_DEPTH_TEST);
    // my app variables
    Shader shader = Shader("../src/vertShader.glsl", "../src/fragShader.glsl");
    Shader lightShader = Shader("../src/lightShaderV.glsl", "../src/lightShader.glsl");
    Rect light = Rect(1.0, 0.0, 4.0, 0.2, 0.2, 0.2);
    light.renderer->shader = &lightShader;

    Rect rect = Rect(0.0f, 0.4, 0, 1, 1, 1);
    rect.renderer->color = glm::vec3(5.0f, 0.0f, 0.0f);
    rect.renderer->shader = &shader;
    rect.physics->physicsEnabled = true;
    Rect rect2 = Rect(0.0f, -5.0f, 0.0f, 5.0, 0.2, 5.0);
    rect2.renderer->color = glm::vec3(0.0f, 1.0f, 0.0f);
    rect2.renderer->shader = &shader;

    std::vector<GameObject *> gameObjects;
    gameObjects.push_back(&light);
    gameObjects.push_back(&rect);
    gameObjects.push_back(&rect2);
    for (size_t i = 0; i < 5; i++)
    {
        Rect *r = new Rect(-3.0f, -(float)i + 1, 0.0f, 0.5f, 0.5f, 0.5f);
        r->renderer->color = glm::vec3(0.0f, 0.0f, 1.0f);
        r->renderer->shader = &shader;
        gameObjects.push_back(r);
    }
    // uncomment this call to draw in wireframe polygons.
    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    // render loop
    while (!glfwWindowShouldClose(window.window))
    {
        physics.update();
        scene.update(&camera);
        imgui.renderStart(&light, physics.deltaTime);
        // input
        Input::processInput(window.window, &camera, &light, physics.deltaTime);
        // render
        window.renderStart();
        // draw our first triangle

        physics.checkCollision(&gameObjects);
        for (auto &&i : gameObjects)
        {
            i->update(physics.deltaTime);
            i->render(&scene, &camera);
        }

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        imgui.renderEnd();
        window.renderEnd();
    }
    for (GameObject *g : gameObjects)
    {
        delete g;
    }
    // glfw: terminate, clearing all previously allocated GLFW resources.
    glfwTerminate();
    delete userData;
    return 0;
}
