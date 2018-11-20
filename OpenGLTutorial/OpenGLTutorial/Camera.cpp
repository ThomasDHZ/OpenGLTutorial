#include "Camera.h"


Camera::Camera(const vec3&pos, float fov, float aspect, float zNear, float zFar)
{
	m_Perspective = perspective(fov, aspect, zNear, zFar);
	m_Position = pos;
	m_forward = vec3(0, 0, 1);
	m_Up = vec3(0, 1, 0);
}
Camera::~Camera()
{

}

void Camera::Update(SDL_Event Event)
{
	float Velocity = CameraMoveSpeed * 5.0F;
	if (Event.type == SDL_KEYDOWN)
	{
		if (Event.key.keysym.sym == SDLK_LEFT)
		{
			int sdf = 34; //For Breakpoint testing.
		}
		else if (Event.key.keysym.sym == SDLK_RIGHT)
		{
			int sdf = 34; //For Breakpoint testing.
		}
		else if (Event.key.keysym.sym == SDLK_UP)
		{
			int sdf = 34; //For Breakpoint testing.
		}
		else if (Event.key.keysym.sym == SDLK_DOWN)
		{
			int sdf = 34; //For Breakpoint testing.
		}
	}
	else if (Event.type == SDL_MOUSEBUTTONDOWN)
	{
		//Not really sure if I'm going to use mouse events yet, but it's here just in case.
		if (Event.button.button == SDL_BUTTON_LEFT)
		{
			int sdf = 34; //For Breakpoint testing.
		}
		else if (Event.button.button == SDL_BUTTON_RIGHT)
		{
			int sdf = 34; //For Breakpoint testing.
		}
		else if (Event.button.button == SDL_BUTTON_MIDDLE)
		{
			int sdf = 34; //For Breakpoint testing.
		}
	}
}

mat4 Camera::GetViewProjection() const
{
	return m_Perspective * lookAt(m_Position, m_Position + m_forward, m_Up);
}