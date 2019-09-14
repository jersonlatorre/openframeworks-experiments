uniform sampler2DRect u_background;

void main(void)
{
    vec4 texture =  texture2DRect(u_background, gl_FragCoord.xy);
	gl_FragColor = texture;
}