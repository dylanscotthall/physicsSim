#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "userData.h"
#include "camera.h"
#include "rect.h"
#include <iostream>

class Input
{
public:
    static void processInput(GLFWwindow *window, Camera *camera, Rect *rect, float deltaTime)
    {
        const float cameraSpeed = 2.5f * deltaTime; // adjust accordingly
        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
            camera->cameraPos += cameraSpeed * (camera->cameraFront);
        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
            camera->cameraPos -= cameraSpeed * (camera->cameraFront);
        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
            camera->cameraPos -= glm::normalize(glm::cross((camera->cameraFront), (camera->cameraUp))) * cameraSpeed;
        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
            camera->cameraPos += glm::normalize(glm::cross((camera->cameraFront), (camera->cameraUp))) * cameraSpeed;
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);
        if (glfwGetKey(window, GLFW_KEY_M) == GLFW_PRESS)
        {
            if (camera->cameraMovable)
            {
                std::cout << "camera move true" << std::endl;
                camera->cameraMovable = false;
                glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
            }
            else
            {
                std::cout << "camera move false" << std::endl;
                camera->cameraMovable = true;
                glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
            }
        }
    }
    static void mouse_callback(GLFWwindow *window, double xpos, double ypos)
    {
        Camera *camera = UserData::getCamera(window);
        if (camera->cameraMovable)
        {
            if (camera->firstMouse)
            {
                camera->lastX = xpos;
                camera->lastY = ypos;
                camera->firstMouse = false;
            }

            float xoffset = xpos - camera->lastX;
            float yoffset = camera->lastY - ypos;
            camera->lastX = xpos;
            camera->lastY = ypos;

            float sensitivity = 0.1f;
            xoffset *= sensitivity;
            yoffset *= sensitivity;

            camera->yaw += xoffset;
            camera->pitch += yoffset;

            if (camera->pitch > 89.0f)
                camera->pitch = 89.0f;
            if (camera->pitch < -89.0f)
                camera->pitch = -89.0f;

            glm::vec3 direction;
            direction.x = cos(glm::radians(camera->yaw)) * cos(glm::radians(camera->pitch));
            direction.y = sin(glm::radians(camera->pitch));
            direction.z = sin(glm::radians(camera->yaw)) * cos(glm::radians(camera->pitch));
            camera->cameraFront = glm::normalize(direction);
        }
    }
    static void scroll_callback(GLFWwindow *window, double xoffset, double yoffset)
    {
        Camera *camera = UserData::getCamera(window);

        camera->fov -= (float)yoffset;
        if (camera->fov < 1.0f)
            camera->fov = 1.0f;
        if (camera->fov > 45.0f)
            camera->fov = 45.0f;
    }
};