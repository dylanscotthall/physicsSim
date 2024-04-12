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
        ImGui_ImplOpenGL3_Init("#version 430");
    }
    void renderStart(Rect *rect, float deltaTime)
    {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        {
            ImGui::Begin("Toolkit");
            ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / io->Framerate, io->Framerate);

            ImGui::PushButtonRepeat(true);
            ImGui::Text("X");
            bool moveX = false, moveY = false, moveZ = false;
            if (ImGui::ArrowButton("##LEFT", ImGuiDir_Left))
            {
                moveX = true;
                rect->physics->velX = -100.0f;
            }
            ImGui::SameLine(0.0f, 5);
            if (ImGui::ArrowButton("##RIGHT", ImGuiDir_Right))
            {
                moveX = true;
                rect->physics->velX = 100.0f;
            }
            if (!moveX)
            {
                rect->physics->velX = 0.0f;
            }
            ImGui::Text("Y");
            if (ImGui::ArrowButton("##UP", ImGuiDir_Up))
            {
                moveY = true;
                rect->physics->velY = 100.0f;
            }
            ImGui::SameLine(0.0f, 5);
            if (ImGui::ArrowButton("##DOWN", ImGuiDir_Down))
            {
                moveY = true;
                rect->physics->velY = -100.0f;
            }
            if (!moveY)
            {
                rect->physics->velY = 0.0f;
            }
            ImGui::Text("Z");
            if (ImGui::ArrowButton("##LEFT", ImGuiDir_Left))
            {
                moveZ = true;
                rect->physics->velZ = -100.0f;
            }
            ImGui::SameLine(0.0f, 5);
            if (ImGui::ArrowButton("##RIGHT", ImGuiDir_Right))
            {
                moveZ = true;
                rect->physics->velZ = 100.0f;
            }
            if (!moveZ)
            {
                rect->physics->velZ = 0.0f;
            }
            ImGui::PopButtonRepeat();
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