#ifndef TIME_H
#define TIME_H
#include "export.h"
#include <chrono>
#include <time.h>

class ENGINE_API Time {
	std::chrono::system_clock::time_point _startTime;
	std::chrono::duration<float> _deltaTime;
	float _timeScale;
	float _elapsedTime;
	float _framesCounter;
	int frames;
	float fps;
public:
	Time();
	~Time();
	void reset();
	void setTimeScale(float t);
	float getTimeScale();
	float getSeconds();
	float getMinutes();
	float getHours();
	void startTime();
	void tick();
	float deltaTime();
	void calculateFps();
	float getFPS();
};
#endif // !TIME_H

