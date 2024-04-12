#pragma once
#include "physicsComponent.h"
#include "renderComponent.h"
#include "scene.h"
#include "camera.h"
class GameObject
{
public:
    PhysicsComponent *physics;
    RenderComponent *renderer;

    virtual ~GameObject()
    {
        delete physics;
        delete renderer;
    };
    GameObject()
    {
        physics = new PhysicsComponent();
        renderer = new RenderComponent();
    };
    virtual void render(Scene *scene, Camera *camera) = 0;
    virtual void update(float deltaTime) = 0;
};