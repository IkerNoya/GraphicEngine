#ifndef WINDOW_H
#define WINDOW_H

#include "export.h"

struct GLFWwindow;

class ENGINE_API Window{
private:
	GLFWwindow* _window;
	float _width;
	float _height;
public:
	Window(float width, float height);
	~Window();
	float getWidth();
	float getHeight();
	int StartWindow(const char* windowName);
	GLFWwindow* GetWindow();
};
#endif // !WINDOW_H

