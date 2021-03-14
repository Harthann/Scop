#include "scop.h"

int compileShader(uint att, const char*source)
{
	uint id;
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

uint CreateShader(const char* vertexShader, const char* fragmentShader)
{
	uint program;
	uint vs;
	uint fs;

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