#ifndef WINDOW_H
#define WINDOW_H

#include "export.h"
#include <stdlib.h>
#include <string>
#include <iostream>
#include "GL/glew.h"
#include "GLFW/glfw3.h"
class ENGINE_API Window{

public:
	Window();
	~Window();
	int StartWindow(int width, int height, const char* windowName);
};
#endif // !WINDOW_H

