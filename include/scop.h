#ifndef SCOP_H
#define SCOP_H


#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "libft.h"
#include "matrix.h"
#include <math.h>

#define RES_X 960
#define RES_Y 540

#ifndef NULL
#define NULL 0
#endif

#define RATIO 0.01745329251f

#define VIEW_DISTANCE 10.0f
#define FIELD_OF_VIEW 90.0f

typedef unsigned int uint;

typedef enum e_bool
{
	false, true
} t_bool;

typedef struct s_object
{
	t_vector	*vertex;
	int			vertex_count;
	int			index_count;
	uint		*index;
	char		*mtl_link;
	uint		*buffer_id;
	uint		*index_id;
	int			u_Model;
	t_mat		Model;
} t_object;

typedef struct s_all
{
	GLFWwindow	  *window;
	t_object		datas;
	t_bool		  fullscreen;
	uint		program_shader;
	int			u_View;
	int			u_Projection;
	t_mat		View;
	t_mat		Proj;
	t_bool		g_rotate;

} t_all;

/*	PROTOTYPE	*/
void			generate_buffer(t_object, int, uint *);
void			generate_index(t_object datas, uint *);

t_all	   		*singleton();
char			*ft_append(char *s1, char *s2, int length);
char			*extract_shader(const char *path);
void			render_loop(t_all *all);
GLFWwindow*		setWindowContext();
void			key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void			window_close(GLFWwindow* window);
uint			CreateShader(const char* vertexShader, const char* fragmentShader);
void			extract_object(const char* path, t_object *obj);
int				get_next_line(int fd, char **line);
void			error(const char* str);
void			print_object(t_object datas);
int				compileShader(uint att, const char*source);
uint			CreateShader(const char* vertexShader, const char* fragmentShader);
t_mat			createProjection(void);
t_mat			createView(void);

#endif
