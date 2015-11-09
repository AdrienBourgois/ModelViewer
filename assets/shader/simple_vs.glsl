#version 420

uniform mat4 world;
uniform mat4 view;
uniform mat4 proj;

in vec3 pos;
in vec4 color;

out vec4 tmpColor;

void main(void)
{
    gl_Position = proj * view * world * vec4(pos, 1);
    tmpColor = color;
}
