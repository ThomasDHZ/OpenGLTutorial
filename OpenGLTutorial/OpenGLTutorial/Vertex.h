#pragma once

#ifndef VERTEX_H
#define VERTEX_H

#include <glm/glm.hpp>

using namespace glm;

class Vertex
{
	private:
		vec3 Pos;
		vec2 TextureCoordinates;

	public:
		Vertex(const vec3& pos, vec2& texCoordinates);
		inline vec3* GetPos()
		{
			return &Pos;
		}
		inline vec2* GetTextureCoordinates()
		{
			return &TextureCoordinates;
		}
};

#endif