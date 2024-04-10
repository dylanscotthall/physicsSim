#include "scene.h"
Scene::Scene()
{
    view = glm::lookAt(glm::vec3(0.0f, 0.0f, 3.0f),
                       glm::vec3(0.0f, 0.0f, 0.0f),
                       glm::vec3(0.0f, 1.0f, 0.0f));
    projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
}

void Scene::update(Camera *camera)
{
    view = glm::lookAt(camera->cameraPos, camera->cameraPos + camera->cameraFront, camera->cameraUp);
    projection = glm::perspective(glm::radians(camera->fov), 800.0f / 600.0f, 0.1f, 100.0f);
}