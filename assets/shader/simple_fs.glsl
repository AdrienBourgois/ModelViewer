#version 420

in vec4 tmpColor;
in vec2 tmpTexcoord;

out vec4 outColor;

uniform sampler2D tex;

void main(void)
{
	outColor = texture(tex, tmpTexcoord);
	//outColor = vec4(1,1,1,1);
}
