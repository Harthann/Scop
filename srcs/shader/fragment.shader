#version 330 core

struct Material {
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
}; 

// uniform Material material;
in Material omaterial;

layout(location = 0) out vec4 color;

in vec3 out_color;

void	main()
{
	// ambient
    // vec3 ambient = lightColor * omaterial.ambient;
  	
    // // diffuse 
    // vec3 norm = normalize(Normal);
    // vec3 lightDir = normalize(lightPos - FragPos);
    // float diff = max(dot(norm, lightDir), 0.0);
    // vec3 diffuse = lightColor * (diff * omaterial.diffuse);
    
    // // specular
    // vec3 viewDir = normalize(viewPos - FragPos);
    // vec3 reflectDir = reflect(-lightDir, norm);  
    // float spec = pow(max(dot(viewDir, reflectDir), 0.0), omaterial.shininess);
    // vec3 specular = lightColor * (spec * omaterial.specular);  
        
    // vec3 result = omaterial.ambient + omaterial.diffuse + omaterial.specular;
	// color = vec4(result, 1.0);
	color = vec4(out_color, 1.0);
}
