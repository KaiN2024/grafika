
#define GLEW_DLL
#define GLF_DLL

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>




int main() {
   
    if (!glfwInit()) {
        fprintf(stderr, "EROR start \n");
        return 1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 1);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Создание окна
    GLFWwindow* window = glfwCreateWindow(512, 512, "Main", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    glewExperimental = GL_TRUE;

    GLenum ret = glewInit();
    if (GLEW_OK != ret) {
        fprintf(stderr, "ERROR: GLEW %s\n", glewGetErrorString(ret));
        return 1;
    }

    // Главный цикл
    while (!glfwWindowShouldClose(window)) {
        glClearColor(0.3, 0.3, 0.3, 0.0);
        glClear(GL_COLOR_BUFFER_BIT);

        // Рисуем звезду
        glBegin(GL_TRIANGLE_FAN);
        glColor3f(0.6, 0.2, 0.9);
        // Координаты (X, Y)
        glVertex2f(0.0, 0.0); 

        glVertex2f(0.0, 0.8);
        glVertex2f(0.2, 0.2);

        glVertex2f(0.8, 0.0);
        glVertex2f(0.2, -0.2);

        glVertex2f(0.0, -0.8);
        glVertex2f(-0.2, -0.2);

        glVertex2f(-0.8, 0.0);
        glVertex2f(-0.2, 0.2);

        glVertex2f(0.0, 0.8);

        glEnd();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Очистка
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
