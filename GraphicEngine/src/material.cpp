#include "material.h"

Material::Material() {
	_color[0] = 1.0f;
	_color[1] = 1.0f;
	_color[2] = 1.0f;
}
Material::Material(float r, float g, float b) {
	_color[0] = r;
	_color[1] = g;
	_color[2] = b;

}
Material::~Material(){

}
void Material::setColor(float r, float g, float b) {
	_color[0] = r;
	_color[1] = g;
	_color[2] = b;
}

void Material::setR(float r){
	_color[0] = r;
}
void Material::setG(float g){
	_color[1] = g;
}
void Material::setB(float b) {
	_color[2] = b;
}

float Material::getR() {
	return _color[0];
}
float Material::getG() {
	return _color[1];
}
float Material::getB() {
	return _color[2];
}

float Material::getColorRGB() {
	int sizeColorArray = 3;
	for (int i = 0; i < sizeColorArray; i++) {
		return _color[i];
	}
}