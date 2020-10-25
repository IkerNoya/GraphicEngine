#ifndef INPUT_H
#define INPUT_H
#include "GLFW/glfw3.h"
#include "export.h"
#include <iostream>

enum ENGINE_API keyCode {
	SPACE,
	A,
	B,
	C,
	D,
	E,
	F,
	G,
	H,
	I,
	J,
	K,
	L,
	M,
	N,
	Ñ,
	O,
	P,
	Q,
	R,
	S,
	T,
	U,
	V,
	W,
	X,
	Y,
	Z,

	APOSTROPHE,
	COMMA,
	MINUS,
	PERIOD,
	SLASH,

	NUM_0,
	NUM_1,
	NUM_2,
	NUM_3,
	NUM_4,
	NUM_5,
	NUM_6,
	NUM_7,
	NUM_8,
	NUM_9,

	SEMICOLON,
	EQUAL,

	LEFT_BRACKET,
	BACKSLASH,
	RIGHT_BRACKET,
	GRAVE_ACCENT,
	WORLD_1,
	WORLD_2,

	ESCAPE,
	ENTER,
	TAB,
	BACKSPACE,
	INSERT,
	DELETE,
	RIGHT,
	LEFT,
	DOWN,
	UP,
	PAGE_UP,
	PAGE_DOWN,
	HOME,
	END,
	CAPS_LOCK,
	SCROLL_LOCK,
	NUM_LOCK,
	PRINT_SCREEN,
	PAUSE,
	F1,
	F2,
	F3,
	F4,
	F5,
	F6,
	F7,
	F8,
	F9,
	F10,
	F11,
	F12,

	KP_0,
	KP_1,
	KP_2,
	KP_3,
	KP_4,
	KP_5,
	KP_6,
	KP_7,
	KP_8,
	KP_9,

	LEFT_SHIFT,
	LEFT_CONTROL,
	LEFT_ALT,
	LEFT_SUPER,
	RIGHT_SHIFT,
	RIGHT_CONTROL,
	RIGHT_ALT,
	RIGHT_SUPER,

	MENU
};

class ENGINE_API Input {
private:
	unsigned int _type;
	GLFWwindow* _window;
public:
	Input();
	~Input();
	void setInputWindow(GLFWwindow* window);
	bool getKey(keyCode key);
	bool getKeyDown(keyCode key);
	bool getKeyUp(keyCode key);
	keyCode keys;
};

#endif