#version 330 core
layout(location = 0) in vec3 position;
layout(location = 1) in vec3 vcolor;

out vec3 out_color;

uniform mat4 u_Model;
uniform mat4 u_View;
uniform mat4 u_Projection;

void main()
{
	gl_Position =  u_Projection * u_View * u_Model  * vec4(position, 1.0);
	out_color = vcolor;
}
