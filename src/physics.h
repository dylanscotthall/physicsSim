#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "gameObject.h"
class Physics
{
public:
    void update()
    {
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
    }
    void checkCollision(std::vector<GameObject *> *gameObjects)
    {
        int count1 = 0, count2 = 0;
        for (size_t i = 0; i < gameObjects->size(); i++)
        {
            for (size_t j = 0; j < gameObjects->size(); j++)
            {
                if (j > i)
                {
                    Rect *rI = (Rect *)(*gameObjects)[i];
                    Rect *rJ = (Rect *)(*gameObjects)[j];
                    //             initial Pos             physics.model translate pos                 //half height
                    if (/*y*/ (rI->physics->posY + rI->physics->model[3][1]) - rI->height / 2 < (rJ->physics->posY + rJ->physics->model[3][1]) + rJ->height / 2 &&
                        (rI->physics->posY + rI->physics->model[3][1]) + rI->height / 2 > (rJ->physics->posY + rJ->physics->model[3][1]) - rJ->height / 2 &&
                        /*x*/ (rI->physics->posX + rI->physics->model[3][0]) - rI->width / 2 < (rJ->physics->posX + rJ->physics->model[3][0]) + rJ->width / 2 &&
                        (rI->physics->posX + rI->physics->model[3][0]) + rI->width / 2 > (rJ->physics->posX + rJ->physics->model[3][0]) - rJ->width / 2 &&
                        /*z*/ (rI->physics->posZ + rI->physics->model[3][2]) - rI->breadth / 2 < (rJ->physics->posZ + rJ->physics->model[3][2]) + rJ->breadth / 2 &&
                        (rI->physics->posZ + rI->physics->model[3][2]) + rI->breadth / 2 > (rJ->physics->posZ + rJ->physics->model[3][2]) - rJ->breadth / 2)
                    {
                        rI->physics->velY = 1;
                        rJ->physics->velY = 1;
                    }
                }
            }
        }
    }

    float deltaTime = 0.0f; // Time between current frame and last frame
    float lastFrame = 0.0f; // Time of last frame
};