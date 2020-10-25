#include "GL/glew.h"
#include "input.h"
#include "GLFW/glfw3.h"

Input::Input() {
}

Input::~Input() {
}

void Input::setInputWindow(GLFWwindow* window) {
	_window = window;
}

bool Input::getKey(keyCode key) {
	_type = GLFW_PRESS;
	switch (key)
	{
	case SPACE:
		return glfwGetKey(_window, GLFW_KEY_SPACE) == _type;
		break;
	case A:
		return glfwGetKey(_window, GLFW_KEY_A) == _type;
		break;
	case B:
		return glfwGetKey(_window, GLFW_KEY_B) == _type;
		break;
	case C:
		return glfwGetKey(_window, GLFW_KEY_C) == _type;
		break;
	case D:
		return glfwGetKey(_window, GLFW_KEY_D) == _type;
		break;
	case E:
		return glfwGetKey(_window, GLFW_KEY_E) == _type;
		break;
	case F:
		return glfwGetKey(_window, GLFW_KEY_F) == _type;
		break;
	case G:
		return glfwGetKey(_window, GLFW_KEY_G) == _type;
		break;
	case H:
		return glfwGetKey(_window, GLFW_KEY_H) == _type;
		break;
	case I:
		return glfwGetKey(_window, GLFW_KEY_I) == _type;
		break;
	case J:
		return glfwGetKey(_window, GLFW_KEY_J) == _type;
		break;
	case K:
		return glfwGetKey(_window, GLFW_KEY_K) == _type;
		break;
	case L:
		return glfwGetKey(_window, GLFW_KEY_L) == _type;
		break;
	case M:
		return glfwGetKey(_window, GLFW_KEY_M) == _type;
		break;
	case N:
		return glfwGetKey(_window, GLFW_KEY_N) == _type;
		break;
	/*case Ñ:
		glfwGetKey(_window, GLFW_KEY_Ñ) == _type;
		break;*/
	case O:
		return glfwGetKey(_window, GLFW_KEY_O) == _type;
		break;
	case P:
		return glfwGetKey(_window, GLFW_KEY_P) == _type;
		break;
	case Q:
		return glfwGetKey(_window, GLFW_KEY_Q) == _type;
		break;
	case R:
		return glfwGetKey(_window, GLFW_KEY_R) == _type;
		break;
	case S:
		return glfwGetKey(_window, GLFW_KEY_S) == _type;
		break;
	case T:
		return glfwGetKey(_window, GLFW_KEY_T) == _type;
		break;
	case U:
		return glfwGetKey(_window, GLFW_KEY_U) == _type;
		break;
	case V:
		return glfwGetKey(_window, GLFW_KEY_V) == _type;
		break;
	case W:
		return glfwGetKey(_window, GLFW_KEY_W) == _type;
		break;
	case X:
		return glfwGetKey(_window, GLFW_KEY_X) == _type;
		break;
	case Y:
		return glfwGetKey(_window, GLFW_KEY_Y) == _type;
		break;
	case Z:
		return glfwGetKey(_window, GLFW_KEY_Z) == _type;
		break;
	case APOSTROPHE:
		return glfwGetKey(_window, GLFW_KEY_APOSTROPHE) == _type;
		break;
	case COMMA:
		return glfwGetKey(_window, GLFW_KEY_COMMA) == _type;
		break;
	case MINUS:
		return glfwGetKey(_window, GLFW_KEY_MINUS) == _type;
		break;
	case PERIOD:
		return glfwGetKey(_window, GLFW_KEY_PERIOD) == _type;
		break;
	case SLASH:
		return glfwGetKey(_window, GLFW_KEY_SLASH) == _type;
		break;
	case NUM_0:
		return glfwGetKey(_window, GLFW_KEY_0) == _type;
		break;
	case NUM_1:
		return glfwGetKey(_window, GLFW_KEY_1) == _type;
		break;
	case NUM_2:
		return glfwGetKey(_window, GLFW_KEY_2) == _type;
		break;
	case NUM_3:
		return glfwGetKey(_window, GLFW_KEY_3) == _type;
		break;
	case NUM_4:
		return glfwGetKey(_window, GLFW_KEY_4) == _type;
		break;
	case NUM_5:
		return glfwGetKey(_window, GLFW_KEY_5) == _type;
		break;
	case NUM_6:
		return glfwGetKey(_window, GLFW_KEY_6) == _type;
		break;
	case NUM_7:
		return glfwGetKey(_window, GLFW_KEY_7) == _type;
		break;
	case NUM_8:
		return glfwGetKey(_window, GLFW_KEY_8) == _type;
		break;
	case NUM_9:
		return glfwGetKey(_window, GLFW_KEY_9) == _type;
		break;
	case SEMICOLON:
		return glfwGetKey(_window, GLFW_KEY_SEMICOLON) == _type;
		break;
	case EQUAL:
		return glfwGetKey(_window, GLFW_KEY_EQUAL) == _type;
		break;
	case LEFT_BRACKET:
		return glfwGetKey(_window, GLFW_KEY_LEFT_BRACKET) == _type;
		break;
	case BACKSLASH:
		return glfwGetKey(_window, GLFW_KEY_BACKSLASH) == _type;
		break;
	case RIGHT_BRACKET:
		return glfwGetKey(_window, GLFW_KEY_RIGHT_BRACKET) == _type;
		break;
	case GRAVE_ACCENT:
		return glfwGetKey(_window, GLFW_KEY_GRAVE_ACCENT) == _type;
		break;
	case WORLD_1:
		return glfwGetKey(_window, GLFW_KEY_WORLD_1) == _type;
		break;
	case WORLD_2:
		return glfwGetKey(_window, GLFW_KEY_WORLD_2) == _type;
		break;
	case ESCAPE:
		return glfwGetKey(_window, GLFW_KEY_ESCAPE) == _type;
		break;
	case ENTER:
		return glfwGetKey(_window, GLFW_KEY_ENTER) == _type;
		break;
	case TAB:
		return glfwGetKey(_window, GLFW_KEY_TAB) == _type;
		break;
	case BACKSPACE:
		return glfwGetKey(_window, GLFW_KEY_BACKSPACE) == _type;
		break;
	case INSERT:
		return glfwGetKey(_window, GLFW_KEY_INSERT) == _type;
		break;
	case DELETE:
		return glfwGetKey(_window, GLFW_KEY_DELETE) == _type;
		break;
	case RIGHT:
		return glfwGetKey(_window, GLFW_KEY_RIGHT) == _type;
		break;
	case LEFT:
		return glfwGetKey(_window, GLFW_KEY_LEFT) == _type;
		break;
	case DOWN:
		return glfwGetKey(_window, GLFW_KEY_DOWN) == _type;
		break;
	case UP:
		return glfwGetKey(_window, GLFW_KEY_UP) == _type;
		break;
	case PAGE_UP:
		return glfwGetKey(_window, GLFW_KEY_PAGE_UP) == _type;
		break;
	case PAGE_DOWN:
		return glfwGetKey(_window, GLFW_KEY_PAGE_DOWN) == _type;
		break;
	case HOME:
		return glfwGetKey(_window, GLFW_KEY_HOME) == _type;
		break;
	case END:
		return glfwGetKey(_window, GLFW_KEY_END) == _type;
		break;
	case CAPS_LOCK:
		return glfwGetKey(_window, GLFW_KEY_CAPS_LOCK) == _type;
		break;
	case SCROLL_LOCK:
		return glfwGetKey(_window, GLFW_KEY_SCROLL_LOCK) == _type;
		break;
	case NUM_LOCK:
		return glfwGetKey(_window, GLFW_KEY_NUM_LOCK) == _type;
		break;
	case PRINT_SCREEN:
		return glfwGetKey(_window, GLFW_KEY_PRINT_SCREEN) == _type;
		break;
	case PAUSE:
		return glfwGetKey(_window, GLFW_KEY_PAUSE) == _type;
		break;
	case F1:
		return glfwGetKey(_window, GLFW_KEY_F1) == _type;
		break;
	case F2:
		return glfwGetKey(_window, GLFW_KEY_F2) == _type;
		break;
	case F3:
		return glfwGetKey(_window, GLFW_KEY_F3) == _type;
		break;
	case F4:
		return glfwGetKey(_window, GLFW_KEY_F4) == _type;
		break;
	case F5:
		return glfwGetKey(_window, GLFW_KEY_F5) == _type;
		break;
	case F6:
		return glfwGetKey(_window, GLFW_KEY_F6) == _type;
		break;
	case F7:
		return glfwGetKey(_window, GLFW_KEY_F7) == _type;
		break;
	case F8:
		return glfwGetKey(_window, GLFW_KEY_F8) == _type;
		break;
	case F9:
		return glfwGetKey(_window, GLFW_KEY_F9) == _type;
		break;
	case F10:
		return glfwGetKey(_window, GLFW_KEY_F10) == _type;
		break;
	case F11:
		return glfwGetKey(_window, GLFW_KEY_F11) == _type;
		break;
	case F12:
		return glfwGetKey(_window, GLFW_KEY_F12) == _type;
		break;
	case KP_0:
		return glfwGetKey(_window, GLFW_KEY_KP_0) == _type;
		break;
	case KP_1:
		return glfwGetKey(_window, GLFW_KEY_KP_1) == _type;
		break;
	case KP_2:
		return glfwGetKey(_window, GLFW_KEY_KP_2) == _type;
		break;
	case KP_3:
		return glfwGetKey(_window, GLFW_KEY_KP_3) == _type;
		break;
	case KP_4:
		return glfwGetKey(_window, GLFW_KEY_KP_4) == _type;
		break;
	case KP_5:
		return glfwGetKey(_window, GLFW_KEY_KP_5) == _type;
		break;
	case KP_6:
		return glfwGetKey(_window, GLFW_KEY_KP_6) == _type;
		break;
	case KP_7:
		return glfwGetKey(_window, GLFW_KEY_KP_7) == _type;
		break;
	case KP_8:
		return glfwGetKey(_window, GLFW_KEY_KP_8) == _type;
		break;
	case KP_9:
		return glfwGetKey(_window, GLFW_KEY_KP_9) == _type;
		break;
	case LEFT_SHIFT:
		return glfwGetKey(_window, GLFW_KEY_LEFT_SHIFT) == _type;
		break;
	case LEFT_CONTROL:
		return glfwGetKey(_window, GLFW_KEY_LEFT_CONTROL) == _type;
		break;
	case LEFT_ALT:
		return glfwGetKey(_window, GLFW_KEY_LEFT_ALT) == _type;
		break;
	case LEFT_SUPER:
		return glfwGetKey(_window, GLFW_KEY_LEFT_SUPER) == _type;
		break;
	case RIGHT_SHIFT:
		return glfwGetKey(_window, GLFW_KEY_RIGHT_SHIFT) == _type;
		break;
	case RIGHT_CONTROL:
		return glfwGetKey(_window, GLFW_KEY_RIGHT_CONTROL) == _type;
		break;
	case RIGHT_ALT:
		return glfwGetKey(_window, GLFW_KEY_RIGHT_ALT) == _type;
		break;
	case RIGHT_SUPER:
		return glfwGetKey(_window, GLFW_KEY_RIGHT_SUPER) == _type;
		break;
	case MENU:
		return glfwGetKey(_window, GLFW_KEY_MENU) == _type;
		break;
	default:
		break;
	}
}

