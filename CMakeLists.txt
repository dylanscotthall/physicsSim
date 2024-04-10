cmake_minimum_required(VERSION 3.20)
project(projectSim)

set(CMAKE_CXX_STANDARD 14)
set(CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_FLAGS "-std=c++14")
set(CMAKE_CPP_COMPILER g++)

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libs)
 
# set(SOURCES
#  ${SRC_DIR}/main.cpp
#  ${SRC_DIR}/main.h 
# )
file(GLOB SOURCES "${SRC_DIR}/*.cpp")
file(GLOB HEADERS "${SRC_DIR}/*.h")

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# OpenGL
find_package( OpenGL REQUIRED )
include_directories(${OPENGL_INCLUDE_DIRS})

# GLAD
add_library(glad STATIC ${LIB_DIR}/glad/src/glad.c)
target_include_directories(glad PRIVATE ${LIB_DIR}/glad/include)

#GLFW
set(GLFW_DIR ${LIB_DIR}/glfw)
set(GLFW_BUILD_EXAMPLES OFF CACHE INTERNAL "Build the GLFW example programs")
set(GLFW_BUILD_TESTS OFF CACHE INTERNAL "Build the GLFW test programs")
set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "Build the GLFW documentation")
set(GLFW_INSTALL OFF CACHE INTERNAL "Generate installation target")

set(GLM_DIR ${LIB_DIR}/glm)
include_directories(${GLM_DIR})

set (STB_DIR ${LIB_DIR}/stb)
include_directories(${STB_DIR})

add_subdirectory(${GLFW_DIR} "glfw-binaries")

set(IMGUI_DIR "${LIB_DIR}/imgui")

add_library("imgui" "${IMGUI_DIR}/imgui.cpp"
                  "${IMGUI_DIR}/imgui_demo.cpp"
                  "${IMGUI_DIR}/imgui_draw.cpp"
                  "${IMGUI_DIR}/imgui_tables.cpp"
                  "${IMGUI_DIR}/imgui_widgets.cpp"
                  
                  "${IMGUI_DIR}/imgui_impl_glfw.cpp"
                  "${IMGUI_DIR}/imgui_impl_opengl3.cpp")

target_include_directories("imgui" PRIVATE "${IMGUI_DIR}")
target_include_directories(${PROJECT_NAME} PRIVATE "${IMGUI_DIR}")
target_link_libraries(${PROJECT_NAME} "imgui" "${CMAKE_DL_LIBS}")
target_link_libraries(imgui PUBLIC glfw)

#add_library(${PROJECT_NAME} STATIC ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${SRC_DIR})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(${PROJECT_NAME} PUBLIC ${GLFW_DIR}/include)
target_include_directories(${PROJECT_NAME} PUBLIC ${LIB_DIR}/glad/include)
target_compile_definitions(${PROJECT_NAME} PRIVATE GLFW_INCLUDE_NONE)
target_include_directories(${PROJECT_NAME} PUBLIC ${LIB_DIR}/glm)
# target_include_directories(${PROJECT_NAME} PUBLIC ${IMGUI_DIR}) # and here...

if(UNIX AND NOT APPLE)
    target_link_libraries(${PROJECT_NAME} pthread)
    elseif(WIN32)
    target_link_libraries(${PROJECT_NAME} glad glfw)
endif()
