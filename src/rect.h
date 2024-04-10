#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "scene.h"
#include "shader.h"
class Rect
{
public:
    unsigned int VAO, VBO, EBO;
    glm::mat4 model;
    Rect(float posX, float posY, float width, float height);
    ~Rect();
    void render(Shader *shader, Scene *scene);
    void update();

private:
    float posX, posY, width, height;
};