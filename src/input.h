#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "userData.h"

class Input
{
public:
    bool mouseCapture = true;
    void processInput(GLFWwindow *window, glm::vec3 *cameraPos, glm::vec3 *cameraFront, glm::vec3 *cameraUp, float deltaTime)
    {
        const float cameraSpeed = 2.5f * deltaTime; // adjust accordingly
        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
            *cameraPos += cameraSpeed * (*cameraFront);
        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
            *cameraPos -= cameraSpeed * (*cameraFront);
        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
            *cameraPos -= glm::normalize(glm::cross((*cameraFront), (*cameraUp))) * cameraSpeed;
        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
            *cameraPos += glm::normalize(glm::cross((*cameraFront), (*cameraUp))) * cameraSpeed;
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);
        if (glfwGetKey(window, GLFW_KEY_LEFT_ALT) == GLFW_PRESS)
        {
            mouseCapture = !mouseCapture;
            if (mouseCapture)
                glfwSetCursorPosCallback(window, mouse_callback);
            else
                glfwSetCursorPosCallback(window, mouse_callback);
        }
    }
    static void mouse_callback(GLFWwindow *window, double xpos, double ypos)
    {
        Camera *camera = UserData::getCamera(window);
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