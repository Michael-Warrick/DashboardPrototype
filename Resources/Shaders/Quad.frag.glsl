#version 410 core

layout (location = 0) out vec4 FragColor;

layout (location = 0) in vec3 fragmentColor;
layout (location = 1) in vec2 fragmentTextureCoords;

uniform sampler2D imageTexture;
uniform vec4 quadColor;

void main()
{
   // FragColor = texture(imageTexture, fragmentTextureCoords) * vec4(1.0, 1.0, 1.0, 1.0);
   FragColor = quadColor;
}