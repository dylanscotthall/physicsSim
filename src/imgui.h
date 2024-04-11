#pragma once
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <iostream>
#include "rect.h"
class IMGUI
{
public:
    IMGUI(GLFWwindow *window)
    {
        // Setup Dear ImGui context
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        io = &ImGui::GetIO();
        io->ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; // Enable Keyboard Controls
        io->ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;  // Enable Gamepad Controls

        // Setup Dear ImGui style
        ImGui::StyleColorsDark();
        // ImGui::StyleColorsLight();

        // Setup Platform/Renderer backends
        ImGui_ImplGlfw_InitForOpenGL(window, true);
        ImGui_ImplOpenGL3_Init("#version 330");
        std::cout << "Test" << std::endl;
    }
    void renderStart(Rect *rect, float deltaTime)
    {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        float t;
        {
            ImGui::Begin("Toolkit");
            // ImGui::PushButtonRepeat(true);
            ImGui::SliderFloat3("translation", &t, -1.0f, 1.0f);
            // ImGui::SliderFloat3("translationB", &translationB.x, -1.0f, 1.0f);
            if (ImGui::ArrowButton("##Up", ImGuiDir_Up))
            {
                rect->model = glm::translate(rect->model, glm::vec3(0.0f, 10.0f * deltaTime, 0.0f));
            }
            ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / io->Framerate, io->Framerate);
            ImGui::End();
        }
        // rect->model = glm::translate(rect->model, glm::vec3(0.0f, 0.0f, 0.0f));
    }
    void renderEnd()
    {
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }
    ~IMGUI()
    {
        ImGui_ImplOpenGL3_Shutdown();
        ImGui::DestroyContext();
    }

private:
    ImGuiIO *io;
};