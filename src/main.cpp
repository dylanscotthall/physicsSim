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

int main()
{
    // my project variables
    Window window = Window("physicsSim", 800, 600);
    Camera camera;
    Physics physics;
    Scene scene;
    UserData *userData = new UserData(&camera);
    glfwSetWindowUserPointer(window.window, userData);

    // my app variables
    Shader shader = Shader("../src/shader.vertShader", "../src/shader.fragShader");
    Rect rect = Rect(0, 0, 0.7, 0.7);
    Rect rect2 = Rect(0.5f, 0.5f, 0.7, 0.7);

    // uncomment this call to draw in wireframe polygons.
    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    // render loop
    while (!glfwWindowShouldClose(window.window))
    {
        physics.update();
        scene.update(&camera);

        // input
        Input::processInput(window.window, &camera.cameraPos, &camera.cameraFront, &camera.cameraUp, physics.deltaTime);
        // render
        window.renderStart();
        rect.model = glm::rotate(rect.model, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));
        // draw our first triangle
        rect.render(&shader, &scene);
        rect2.render(&shader, &scene);
        // glBindVertexArray(0); // no need to unbind it every time

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        window.renderEnd();
    }

    // optional: de-allocate all resources once they've outlived their purpose:
    glDeleteProgram(shader.ID);

    // glfw: terminate, clearing all previously allocated GLFW resources.
    glfwTerminate();
    delete userData;
    return 0;
}
