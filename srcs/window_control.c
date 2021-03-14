#include "scop.h"

#include <stdio.h>

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

void	view_transform(int scancode)
{
	float v[3] = {
		0.0f, 0.0f, 0.0f
	};
	if (scancode == 263)
		v[0] = -0.25f;
	else if (scancode == 262)
		v[0] = 0.25f;
	else if (scancode == 265)
		v[1] = 0.25f;
	else if (scancode == 264)
		v[1] = -0.25f;
	singleton()->View = multMat(&singleton()->View.r1[0],
							&createMatrice(M_TRANSLATE, v, 0).r1[0]);
	glUniformMatrix4fv(singleton()->u_View, 1, 0, &singleton()->View.r1[0]);
}

void	model_transform(int scancode)
{
	float v[3];
	if (scancode == 86) {
		v[0] = 1.5f;
		v[1] = 1.5f;
		v[2] = 1.5f;
	}
	else if (scancode == 82) {
		v[0] = 0.5f;
		v[1] = 0.5f;
		v[2] = 0.5f;
	}
	singleton()->datas.Model = multMat(&singleton()->datas.Model.r1[0],
							&createMatrice(M_SCALE, v, 0).r1[0]);
	glUniformMatrix4fv(singleton()->datas.u_Model, 1, 0, &singleton()->datas.Model.r1[0]);
}

/*
**	up		: 265
**	down	: 264
**	left	: 263
**	right	: 262
*/

void	key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	printf("Scancode : [%d] Mods : [%d]\n", scancode, key);
	if (action == GLFW_PRESS && key == GLFW_KEY_ESCAPE)
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	else if (action == GLFW_PRESS && key == GLFW_KEY_F9)
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
	else if (action == 1 &&
			(scancode >= 262 && scancode <= 265))
		view_transform(scancode);
	else if (action == 1 && (scancode == 82 || scancode == 86))
		model_transform(scancode);
	else if (action == GLFW_PRESS && key == GLFW_KEY_P)
		printMatrices(singleton()->datas.Model);
	else if (action == GLFW_PRESS && key == GLFW_KEY_R)
		singleton()->g_rotate = !singleton()->g_rotate;
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
