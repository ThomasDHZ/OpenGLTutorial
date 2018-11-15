#pragma once

#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

using namespace std;
using namespace glm;

class Transform
{
	private:
		vec3 Position;
		vec3 Rotation;
		vec3 Scale;

	public:
		Transform(const vec3& position = vec3(0, 0, 0), const vec3& rotation = vec3(0, 0, 0), const vec3& scale = vec3(1.0F, 1.0F, 1.0F));
		 mat4 GetModel() const;

		inline vec3& GetPosition() { return Position; }
		inline vec3& GetRotation() { return Rotation; }
		inline vec3& GetScale() { return Scale; }

		inline void SetPosition(vec3& pos) { Position = pos; }
		inline void SetRotation(vec3& rot) { Rotation = rot; }
		inline void SetScale(vec3& scale) { Scale = scale; }
};
#endif