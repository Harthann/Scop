#include "scop.h"

#include <alloca.h>

void	initialize_uniform(t_all *all)
{
	t_mat matrix;
	float v[3] = {0.25f, 0.25f, 0.25f};

	all->datas.Model = createMatrice(M_IDENTITY, NULL, 0);
	all->View = createView();

	all->datas.u_Model = glGetUniformLocation(all->program_shader, "u_Model");
	all->u_View = glGetUniformLocation(all->program_shader, "u_View");
	all->u_Projection = glGetUniformLocation(all->program_shader, "u_Projection");
	all->Proj = createProjection();
	all->datas.Model = multMat(&all->datas.Model.r1[0], &createMatrice(M_SCALE, v, 0).r1[0]);
	glUniformMatrix4fv(all->u_View, 1, 0, &all->View.r1[0]);
	glUniformMatrix4fv(all->datas.u_Model, 1, 0, &all->datas.Model.r1[0]);
	glUniformMatrix4fv(all->u_Projection, 1, 0, &all->Proj.r1[0]);
}

void	set_mat(const char* uniform_name, float a, float b, float c)
{
	int tmp;
	t_all *all = singleton();

	tmp = glGetUniformLocation(all->program_shader, uniform_name);
	printf("[%d] [%u]\n", tmp, all->program_shader);
	if (tmp)
		glUniform4f(tmp, a, b, c, 1.0f);
	// glUniform4f("material.diffuse", 1.0f, 0.5f, 0.31f, 1.0f);
	// glUniform4f("material.specular", 0.5f, 0.5f, 0.5f, 1.0f);
}

void	render_loop(t_all *all)
{
	t_mat matrix;
	float x = 0.5f;
	float v[3];
	generate_buffer(all->datas, 3, singleton()->datas.buffer_id);
	generate_index(all->datas, singleton()->datas.index_id);
	initialize_uniform(all);
	set_mat("material.ambient", 1.0f, 0.5f, 0.31f);
	set_mat("material.diffuse", 1.0f, 0.5f, 0.31f);
	set_mat("material.specular", 0.5f, 0.5f, 0.5f);
	glUniform1f(glGetUniformLocation(all->program_shader, "material.shininess"), 32.0f);

	v[0] = 0.0f;
	v[1] = 1.0f;
	v[2] = 0.0f;
	matrix = createMatrice(M_ROTATE, v, x);
	glfwSwapInterval(10);
	// glEnable(GL_CULL_FACE);
	// glCullFace(GL_FRONT);
	// glFrontFace(GL_CCW);
	glEnable(GL_DEPTH_TEST);
	while (!glfwWindowShouldClose(all->window))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glUniformMatrix4fv(all->datas.u_Model, 1, 0, &all->datas.Model.r1[0]);
		glEnableVertexAttribArray(1);
		glDrawElements(GL_TRIANGLES, all->datas.index_count,
						GL_UNSIGNED_INT, NULL);
		glDisableVertexAttribArray(1);
		glDrawElements(GL_LINES, all->datas.index_count,
						GL_UNSIGNED_INT, NULL);
		if (all->g_rotate == true)
			all->datas.Model = multMat(&all->datas.Model.r1[0], &createMatrice(M_ROTATE, v, x).r1[0]);
		// 	x+=0.5f;
		// }
		// matrix = createMatrice(M_ROTATE, v, x);
		glfwSwapBuffers(all->window);
		glfwPollEvents();
	}
}