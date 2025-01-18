#version 410 core

layout (location = 0) in vec3 vertexPosition;
layout (location = 1) in vec3 vertexColor;
layout (location = 2) in vec2 vertexTextureCoords;

layout (location = 0) out vec3 fragmentColor;
layout (location = 1) out vec2 fragmentTextureCoords;

uniform mat4 mvp;

void main()
{
   gl_Position = mvp * vec4(vertexPosition, 1.0);

   fragmentColor = vertexColor;
   fragmentTextureCoords = vertexTextureCoords;
}