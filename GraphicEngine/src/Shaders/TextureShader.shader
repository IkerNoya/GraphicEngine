#version 330 core
out vec4 Texture;

in vec2 TexCoord;
in vec3 color;

uniform sampler2D ourTexture;

void main() {
	Texture = texture(ourTexture, TexCoord) * vec4(color, 1.0);
}