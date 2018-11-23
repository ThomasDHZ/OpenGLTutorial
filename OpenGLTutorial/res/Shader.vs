#version 120

attribute vec3 position;
attribute vec2 texCoord;
attribute vec3 normal;

varying vec2 texCoord0;
varying vec3 normal0;

uniform mat4 CameraMatrix;
uniform mat4 ViewMatrix;
uniform mat4 ModelMatrix;

void main()
{
	gl_Position = ViewMatrix * CameraMatrix * vec4(position, 1.0f);
	texCoord0 = texCoord;
	normal0 = (ViewMatrix * CameraMatrix * vec4(normal, 0.0f)).xyz;
}

