#version 410 core

layout (location = 0) out vec4 FragColor;

layout (location = 0) in vec3 fragmentColor;
layout (location = 1) in vec2 fragmentTextureCoords;

uniform sampler2D imageTexture;

vec3 hexToRGB(int hexValue) 
{
   vec3 color;
   color.x = ((hexValue >> 16) & 0xFF) / 255.0;  // Extract the RR byte
   color.y = ((hexValue >> 8) & 0xFF) / 255.0;   // Extract the GG byte
   color.z = ((hexValue) & 0xFF) / 255.0;        // Extract the BB byte

   return color;
}

void main()
{
   FragColor = texture(imageTexture, fragmentTextureCoords) * vec4(1.0, 1.0, 1.0, 1.0);
}