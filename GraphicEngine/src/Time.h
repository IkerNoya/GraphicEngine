#ifndef TIME_H
#define TIME_H
#include "export.h"

class Time {
	float _time;
public:
	float deltaTime();
	float timeScale();
	float getSeconds();
};
#endif // !TIME_H

