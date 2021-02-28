#include "scop.h"

#include <stdio.h>
void	window_close(GLFWwindow* window)
{
	glfwSetWindowShouldClose(window, GLFW_TRUE);
}

GLFWmonitor* getMonitor(int count)
{
	static int numbers = 0;
	static GLFWmonitor** monitors = NULL;

	if (!monitors)
		monitors = glfwGetMonitors(&numbers);
	if (count < numbers)
		return (monitors[count]);
	else
		return (NULL);
}

void	key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	printf("Scancode : [%d] Mods : [%d]\n", scancode, singleton()->fullscreen);
	if (action == GLFW_PRESS && key == GLFW_KEY_ESCAPE)
		window_close(window);
	if (action == GLFW_PRESS && key == GLFW_KEY_F9)
	{
		GLFWmonitor *monitor = getMonitor(0);
		if (monitor)
		{
			if (!singleton()->fullscreen)
				glfwSetWindowSize(window,
								glfwGetVideoMode(monitor)->width,
								glfwGetVideoMode(monitor)->height);
			else
				glfwSetWindowSize(window, RES_X, RES_Y);
			singleton()->fullscreen = !singleton()->fullscreen;
		}
	}
}

GLFWwindow*	setWindowContext()
{
	GLFWwindow	*window;
	char		*vertexShader;
	char		*fragmentShader;

	if (!glfwInit())
		return NULL;
	window = glfwCreateWindow(RES_X, RES_Y, "SCOP", NULL, NULL);
	if (!window)
		return NULL;
	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, key_callback);
	if (glewInit() != GLEW_OK)
		return (NULL);
	vertexShader = extract_shader("srcs/shader/vertex.shader");
	fragmentShader = extract_shader("srcs/shader/fragment.shader");

	singleton()->program_shader = CreateShader(vertexShader, fragmentShader);
	glUseProgram(singleton()->program_shader);
	return window;
}
