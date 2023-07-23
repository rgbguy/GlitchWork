#pragma once
#include <GLFW/glfw3.h>
#include <iostream>
#include<glad/glad.h>

namespace Gx {
    class Window {
    public:
        Window(int width, int height, const char* title) : width(width), height(height), title(title) {
            if (!glfwInit()) {
                std::cerr << "Failed to initialize GLFW" << std::endl;
                std::exit(EXIT_FAILURE);
            }

            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

            window = glfwCreateWindow(width, height, title, nullptr, nullptr);

            if (!window) {
                std::cerr << "Failed to create GLFW window" << std::endl;
                glfwTerminate();
                std::exit(EXIT_FAILURE);
            }

            glfwMakeContextCurrent(window);
            glfwSetWindowUserPointer(window, this);

            glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);
            glfwSetKeyCallback(window, keyCallback);

            // Initialize OpenGL or other libraries here
            gladLoadGL();
        }

        ~Window() {
            glfwDestroyWindow(window);
            glfwTerminate();
        }

        bool shouldClose() {
            return glfwWindowShouldClose(window);
        }

        void update() {
            glfwSwapBuffers(window);
            glfwPollEvents();
        }

        void setTitle(const char* newTitle) {
            glfwSetWindowTitle(window, newTitle);
        }

        static void framebufferSizeCallback(GLFWwindow* window, int width, int height) {
            glViewport(0, 0, width, height);
        }

        static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
            Window* instance = static_cast<Window*>(glfwGetWindowUserPointer(window));

            if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
                glfwSetWindowShouldClose(window, true);
            }
        }

    private:
        GLFWwindow* window;
        int width;
        int height;
        const char* title;
    };
}