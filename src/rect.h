#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "scene.h"
#include "shader.h"
#include "gameObject.h"

class Rect : public GameObject
{
public:
    float width, height, breadth;
    Rect(float posX, float posY, float posZ, float width, float height, float breadth);
    ~Rect();
    void render(Scene *scene, Camera *camera) override;
    void update(float deltaTime) override;

private:
};