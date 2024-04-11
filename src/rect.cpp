#include "rect.h"
#include <glm/glm.hpp>

Rect::Rect(float posX, float posY, float posZ, float width, float height, float breadth) : posX(posX), posY(posY), posZ(posZ), width(width), height(height), breadth(breadth)
{
    model = glm::mat4(1.0f);
    float vertices[] = {
        // triangles
        // front 1
        posX + (width / 2), posY + (height / 2), posZ + (breadth / 2), 0.0f, 0.0f, 1.0f,
        posX + (width / 2), posY - (height / 2), posZ + (breadth / 2), 0.0f, 0.0f, 1.0f,
        posX - (width / 2), posY + (height / 2), posZ + (breadth / 2), 0.0f, 0.0f, 1.0f,
        // front 2
        posX + (width / 2), posY - (height / 2), posZ + (breadth / 2), 0.0f, 0.0f, 1.0f,
        posX - (width / 2), posY - (height / 2), posZ + (breadth / 2), 0.0f, 0.0f, 1.0f,
        posX - (width / 2), posY + (height / 2), posZ + (breadth / 2), 0.0f, 0.0f, 1.0f,
        // back 1
        posX + (width / 2), posY + (height / 2), posZ - (breadth / 2), 0.0f, 0.0f, -1.0f,
        posX + (width / 2), posY - (height / 2), posZ - (breadth / 2), 0.0f, 0.0f, -1.0f,
        posX - (width / 2), posY + (height / 2), posZ - (breadth / 2), 0.0f, 0.0f, -1.0f,
        // back 2
        posX + (width / 2), posY - (height / 2), posZ - (breadth / 2), 0.0f, 0.0f, -1.0f,
        posX - (width / 2), posY - (height / 2), posZ - (breadth / 2), 0.0f, 0.0f, -1.0f,
        posX - (width / 2), posY + (height / 2), posZ - (breadth / 2), 0.0f, 0.0f, -1.0f,
        // top 1
        posX + (width / 2), posY + (height / 2), posZ + (breadth / 2), 0.0f, 1.0f, 0.0f,
        posX - (width / 2), posY + (height / 2), posZ + (breadth / 2), 0.0f, 1.0f, 0.0f,
        posX - (width / 2), posY + (height / 2), posZ - (breadth / 2), 0.0f, 1.0f, 0.0f,
        // top 2
        posX + (width / 2), posY + (height / 2), posZ - (breadth / 2), 0.0f, 1.0f, 0.0f,
        posX - (width / 2), posY + (height / 2), posZ - (breadth / 2), 0.0f, 1.0f, 0.0f,
        posX + (width / 2), posY + (height / 2), posZ + (breadth / 2), 0.0f, 1.0f, 0.0f,
        // bottom 1
        posX + (width / 2), posY - (height / 2), posZ + (breadth / 2), 0.0f, -1.0f, 0.0f,
        posX - (width / 2), posY - (height / 2), posZ + (breadth / 2), 0.0f, -1.0f, 0.0f,
        posX - (width / 2), posY - (height / 2), posZ - (breadth / 2), 0.0f, -1.0f, 0.0f,
        // bottom 2
        posX + (width / 2), posY - (height / 2), posZ - (breadth / 2), 0.0f, -1.0f, 0.0f,
        posX + (width / 2), posY - (height / 2), posZ + (breadth / 2), 0.0f, -1.0f, 0.0f,
        posX - (width / 2), posY - (height / 2), posZ - (breadth / 2), 0.0f, -1.0f, 0.0f,
        // left 1
        posX - (width / 2), posY + (height / 2), posZ + (breadth / 2), -1.0f, 0.0f, 0.0f,
        posX - (width / 2), posY - (height / 2), posZ + (breadth / 2), -1.0f, 0.0f, 0.0f,
        posX - (width / 2), posY + (height / 2), posZ - (breadth / 2), -1.0f, 0.0f, 0.0f,
        // left 2
        posX - (width / 2), posY - (height / 2), posZ - (breadth / 2), -1.0f, 0.0f, 0.0f,
        posX - (width / 2), posY - (height / 2), posZ + (breadth / 2), -1.0f, 0.0f, 0.0f,
        posX - (width / 2), posY + (height / 2), posZ - (breadth / 2), -1.0f, 0.0f, 0.0f,
        // right 1
        posX + (width / 2), posY - (height / 2), posZ - (breadth / 2), 1.0f, 0.0f, 0.0f,
        posX + (width / 2), posY - (height / 2), posZ + (breadth / 2), 1.0f, 0.0f, 0.0f,
        posX + (width / 2), posY + (height / 2), posZ - (breadth / 2), 1.0f, 0.0f, 0.0f,
        // right 2
        posX + (width / 2), posY + (height / 2), posZ + (breadth / 2), 1.0f, 0.0f, 0.0f,
        posX + (width / 2), posY - (height / 2), posZ + (breadth / 2), 1.0f, 0.0f, 0.0f,
        posX + (width / 2), posY + (height / 2), posZ - (breadth / 2), 1.0f, 0.0f, 0.0f

        // posX + (width / 2), posY + (height / 2), posZ + (breadth / 2), 0.0f, 0.0f, -1.0f,   // top right front
        // posX + (width / 2), posY - (height / 2), posZ + (breadth / 2), 0.0f, 0.0f, -1.0f,   // bottom right front
        // posX - (width / 2), posY - (height / 2), posZ + (breadth / 2), -0.0f, 0.0f, -1.0f,  // bottom left front
        // posX - (width / 2), posY + (height / 2), posZ + (breadth / 2), -0.0f, -0.0f, -1.0f, // top left front
        // posX + (width / 2), posY + (height / 2), posZ - (breadth / 2), 0.0f, -0.0f, 0.0f,   // top right back
        // posX + (width / 2), posY - (height / 2), posZ - (breadth / 2), 0.0f, 0.0f, -0.0f,   // bottom right back
        // posX - (width / 2), posY - (height / 2), posZ - (breadth / 2), -0.0f, 0.0f, 0.0f,   // bottom left back
        // posX - (width / 2), posY + (height / 2), posZ - (breadth / 2), -0.0f, -0.0f, 0.0f   // top left back
    };
    unsigned int indices[] = {
        0, 1, 2,    // front 1
        3, 4, 5,    // front 2
        6, 7, 8,    // back 1
        9, 10, 11,  // back 2
        12, 13, 14, // top 1
        15, 16, 17, // top 2
        18, 19, 20, // bottom 1
        21, 22, 23, // bottom 2
        24, 25, 26, // left 1
        27, 28, 29, // left 2
        30, 31, 32, // right 1
        33, 34, 35  // right 2

    }; // unsigned int indices[] = {
       //     // note that we start from 0!
       //     0, 1, 3, // front first Triangle
       //     1, 2, 3, // front second Triangle
       //     4, 5, 7, // back first Triangle
       //     5, 6, 7, // back second Triangle
       //     0, 3, 7, // top first triangle
       //     4, 7, 0, // top second triangle
       //     2, 1, 6, // bottom first triangle
       //     5, 1, 6, // botoom second triangle
       //     3, 2, 7, // left first triangle
       //     6, 2, 7, // left second triangle
       //     5, 1, 4, // right first triangle
       //     0, 1, 4  // right second triangle
       // };
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // remember: do NOT unbind the EBO while a VAO is active as the bound element buffer object IS stored in the VAO; keep the EBO bound.
    // glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    glBindVertexArray(0);
}
Rect::~Rect()
{
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
}

void Rect::render(Shader *shader, Scene *scene)
{
    shader->setUniformMatrix4fv("model", model);
    shader->setUniformMatrix4fv("view", scene->view);
    shader->setUniformMatrix4fv("projection", scene->projection);
    glUseProgram(shader->ID);
    glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
    // glDrawArrays(GL_TRIANGLES, 0, 6);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
}
void Rect::update(float deltaTime)
{
    // model = glm::translate(model, glm::vec3(0.0f, 0.2f * deltaTime, 0.0f));
}