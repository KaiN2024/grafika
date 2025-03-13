
#define GLEW_DLL
#define GLF_DLL

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>


// Функция изменения размеров окна
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

int main() {
    // Инициализация GLFW
    if (!glfwInit()) {
        std::cerr << "Ошибка инициализации GLFW" << std::endl;
        return -1;
    }

    // Создание окна
    GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL Point", nullptr, nullptr);
    if (!window) {
        std::cerr << "Ошибка создания окна GLFW" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // Инициализация GLEW
    if (glewInit() != GLEW_OK) {
        std::cerr << "Ошибка инициализации GLEW" << std::endl;
        return -1;
    }

    // Вывод версии OpenGL
    std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;

    // Установка функции изменения размеров окна
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Настройка OpenGL
    glPointSize(10.0f);  // Размер точки

    // Главный цикл
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        // Рисуем точку
        glBegin(GL_POINTS);
        glVertex2f(0.0f, 0.0f);  // Координаты (X, Y)
        glEnd();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Очистка
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
