#include "scop.h"

#include <alloca.h>

static int compileShader(unsigned int att, const char*source)
{
	unsigned int id;
	int result;

	id = glCreateShader(att);
	glShaderSource(id, 1, &source, NULL);
	glCompileShader(id);

	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE) {
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		char *message = (char*)alloca(length);
		glGetShaderInfoLog(id, length, &length, message);
		glDeleteShader(id);
		return (0);
	}
	return id;
}

unsigned int CreateShader(const char* vertexShader, const char* fragmentShader)
{
	unsigned int program;
	unsigned int vs;
	unsigned int fs;

	program = glCreateProgram();
	vs = compileShader(GL_VERTEX_SHADER, vertexShader);
	fs = compileShader(GL_FRAGMENT_SHADER, fragmentShader);

	glAttachShader(program, vs);
	glAttachShader(program, fs);
	glLinkProgram(program);
	glValidateProgram(program);
	glDeleteShader(vs);
	glDeleteShader(fs);
	return program;
}

void	gen_sqr(t_object *datas,float length)
{
	datas->vertex = malloc(sizeof(float) * (4 * 2));
	datas->vertex_count = 4 * 2;
	datas->vertex[0] = -(length / 2);
	datas->vertex[1] = (length / 2);
	datas->vertex[2] = -(length / 2);
	datas->vertex[3] = -(length / 2);
	datas->vertex[4] = (length / 2);
	datas->vertex[5] = (length / 2);
	datas->vertex[6] = (length / 2);
	datas->vertex[7] = -(length / 2);

	datas->index = malloc(sizeof(unsigned int) * 6);
	datas->index_count = 6;
	datas->index[0] = 0;
	datas->index[1] = 1;
	datas->index[2] = 2;
	datas->index[3] = 2;
	datas->index[4] = 3;
	datas->index[5] = 1;
}

t_mat	createProjection(void)
{
	t_mat proj;

	proj.r1[0] = 2.0f * 1.0f / (float)RES_X;
	proj.r1[1] = 0;
	proj.r1[2] = 0;
	proj.r1[3] = 0;

	proj.r2[0] = 0;
	proj.r2[1] = 2.0f * 1.0f / (float)RES_Y;
	proj.r2[2] = 0;
	proj.r2[3] = 0;

	proj.r3[0] = 0;
	proj.r3[1] = 0;
	proj.r3[2] = -(5.0f / 3.0f);
	proj.r3[3] = -1.0f;

	proj.r4[0] = -1.0f * ((float)RES_X / 2.0f) / (float)RES_X;
	proj.r4[1] = -1.0f * ((float)RES_Y / 2.0f) / (float)RES_Y;
	proj.r4[2] = 2.0f * 4.0f / -3.0f;
	proj.r4[3] = 0;
	// proj = createMatrice(M_IDENTITY, NULL, 0);
	return (proj);
}

void	initialize_uniform(t_all *all)
{
	t_mat matrix;

	matrix = createMatrice(M_IDENTITY, NULL, 0);

	all->u_Model = glGetUniformLocation(all->program_shader, "u_Model");
	all->u_View = glGetUniformLocation(all->program_shader, "u_View");
	all->u_Projection = glGetUniformLocation(all->program_shader, "u_Projection");
	glUniformMatrix4fv(all->u_Model, 1, 0, &matrix.r1[0]);
	glUniformMatrix4fv(all->u_View, 1, 0, &matrix.r1[0]);
	matrix = createProjection();
	glUniformMatrix4fv(all->u_Projection, 1, 0, &matrix.r1[0]);
}

void	render_loop(t_all *all)
{
	t_mat m_rot;
	// t_mat matrix;
	float x = 0.0f;
	float v[3];
	generate_buffer(all->datas, 2, singleton()->buffer_id);
	generate_index(all->datas, singleton()->index_id);
	initialize_uniform(all);
	
	v[0] = 0.0f;
	v[1] = 0.0f;
	v[2] = 1.0f;
	// printMatrices(matrix);
	glfwSwapInterval(10);
	while (!glfwWindowShouldClose(all->window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		// matrix = multMat(&matrix.r1[0], &m_rot.r1[0]);
		// if (x < 90 && x > 0)
		x += 0.5f;
		m_rot = createMatrice(M_ROTATE, v, x);
		glUniformMatrix4fv(all->u_Model, 1, 0, &m_rot.r1[0]);
		glDrawElements(GL_TRIANGLES, 6,
						GL_UNSIGNED_INT, NULL);
		glfwSwapBuffers(all->window);
		glfwPollEvents();
	}
}