#include "Light.h"

Light::Light()
{

}

Light::Light(vec3 lightPosition)
{
	LightPosition = lightPosition;
	LightColor = vec3(1.0f, 1.0f, 1.0f);
}

Light::Light(vec3 lightPosition, vec3 lightColor)
{
	LightPosition = lightPosition;
	LightColor = lightColor;
}

Light::~Light()
{
	int adsf = 234;
}

void Light::SetLightPosition(vec3 lightPosition)
{
	LightPosition = lightPosition;
}

void Light::SetLightColor(vec3 lightColor)
{
	LightColor = lightColor;
}

void Light::Update(Shader shader)
{
	shader.SetVec3f("LightDirection", LightPosition.x, LightPosition.y, LightPosition.z);
	shader.SetVec3f("DiffuseColor", LightColor.x, LightColor.y, LightColor.z);
}
