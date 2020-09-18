#ifndef ENTITY_H
#define ENTITY_H

#include "export.h"
#include "renderer.h"

#include "vec3.hpp"
#include "vec4.hpp"
#include "mat4x4.hpp"
#include "ext/matrix_transform.hpp"
#include "ext/matrix_clip_space.hpp"
#include "ext/scalar_constants.hpp"

struct ENGINE_API TRS {
	glm::mat4 translate;
	glm::mat4 rotationX;
	glm::mat4 rotationY;
	glm::mat4 rotationZ;
	glm::mat4 scale;
	glm::mat4 TRS;
};
struct ENGINE_API Transform {
	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;
};

class ENGINE_API Entity {
protected:
	Renderer* _renderer;
	TRS trs;
	void updateTRS();
public:
	Entity(Renderer* renderer);
	~Entity();
	Transform transform;
	Renderer* getRenderer();
	void setPosition(float x, float y, float z);
	void setRotX(float x);
	void setRotY(float y);
	void setRotZ(float z);
	void setScale(float x, float y, float z);
};
#endif // !ENTITY_H
