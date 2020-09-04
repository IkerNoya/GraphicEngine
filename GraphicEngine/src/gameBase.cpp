#include "gameBase.h"
#include <stdlib.h>
#include <iostream>
#include "GL/glew.h"
#include "GLFW/glfw3.h"
GameBase::GameBase() {
	window = new Window();
	renderer = NULL;
	renderer = new Renderer();
}
GameBase::~GameBase() {
	if (window != NULL)
		delete window;
	if (renderer != NULL)
		delete renderer;
}

int GameBase::compileShader(int type, const char*& source) {
	int id = glCreateShader(type);
	const char* src = source;
	glShaderSource(id, 1, &src, nullptr);
	glCompileShader(id);

	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);

	if (result == GL_FALSE) {
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		char* message = (char*)alloca(length * sizeof(char));
		glGetShaderInfoLog(id, length, &length, message);
		std::cout << "Failed to compile"<< (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << "shader" << std::endl;
		std::cout << message << std::endl;
		glDeleteShader(id);
		return 0;
	}

	return id;
}

int GameBase::createShader(const GLchar*& vertexShader, const GLchar*& fragmentShader) {
	int program = glCreateProgram();
	int vertexshader = compileShader(GL_VERTEX_SHADER, vertexShader);
	int fragmentshader = compileShader(GL_FRAGMENT_SHADER, fragmentShader);

	glAttachShader(program, vertexshader);
	glAttachShader(program, fragmentshader);
	glLinkProgram(program);
	glValidateProgram(program);

	glDeleteShader(vertexshader);
	glDeleteShader(fragmentshader);

	return program;
}
int GameBase::init() {
	GLFWwindow* newWindow;

	window->StartWindow(800, 600, "Graphics Engine", newWindow);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	// Make the window's context current /
	glfwMakeContextCurrent(newWindow);

	glewExperimental = GL_TRUE;
	glewInit();

	renderer->CreateTriangle();

	const GLchar* vertexShader = R"glsl(
		#version 150 core
		
		in vec2 position;
		in vec3 customColor;
		out vec3 color;

		void main()
		{
		gl_Position = vec4(position,0.0,1.0);
		}
)glsl";

	const GLchar* fragmentShader = R"glsl(
		#version 150 core
		

		out vec4 outColor;
		
		void main()
		{
		outColor = vec4(1.0, 1.0, 0.0, 1.0);
		}
)glsl";

	int shader = createShader(vertexShader, fragmentShader);
	glUseProgram(shader);

	glBindBuffer(GL_ARRAY_BUFFER, 0);


	//Loop until the user closes the window /
	while (!glfwWindowShouldClose(newWindow))
	{
		// Render here /
		glClearColor(0.0f, 0.0f, 1.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		renderer->DrawTriangle();

		// Swap front and back buffers /
		glfwSwapBuffers(newWindow);

		// Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}