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
	datas->vertex = malloc(sizeof(float) * (4 * sizeof(t_vector)));
	datas->vertex_count = 4;
	datas->vertex[0].x = -0.5;
	datas->vertex[0].y = 0.5;
	datas->vertex[0].z = -1.0;
	
	datas->vertex[1].x = -0.5;
	datas->vertex[1].y = -0.5;
	datas->vertex[1].z = -1.0;

	datas->vertex[2].x = 0.5;
	datas->vertex[2].y = 0.5;
	datas->vertex[2].z = -1.0;

	datas->vertex[3].x = 0.5;
	datas->vertex[3].y = -0.5;
	datas->vertex[3].z = -1.0;

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
	float r = 1;
	float l = -1;
	float n = -1;
	float f = -3;
	float t = 1;
	float b = -1;

	proj.r1[0] = 2.0f * n / (r - l);
	proj.r1[1] = 0;
	proj.r1[2] = 0;
	proj.r1[3] = 0;

	proj.r2[0] = 0;
	proj.r2[1] = 2.0f * n / (t - b);
	proj.r2[2] = 0;
	proj.r2[3] = 0;

	proj.r3[0] = (r + l) / (r - l);
	proj.r3[1] = (t + b) / (t - b);
	proj.r3[2] = - (f + n)/  (f - n);
	proj.r3[3] = -1.0f;

	proj.r4[0] = 0;
	proj.r4[1] = 0;
	proj.r4[2] = - (2.0f * f * n) / (f - n);
	proj.r4[3] = 0;
	proj = createMatrice(M_IDENTITY, NULL, 0);
	return (proj);
}

void	initialize_uniform(t_all *all)
{
	t_mat matrix;
	float v[3] = {0.5f, 0.5f, 0.5f};

	all->Model = createMatrice(M_IDENTITY, NULL, 0);
	// matrix = createMatrice(M_IDENTITY, NULL, 0);

	all->u_Model = glGetUniformLocation(all->program_shader, "u_Model");
	all->u_View = glGetUniformLocation(all->program_shader, "u_View");
	all->u_Projection = glGetUniformLocation(all->program_shader, "u_Projection");
	glUniformMatrix4fv(all->u_View, 1, 0, &all->Model.r1[0]);
	all->Model = createMatrice(M_SCALE, v, 0);
	v[0] = 0.0f;
	v[1] = 0.0f;
	v[2] = 2.0f;
	all->Model = multMat(&all->Model.r1[0], &createMatrice(M_TRANSLATE,v , 0).r1[0]);
	glUniformMatrix4fv(all->u_Model, 1, 0, &all->Model.r1[0]);
	matrix = createProjection();
	glUniformMatrix4fv(all->u_Projection, 1, 0, &matrix.r1[0]);
}

void	render_loop(t_all *all)
{
	t_mat m_rot;
	t_mat matrix;
	float x = 0.0f;
	float v[3];
	generate_buffer(all->datas, 2, singleton()->buffer_id);
	generate_index(all->datas, singleton()->index_id);
	initialize_uniform(all);

	v[0] = 0.0f;
	v[1] = 0.0f;
	v[2] = 1.0f;
	matrix = createMatrice(M_ROTATE, v, x);
	glfwSwapInterval(10);
	while (!glfwWindowShouldClose(all->window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		glUniformMatrix4fv(all->u_Model, 1, 0, &all->Model.r1[0]);
		glDrawElements(GL_TRIANGLES, 6,
						GL_UNSIGNED_INT, NULL);
		if (all->g_rotate == true) {
			all->Model = multMat(&all->Model.r1[0], &createMatrice(M_ROTATE, v, x).r1[0]);
			x+=0.1f;
		}
		// matrix = createMatrice(M_ROTATE, v, x);
		glfwSwapBuffers(all->window);
		glfwPollEvents();
	}
}