#ifndef ENTITY2D_H
#define ENTITY2D_H

#include "export.h"

#include "vec2.hpp"
#include "vec4.hpp"
#include "mat4x4.hpp"
#include "ext/matrix_transform.hpp"
#include "ext/matrix_clip_space.hpp"
#include "ext/scalar_constants.hpp"

struct ENGINE_API TRS {
	glm::mat4 translate;
	glm::mat4 rotationX;
	glm::mat4 rotationY;
	glm::mat4 scale;
	glm::mat4 TRS;
};
struct ENGINE_API Transform {
	glm::vec2 position;
	glm::vec2 rotation;
	glm::vec2 scale;
};
class ENGINE_API Entity2D{
private:
	TRS trs;
	void updateTRS();
public:
	Entity2D();
	~Entity2D();
	Transform transform;
	void setPosition(float x, float y);
	void setRotX(float x);
	void setRotY(float y);
	void setScale(float x, float y);
};

#endif