bool Input::getKeyDown(keyCode key) {
	_type = GLFW_FALSE;
	switch (key)
	{
	case SPACE:
		return glfwGetKey(_window, GLFW_KEY_SPACE) == _type;
		break;
	case A:
		return glfwGetKey(_window, GLFW_KEY_A) == _type;
		break;
	case B:
		return glfwGetKey(_window, GLFW_KEY_B) == _type;
		break;
	case C:
		return glfwGetKey(_window, GLFW_KEY_C) == _type;
		break;
	case D:
		return glfwGetKey(_window, GLFW_KEY_D) == _type;
		break;
	case E:
		return glfwGetKey(_window, GLFW_KEY_E) == _type;
		break;
	case F:
		return glfwGetKey(_window, GLFW_KEY_F) == _type;
		break;
	case G:
		return glfwGetKey(_window, GLFW_KEY_G) == _type;
		break;
	case H:
		return glfwGetKey(_window, GLFW_KEY_H) == _type;
		break;
	case I:
		return glfwGetKey(_window, GLFW_KEY_I) == _type;
		break;
	case J:
		return glfwGetKey(_window, GLFW_KEY_J) == _type;
		break;
	case K:
		return glfwGetKey(_window, GLFW_KEY_K) == _type;
		break;
	case L:
		return glfwGetKey(_window, GLFW_KEY_L) == _type;
		break;
	case M:
		return glfwGetKey(_window, GLFW_KEY_M) == _type;
		break;
	case N:
		return glfwGetKey(_window, GLFW_KEY_N) == _type;
		break;
		/*case Ñ:
			glfwGetKey(_window, GLFW_KEY_Ñ) == _type;
			break;*/
	case O:
		return glfwGetKey(_window, GLFW_KEY_O) == _type;
		break;
	case P:
		return glfwGetKey(_window, GLFW_KEY_P) == _type;
		break;
	case Q:
		return glfwGetKey(_window, GLFW_KEY_Q) == _type;
		break;
	case R:
		return glfwGetKey(_window, GLFW_KEY_R) == _type;
		break;
	case S:
		return glfwGetKey(_window, GLFW_KEY_S) == _type;
		break;
	case T:
		return glfwGetKey(_window, GLFW_KEY_T) == _type;
		break;
	case U:
		return glfwGetKey(_window, GLFW_KEY_U) == _type;
		break;
	case V:
		return glfwGetKey(_window, GLFW_KEY_V) == _type;
		break;
	case W:
		return glfwGetKey(_window, GLFW_KEY_W) == _type;
		break;
	case X:
		return glfwGetKey(_window, GLFW_KEY_X) == _type;
		break;
	case Y:
		return glfwGetKey(_window, GLFW_KEY_Y) == _type;
		break;
	case Z:
		return glfwGetKey(_window, GLFW_KEY_Z) == _type;
		break;
	case APOSTROPHE:
		return glfwGetKey(_window, GLFW_KEY_APOSTROPHE) == _type;
		break;
	case COMMA:
		return glfwGetKey(_window, GLFW_KEY_COMMA) == _type;
		break;
	case MINUS:
		return glfwGetKey(_window, GLFW_KEY_MINUS) == _type;
		break;
	case PERIOD:
		return glfwGetKey(_window, GLFW_KEY_PERIOD) == _type;
		break;
	case SLASH:
		return glfwGetKey(_window, GLFW_KEY_SLASH) == _type;
		break;
	case NUM_0:
		return glfwGetKey(_window, GLFW_KEY_0) == _type;
		break;
	case NUM_1:
		return glfwGetKey(_window, GLFW_KEY_1) == _type;
		break;
	case NUM_2:
		return glfwGetKey(_window, GLFW_KEY_2) == _type;
		break;
	case NUM_3:
		return glfwGetKey(_window, GLFW_KEY_3) == _type;
		break;
	case NUM_4:
		return glfwGetKey(_window, GLFW_KEY_4) == _type;
		break;
	case NUM_5:
		return glfwGetKey(_window, GLFW_KEY_5) == _type;
		break;
	case NUM_6:
		return glfwGetKey(_window, GLFW_KEY_6) == _type;
		break;
	case NUM_7:
		return glfwGetKey(_window, GLFW_KEY_7) == _type;
		break;
	case NUM_8:
		return glfwGetKey(_window, GLFW_KEY_8) == _type;
		break;
	case NUM_9:
		return glfwGetKey(_window, GLFW_KEY_9) == _type;
		break;
	case SEMICOLON:
		return glfwGetKey(_window, GLFW_KEY_SEMICOLON) == _type;
		break;
	case EQUAL:
		return glfwGetKey(_window, GLFW_KEY_EQUAL) == _type;
		break;
	case LEFT_BRACKET:
		return glfwGetKey(_window, GLFW_KEY_LEFT_BRACKET) == _type;
		break;
	case BACKSLASH:
		return glfwGetKey(_window, GLFW_KEY_BACKSLASH) == _type;
		break;
	case RIGHT_BRACKET:
		return glfwGetKey(_window, GLFW_KEY_RIGHT_BRACKET) == _type;
		break;
	case GRAVE_ACCENT:
		return glfwGetKey(_window, GLFW_KEY_GRAVE_ACCENT) == _type;
		break;
	case WORLD_1:
		return glfwGetKey(_window, GLFW_KEY_WORLD_1) == _type;
		break;
	case WORLD_2:
		return glfwGetKey(_window, GLFW_KEY_WORLD_2) == _type;
		break;
	case ESCAPE:
		return glfwGetKey(_window, GLFW_KEY_ESCAPE) == _type;
		break;
	case ENTER:
		return glfwGetKey(_window, GLFW_KEY_ENTER) == _type;
		break;
	case TAB:
		return glfwGetKey(_window, GLFW_KEY_TAB) == _type;
		break;
	case BACKSPACE:
		return glfwGetKey(_window, GLFW_KEY_BACKSPACE) == _type;
		break;
	case INSERT:
		return glfwGetKey(_window, GLFW_KEY_INSERT) == _type;
		break;
	case DELETE:
		return glfwGetKey(_window, GLFW_KEY_DELETE) == _type;
		break;
	case RIGHT:
		return glfwGetKey(_window, GLFW_KEY_RIGHT) == _type;
		break;
	case LEFT:
		return glfwGetKey(_window, GLFW_KEY_LEFT) == _type;
		break;
	case DOWN:
		return glfwGetKey(_window, GLFW_KEY_DOWN) == _type;
		break;
	case UP:
		return glfwGetKey(_window, GLFW_KEY_UP) == _type;
		break;
	case PAGE_UP:
		return glfwGetKey(_window, GLFW_KEY_PAGE_UP) == _type;
		break;
	case PAGE_DOWN:
		return glfwGetKey(_window, GLFW_KEY_PAGE_DOWN) == _type;
		break;
	case HOME:
		return glfwGetKey(_window, GLFW_KEY_HOME) == _type;
		break;
	case END:
		return glfwGetKey(_window, GLFW_KEY_END) == _type;
		break;
	case CAPS_LOCK:
		return glfwGetKey(_window, GLFW_KEY_CAPS_LOCK) == _type;
		break;
	case SCROLL_LOCK:
		return glfwGetKey(_window, GLFW_KEY_SCROLL_LOCK) == _type;
		break;
	case NUM_LOCK:
		return glfwGetKey(_window, GLFW_KEY_NUM_LOCK) == _type;
		break;
	case PRINT_SCREEN:
		return glfwGetKey(_window, GLFW_KEY_PRINT_SCREEN) == _type;
		break;
	case PAUSE:
		return glfwGetKey(_window, GLFW_KEY_PAUSE) == _type;
		break;
	case F1:
		return glfwGetKey(_window, GLFW_KEY_F1) == _type;
		break;
	case F2:
		return glfwGetKey(_window, GLFW_KEY_F2) == _type;
		break;
	case F3:
		return glfwGetKey(_window, GLFW_KEY_F3) == _type;
		break;
	case F4:
		return glfwGetKey(_window, GLFW_KEY_F4) == _type;
		break;
	case F5:
		return glfwGetKey(_window, GLFW_KEY_F5) == _type;
		break;
	case F6:
		return glfwGetKey(_window, GLFW_KEY_F6) == _type;
		break;
	case F7:
		return glfwGetKey(_window, GLFW_KEY_F7) == _type;
		break;
	case F8:
		return glfwGetKey(_window, GLFW_KEY_F8) == _type;
		break;
	case F9:
		return glfwGetKey(_window, GLFW_KEY_F9) == _type;
		break;
	case F10:
		return glfwGetKey(_window, GLFW_KEY_F10) == _type;
		break;
	case F11:
		return glfwGetKey(_window, GLFW_KEY_F11) == _type;
		break;
	case F12:
		return glfwGetKey(_window, GLFW_KEY_F12) == _type;
		break;
	case KP_0:
		return glfwGetKey(_window, GLFW_KEY_KP_0) == _type;
		break;
	case KP_1:
		return glfwGetKey(_window, GLFW_KEY_KP_1) == _type;
		break;
	case KP_2:
		return glfwGetKey(_window, GLFW_KEY_KP_2) == _type;
		break;
	case KP_3:
		return glfwGetKey(_window, GLFW_KEY_KP_3) == _type;
		break;
	case KP_4:
		return glfwGetKey(_window, GLFW_KEY_KP_4) == _type;
		break;
	case KP_5:
		return glfwGetKey(_window, GLFW_KEY_KP_5) == _type;
		break;
	case KP_6:
		return glfwGetKey(_window, GLFW_KEY_KP_6) == _type;
		break;
	case KP_7:
		return glfwGetKey(_window, GLFW_KEY_KP_7) == _type;
		break;
	case KP_8:
		return glfwGetKey(_window, GLFW_KEY_KP_8) == _type;
		break;
	case KP_9:
		return glfwGetKey(_window, GLFW_KEY_KP_9) == _type;
		break;
	case LEFT_SHIFT:
		return glfwGetKey(_window, GLFW_KEY_LEFT_SHIFT) == _type;
		break;
	case LEFT_CONTROL:
		return glfwGetKey(_window, GLFW_KEY_LEFT_CONTROL) == _type;
		break;
	case LEFT_ALT:
		return glfwGetKey(_window, GLFW_KEY_LEFT_ALT) == _type;
		break;
	case LEFT_SUPER:
		return glfwGetKey(_window, GLFW_KEY_LEFT_SUPER) == _type;
		break;
	case RIGHT_SHIFT:
		return glfwGetKey(_window, GLFW_KEY_RIGHT_SHIFT) == _type;
		break;
	case RIGHT_CONTROL:
		return glfwGetKey(_window, GLFW_KEY_RIGHT_CONTROL) == _type;
		break;
	case RIGHT_ALT:
		return glfwGetKey(_window, GLFW_KEY_RIGHT_ALT) == _type;
		break;
	case RIGHT_SUPER:
		return glfwGetKey(_window, GLFW_KEY_RIGHT_SUPER) == _type;
		break;
	case MENU:
		return glfwGetKey(_window, GLFW_KEY_MENU) == _type;
		break;
	default:
		break;
	}
}

