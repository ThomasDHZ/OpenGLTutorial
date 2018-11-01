#pragma once

#ifndef VERTEX_H
#define VERTEX_H

#include <glm/glm.hpp>

using namespace glm;

class Vertex
{
	private:
		vec3 Pos;
	public:
		Vertex(const vec3& pos);
		vec3 GetPos()
		{
			return Pos;
		}
};

#endif