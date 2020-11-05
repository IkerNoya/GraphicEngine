#ifndef ANIMATION_H
#define ANIMATION_H
#include "export.h"
#include "frame.h"
#include "Time.h"
#include <vector>
class ENGINE_API Animation {
	int _currentFrame;
	float _length;
	float _currentTime;
	std::vector<Frame> _frames;
public:
	Animation();
	~Animation();
	void update(Time & time);
	void addFrame(float u, float v, int width, int height, int spriteWidth, int spriteHeight, int timeToAnim, int totalFrames, int rowFramesCount);
	int getCurrentFrame();
	std::vector<Frame>& GetFrames();
};
#endif // !ANIMATION_H
