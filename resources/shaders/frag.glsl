#version 410 core

out vec4 FragColor;

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
   FragColor = vec4(hexToRGB(0x008B01), 1.0);
}