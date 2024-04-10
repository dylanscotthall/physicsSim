#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "camera.h"
class Scene
{
public:
    Scene();
    void update(Camera *camera);
    glm::mat4 view;
    glm::mat4 projection;
};