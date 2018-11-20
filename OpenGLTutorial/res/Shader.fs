#version 120

uniform sampler2D Texture0;
uniform vec3 lightPos0;
uniform vec4 AmbientLight;
uniform vec3 DiffuseColor;
uniform vec3 LightDirection;

varying vec2 texCoord0;
varying vec3 normal0;
void main()
{
//	vec3 lightPos0(0.0f, 0.0f, 2.0f);
	//vec3 LightDirection = vec3(0,0,1);
//	float DiffuseColor = clamp(dot(-LightDirection, normal0), 0.0, 1.0);

	//vec4 AmbientLight = vec4(0.2f,0.2f,0.2f,1.0f);

	float Diffuse = clamp(dot(-LightDirection, normal0), 0.0, 1.0);
	//vec3 DiffuseColor = vec3(0.9f,0.9f,0.9f);
	vec3 FinalDiffuse = DiffuseColor * Diffuse;

	gl_FragColor = texture2D(Texture0, texCoord0) * vec4(FinalDiffuse,1.0f) * (AmbientLight + vec4(FinalDiffuse, 1.0f));
}
