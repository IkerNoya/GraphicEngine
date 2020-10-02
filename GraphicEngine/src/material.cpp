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
void Material::SetColor(float r, float g, float b) {
	_color[0] = r;
	_color[1] = g;
	_color[2] = b;
}
float Material::GetR() {
	return _color[0];
}
float Material::GetG() {
	return _color[1];
}
float Material::GetB() {
	return _color[2];
}
float Material::GetColorRGB() {
	int sizeColorArray = 3;
	for (int i = 0; i < sizeColorArray; i++) {
		return _color[i];
	}
}