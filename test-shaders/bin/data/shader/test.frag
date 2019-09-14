#version 450

out vec4 outputColor;

void main()
{
    float windowWidth = 600.0;
    float windowHeight = 600.0;
    
	float r = gl_FragCoord.x / windowWidth;
	float g = gl_FragCoord.y / windowHeight;
	float b = 1.0;
	float a = 1.0;
	outputColor = vec4(r, g, b, a);
}