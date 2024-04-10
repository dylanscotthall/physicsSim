#pragma once
#include "camera.h"
#include <GLFW/glfw3.h>

struct UserData
{
    Camera *camera;

    // Constructor to initialize the camera pointer
    UserData(Camera *cam) : camera(cam)
    {
    }

    // Static function to retrieve the Camera object associated with a GLFW window
    static Camera *getCamera(GLFWwindow *window)
    {
        UserData *userData = static_cast<UserData *>(glfwGetWindowUserPointer(window));
        return userData ? userData->camera : nullptr;
    }
};
