#include "animation.h"
#include <iostream>

Animation::Animation()
{
	_currentTime = 0;
	_currentFrame = 0;
	_length = 200;
}

Animation::~Animation() {}

void Animation::update(Time& timer)
{
	_currentTime = (timer.deltaTime() * _length);

	while (_currentTime >= _length) {
		_currentTime -= _length;
	}
	float frameLength = _length / _animations[_currentAnimation].size();
	_currentFrame = static_cast<int>(_currentTime / frameLength);
}
void Animation::addFrame(float frameX, float frameY, int spriteWidth, int spriteHeigth, int textureWidth, int textureHeigth, float timeToAnim, int totalFrames, int counFilas)
{
	_length = timeToAnim * 200;

	totalFrames = totalFrames + counFilas;
	float index_X = 0;
	float index_Y = 0;
	Frame frame;
	for (int i = 0; i < totalFrames; i++) {
		//--------
		frame.frameCoordinates[0].u = ((frameX + index_X) / textureWidth);
		frame.frameCoordinates[0].v = ((spriteHeigth + index_Y) / textureHeigth);

		frame.frameCoordinates[1].u = (((frameX + index_X) + spriteWidth) / textureWidth);
		frame.frameCoordinates[1].v = ((spriteHeigth + index_Y) / textureHeigth);

		frame.frameCoordinates[2].u = (((frameX + index_X) + spriteWidth) / textureWidth);
		frame.frameCoordinates[2].v = ((frameY + index_Y) / textureHeigth);

		frame.frameCoordinates[3].u = ((frameX + index_X) / textureWidth);
		frame.frameCoordinates[3].v = ((frameY + index_Y) / textureHeigth);

		_totalFrames.push_back(frame);
		index_X += spriteWidth;

		if (i > 0)
		{
			if (i % counFilas == 0)
			{
				index_Y += spriteHeigth;
				_animations.push_back(_totalFrames);
				_totalFrames.clear();
			}
		}
	}
}
void Animation::addFrame(float frameX, float frameY, int spriteWidth, int spriteHeigth, int textureWidth, int textureHeigth, float timeToAnim)
{
	_length = timeToAnim * 200;

	Frame frame;

	frame.frameCoordinates[0].u = ((frameX) / textureWidth);
	frame.frameCoordinates[0].v = ((spriteHeigth + frameY) / textureHeigth);


	frame.frameCoordinates[1].u = (((frameX)+spriteWidth) / textureWidth);
	frame.frameCoordinates[1].v = ((spriteHeigth + frameY) / textureHeigth);
	
	frame.frameCoordinates[2].u = (((frameX)+spriteWidth) / textureWidth);
	frame.frameCoordinates[2].v = ((frameY) / textureHeigth);

	frame.frameCoordinates[3].u = ((frameX) / textureWidth);
	frame.frameCoordinates[3].v = ((frameY) / textureHeigth);

	_totalFrames.push_back(frame);
}

void Animation::addAnimation()
{
	if (_totalFrames.size() > 0)
	{
		//cout << "PUSHIE LA ANIMACION VIEJA" << endl;
		_animations.push_back(_totalFrames);
		_totalFrames.clear();
		//cout << _animations.size() << endl;
	}
}
int Animation::getCurrentFrame()
{
	return _currentFrame;
}

void Animation::setCurrentAnimation(int currentAnimation) {
	_currentAnimation = currentAnimation;
}

vector<Frame>& Animation::getAnimation()
{
	if (_currentAnimation < _animations.size())
		return _animations[_currentAnimation];

	return _animations[_animations.size() - 1];
}