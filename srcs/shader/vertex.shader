#version 330 core
layout(location = 0) in vec3 position;
layout(location = 1) in vec3 vcolor;

struct Material {
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
}; 


out vec3 out_color;
out Material omaterial;

uniform Material material;
uniform mat4 u_Model;
uniform mat4 u_View;
uniform mat4 u_Projection;

void main()
{
	gl_Position =  u_Projection * u_View * u_Model  * vec4(position, 1.0);
	out_color = vcolor;
	omaterial = material;
}
