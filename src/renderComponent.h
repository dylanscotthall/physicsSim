class RenderComponent
{
public:
    Shader *shader;
    unsigned int VAO, VBO, EBO;
    glm::vec3 color = glm::vec3(0.0f, 0.0f, 0.0f);
};