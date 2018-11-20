#pragma once

#ifndef CAMERA_H
#define CAMERA_H

#include <GLM/glm.hpp>
#include <GLM/gtx/transform.hpp>
#include <SDL2/SDL.h>

using namespace glm;

class Camera
{
	private:
		mat4 m_Perspective;
		vec3 m_Position;
		vec3 m_forward;
		vec3 m_Up;

		float CameraMoveSpeed = 2.5F;

	public:
		Camera(const vec3& pos, float fov, float aspect, float zNear, float zFar);
		~Camera();

		void Update(SDL_Event Event);
		mat4 GetViewProjection() const;
		
};
#endif