class PhysicsComponent
{
public:
    bool physicsEnabled = false;
    float velX = 0, velY = 0, velZ = 0;
    float posX, posY, posZ;
    glm::mat4 model;
};