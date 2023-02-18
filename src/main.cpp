#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include<iostream>

using namespace std;

int g_windowSizeX = 640;
int g_windowSizeY = 480;

void glfwwWindowSizeCallback(GLFWwindow* pWindow, int width, int heihgt)
{
    g_windowSizeX = width;
    g_windowSizeY = heihgt;
    glViewport(0,0, g_windowSizeX,g_windowSizeY);
}

void glfwKeyCallBack(GLFWwindow* pWindow, int key, int scancode,int actoin, int mode)
{
    if (key == GLFW_KEY_ESCAPE && actoin == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(pWindow,GL_TRUE);
    }
}

int main(void)
{
    GLFWwindow* pWindow;

    /* Initialize the library */
    if (!glfwInit())
    {
        std::cout << "glfwInit Failed!" << std::endl;
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /* Create a windowed mode window and its OpenGL context */
    pWindow = glfwCreateWindow(g_windowSizeX, g_windowSizeY, "Battle-Cuty", nullptr, nullptr);
    if (!pWindow) // Window creation check
    {
        cout << "glfwCreateWindow Failed!" << endl;
        glfwTerminate();
        return -1;
    }

    //register a callback
    glfwSetWindowSizeCallback(pWindow, glfwwWindowSizeCallback);
    glfwSetKeyCallback(pWindow, glfwKeyCallBack);

    /* Make the window's context current */
    glfwMakeContextCurrent(pWindow);

	if(!gladLoadGL())
	{
		std::cout<<"Can't load GLAD"<<std::endl;
		return 0;
	}

    cout << "Renderer :" << glGetString(GL_RENDERER) << endl;
    cout << "OpenGL version :" << glGetString(GL_VERSION) << endl;

	glClearColor(1,1,0,1);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(pWindow))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(pWindow);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}