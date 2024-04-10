#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
class Physics
{
public:
    void update()
    {
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
    }

    float deltaTime = 0.0f; // Time between current frame and last frame
    float lastFrame = 0.0f; // Time of last frame
};