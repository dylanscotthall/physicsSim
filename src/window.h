#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Window
{
public:
    GLFWwindow *window;
    Window();
    Window(const char *title, unsigned int width, unsigned int height);
    ~Window();
    static void framebuffer_size_callback(GLFWwindow *window, int width, int height);

    void renderStart();
    void renderEnd();
    void update();

private:
    unsigned int screenWidth;
    unsigned int screenHeight;
};