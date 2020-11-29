#version 330 core

in vec3 position;
in vec3 customColor;
layout(location = 2) in vec2 aTexCoord;

out vec3 color;
out vec2 TexCoord;

uniform mat4 transform;
uniform mat4 view;
uniform mat4 projection;

void main() {
	color = customColor;
	texCoord = aTexCoord;
	gl_position = projection * view * transform * vec4(position, 1.0);
}