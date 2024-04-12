#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader
{
public:
    unsigned int ID;
    Shader(const char *vertexPath, const char *fragmentPath);
    ~Shader();
    void use() const;
    void setUniformMatrix4fv(const char *name, glm::mat4 uniform);
    void setUniformVec3f(const char *name, glm::vec3 uniform);
    void setUniformf(const char *name, float uniform);

private:
    void checkCompileErrors(GLuint shader, std::string type);
};