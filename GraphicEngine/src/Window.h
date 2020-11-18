#ifndef WINDOW_H
#define WINDOW_H

#include "export.h"

struct GLFWwindow;

class ENGINE_API Window{
private:
	GLFWwindow* _window;
public:
	Window();
	~Window();
	int StartWindow(int width, int height, const char* windowName);
	GLFWwindow* GetWindow();
};
#endif // !WINDOW_H