bool Input::getKeyUp(keyCode key) {
	_type = GLFW_RELEASE;
	switch (key)
	{
	case SPACE:
		return glfwGetKey(_window, GLFW_KEY_SPACE) == _type;
		break;
	case A:
		return glfwGetKey(_window, GLFW_KEY_A) == _type;
		break;
	case B:
		return glfwGetKey(_window, GLFW_KEY_B) == _type;
		break;
	case C:
		return glfwGetKey(_window, GLFW_KEY_C) == _type;
		break;
	case D:
		return glfwGetKey(_window, GLFW_KEY_D) == _type;
		break;
	case E:
		return glfwGetKey(_window, GLFW_KEY_E) == _type;
		break;
	case F:
		return glfwGetKey(_window, GLFW_KEY_F) == _type;
		break;
	case G:
		return glfwGetKey(_window, GLFW_KEY_G) == _type;
		break;
	case H:
		return glfwGetKey(_window, GLFW_KEY_H) == _type;
		break;
	case I:
		return glfwGetKey(_window, GLFW_KEY_I) == _type;
		break;
	case J:
		return glfwGetKey(_window, GLFW_KEY_J) == _type;
		break;
	case K:
		return glfwGetKey(_window, GLFW_KEY_K) == _type;
		break;
	case L:
		return glfwGetKey(_window, GLFW_KEY_L) == _type;
		break;
	case M:
		return glfwGetKey(_window, GLFW_KEY_M) == _type;
		break;
	case N:
		return glfwGetKey(_window, GLFW_KEY_N) == _type;
		break;
		/*case Ñ:
			glfwGetKey(_window, GLFW_KEY_Ñ) == _type;
			break;*/
	case O:
		return glfwGetKey(_window, GLFW_KEY_O) == _type;
		break;
	case P:
		return glfwGetKey(_window, GLFW_KEY_P) == _type;
		break;
	case Q:
		return glfwGetKey(_window, GLFW_KEY_Q) == _type;
		break;
	case R:
		return glfwGetKey(_window, GLFW_KEY_R) == _type;
		break;
	case S:
		return glfwGetKey(_window, GLFW_KEY_S) == _type;
		break;
	case T:
		return glfwGetKey(_window, GLFW_KEY_T) == _type;
		break;
	case U:
		return glfwGetKey(_window, GLFW_KEY_U) == _type;
		break;
	case V:
		return glfwGetKey(_window, GLFW_KEY_V) == _type;
		break;
	case W:
		return glfwGetKey(_window, GLFW_KEY_W) == _type;
		break;
	case X:
		return glfwGetKey(_window, GLFW_KEY_X) == _type;
		break;
	case Y:
		return glfwGetKey(_window, GLFW_KEY_Y) == _type;
		break;
	case Z:
		return glfwGetKey(_window, GLFW_KEY_Z) == _type;
		break;
	case APOSTROPHE:
		return glfwGetKey(_window, GLFW_KEY_APOSTROPHE) == _type;
		break;
	case COMMA:
		return glfwGetKey(_window, GLFW_KEY_COMMA) == _type;
		break;
	case MINUS:
		return glfwGetKey(_window, GLFW_KEY_MINUS) == _type;
		break;
	case PERIOD:
		return glfwGetKey(_window, GLFW_KEY_PERIOD) == _type;
		break;
	case SLASH:
		return glfwGetKey(_window, GLFW_KEY_SLASH) == _type;
		break;
	case NUM_0:
		return glfwGetKey(_window, GLFW_KEY_0) == _type;
		break;
	case NUM_1:
		return glfwGetKey(_window, GLFW_KEY_1) == _type;
		break;
	case NUM_2:
		return glfwGetKey(_window, GLFW_KEY_2) == _type;
		break;
	case NUM_3:
		return glfwGetKey(_window, GLFW_KEY_3) == _type;
		break;
	case NUM_4:
		return glfwGetKey(_window, GLFW_KEY_4) == _type;
		break;
	case NUM_5:
		return glfwGetKey(_window, GLFW_KEY_5) == _type;
		break;
	case NUM_6:
		return glfwGetKey(_window, GLFW_KEY_6) == _type;
		break;
	case NUM_7:
		return glfwGetKey(_window, GLFW_KEY_7) == _type;
		break;
	case NUM_8:
		return glfwGetKey(_window, GLFW_KEY_8) == _type;
		break;
	case NUM_9:
		return glfwGetKey(_window, GLFW_KEY_9) == _type;
		break;
	case SEMICOLON:
		return glfwGetKey(_window, GLFW_KEY_SEMICOLON) == _type;
		break;
	case EQUAL:
		return glfwGetKey(_window, GLFW_KEY_EQUAL) == _type;
		break;
	case LEFT_BRACKET:
		return glfwGetKey(_window, GLFW_KEY_LEFT_BRACKET) == _type;
		break;
	case BACKSLASH:
		return glfwGetKey(_window, GLFW_KEY_BACKSLASH) == _type;
		break;
	case RIGHT_BRACKET:
		return glfwGetKey(_window, GLFW_KEY_RIGHT_BRACKET) == _type;
		break;
	case GRAVE_ACCENT:
		return glfwGetKey(_window, GLFW_KEY_GRAVE_ACCENT) == _type;
		break;
	case WORLD_1:
		return glfwGetKey(_window, GLFW_KEY_WORLD_1) == _type;
		break;
	case WORLD_2:
		return glfwGetKey(_window, GLFW_KEY_WORLD_2) == _type;
		break;
	case ESCAPE:
		return glfwGetKey(_window, GLFW_KEY_ESCAPE) == _type;
		break;
	case ENTER:
		return glfwGetKey(_window, GLFW_KEY_ENTER) == _type;
		break;
	case TAB:
		return glfwGetKey(_window, GLFW_KEY_TAB) == _type;
		break;
	case BACKSPACE:
		return glfwGetKey(_window, GLFW_KEY_BACKSPACE) == _type;
		break;
	case INSERT:
		return glfwGetKey(_window, GLFW_KEY_INSERT) == _type;
		break;
	case DELETE:
		return glfwGetKey(_window, GLFW_KEY_DELETE) == _type;
		break;
	case RIGHT:
		return glfwGetKey(_window, GLFW_KEY_RIGHT) == _type;
		break;
	case LEFT:
		return glfwGetKey(_window, GLFW_KEY_LEFT) == _type;
		break;
	case DOWN:
		return glfwGetKey(_window, GLFW_KEY_DOWN) == _type;
		break;
	case UP:
		return glfwGetKey(_window, GLFW_KEY_UP) == _type;
		break;
	case PAGE_UP:
		return glfwGetKey(_window, GLFW_KEY_PAGE_UP) == _type;
		break;
	case PAGE_DOWN:
		return glfwGetKey(_window, GLFW_KEY_PAGE_DOWN) == _type;
		break;
	case HOME:
		return glfwGetKey(_window, GLFW_KEY_HOME) == _type;
		break;
	case END:
		return glfwGetKey(_window, GLFW_KEY_END) == _type;
		break;
	case CAPS_LOCK:
		return glfwGetKey(_window, GLFW_KEY_CAPS_LOCK) == _type;
		break;
	case SCROLL_LOCK:
		return glfwGetKey(_window, GLFW_KEY_SCROLL_LOCK) == _type;
		break;
	case NUM_LOCK:
		return glfwGetKey(_window, GLFW_KEY_NUM_LOCK) == _type;
		break;
	case PRINT_SCREEN:
		return glfwGetKey(_window, GLFW_KEY_PRINT_SCREEN) == _type;
		break;
	case PAUSE:
		return glfwGetKey(_window, GLFW_KEY_PAUSE) == _type;
		break;
	case F1:
		return glfwGetKey(_window, GLFW_KEY_F1) == _type;
		break;
	case F2:
		return glfwGetKey(_window, GLFW_KEY_F2) == _type;
		break;
	case F3:
		return glfwGetKey(_window, GLFW_KEY_F3) == _type;
		break;
	case F4:
		return glfwGetKey(_window, GLFW_KEY_F4) == _type;
		break;
	case F5:
		return glfwGetKey(_window, GLFW_KEY_F5) == _type;
		break;
	case F6:
		return glfwGetKey(_window, GLFW_KEY_F6) == _type;
		break;
	case F7:
		return glfwGetKey(_window, GLFW_KEY_F7) == _type;
		break;
	case F8:
		return glfwGetKey(_window, GLFW_KEY_F8) == _type;
		break;
	case F9:
		return glfwGetKey(_window, GLFW_KEY_F9) == _type;
		break;
	case F10:
		return glfwGetKey(_window, GLFW_KEY_F10) == _type;
		break;
	case F11:
		return glfwGetKey(_window, GLFW_KEY_F11) == _type;
		break;
	case F12:
		return glfwGetKey(_window, GLFW_KEY_F12) == _type;
		break;
	case KP_0:
		return glfwGetKey(_window, GLFW_KEY_KP_0) == _type;
		break;
	case KP_1:
		return glfwGetKey(_window, GLFW_KEY_KP_1) == _type;
		break;
	case KP_2:
		return glfwGetKey(_window, GLFW_KEY_KP_2) == _type;
		break;
	case KP_3:
		return glfwGetKey(_window, GLFW_KEY_KP_3) == _type;
		break;
	case KP_4:
		return glfwGetKey(_window, GLFW_KEY_KP_4) == _type;
		break;
	case KP_5:
		return glfwGetKey(_window, GLFW_KEY_KP_5) == _type;
		break;
	case KP_6:
		return glfwGetKey(_window, GLFW_KEY_KP_6) == _type;
		break;
	case KP_7:
		return glfwGetKey(_window, GLFW_KEY_KP_7) == _type;
		break;
	case KP_8:
		return glfwGetKey(_window, GLFW_KEY_KP_8) == _type;
		break;
	case KP_9:
		return glfwGetKey(_window, GLFW_KEY_KP_9) == _type;
		break;
	case LEFT_SHIFT:
		return glfwGetKey(_window, GLFW_KEY_LEFT_SHIFT) == _type;
		break;
	case LEFT_CONTROL:
		return glfwGetKey(_window, GLFW_KEY_LEFT_CONTROL) == _type;
		break;
	case LEFT_ALT:
		return glfwGetKey(_window, GLFW_KEY_LEFT_ALT) == _type;
		break;
	case LEFT_SUPER:
		return glfwGetKey(_window, GLFW_KEY_LEFT_SUPER) == _type;
		break;
	case RIGHT_SHIFT:
		return glfwGetKey(_window, GLFW_KEY_RIGHT_SHIFT) == _type;
		break;
	case RIGHT_CONTROL:
		return glfwGetKey(_window, GLFW_KEY_RIGHT_CONTROL) == _type;
		break;
	case RIGHT_ALT:
		return glfwGetKey(_window, GLFW_KEY_RIGHT_ALT) == _type;
		break;
	case RIGHT_SUPER:
		return glfwGetKey(_window, GLFW_KEY_RIGHT_SUPER) == _type;
		break;
	case MENU:
		return glfwGetKey(_window, GLFW_KEY_MENU) == _type;
		break;
	default:
		break;
	}
}