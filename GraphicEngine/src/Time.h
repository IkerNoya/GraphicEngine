#ifndef TIME_H
#define TIME_H
#include "export.h"
#include <chrono>

class ENGINE_API Time {
	std::chrono::system_clock::time_point _startTime;
	std::chrono::duration<float> _deltaTime;
	float _timeScale;
	float _elapsedTime = 0;
	float _framesCounter;
	int frames;
	float fps=0;
public:
	Time();
	~Time();
	void reset();
	void setTimeScale(float t);
	float getTimeScale();
	float getSeconds();
	float getMinutes();
	float getHours();
	float getCurrentTime();
	void startTime();
	void tick();
	float deltaTime();
	void calculateFps();
	float getFPS();
	void FPS();
};
#endif // !TIME_H

