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

mat4 Camera::GetViewProjection() const
{
	return m_Perspective * lookAt(m_Position, m_Position + m_forward, m_Up);
}