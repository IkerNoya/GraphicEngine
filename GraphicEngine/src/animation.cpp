#include "animation.h"

Animation::Animation() {
	_currentTime = 0;
	_length = 200; // find out why
	_currentTime = 0;
}
Animation::~Animation() {

}
void Animation::update(Time & time) {
	_currentTime = time.deltaTime() * _length;
	while (_currentFrame >= _length)
		_currentTime -= _length;
	float frameLength = _length / _frames.size();
	_currentTime = (int)(_currentTime / frameLength);
}
void Animation::addFrame(float u, float v, int width, int height, int spriteWidth, int spriteHeight, int timeToAnim, int totalFrames, int rowFramesCount) {
	_length = timeToAnim * 200;
	float indexX = 0;
	float indexY = 0;
	Frame frame;
	for (int i = 0; i < totalFrames; i++)
	{
		frame.frameCoordinates[0].u = (u + indexX) / spriteWidth;
		frame.frameCoordinates[0].v = (height + indexY) / spriteHeight;

		frame.frameCoordinates[1].u = ((u + indexX) + width) / spriteWidth;
		frame.frameCoordinates[1].v = (height + indexY) / spriteHeight;

		frame.frameCoordinates[2].u = ((u + indexX) + width) / spriteWidth;
		frame.frameCoordinates[2].v = (v + indexY) / spriteHeight;

		frame.frameCoordinates[3].u = (u + indexX) / spriteWidth;
		frame.frameCoordinates[3].v = (v + indexY) / spriteHeight;
		 // averiguar por que ocurren los cambios en las cuentas
		_frames.push_back(frame);
		indexX += width;
		if (i > 0)
			if (i % rowFramesCount == 0)
				indexY += height;
	}
}
int Animation::getCurrentFrame() {
	return _currentFrame; 
}
std::vector<Frame>& Animation::GetFrames() {
	return _frames;
}