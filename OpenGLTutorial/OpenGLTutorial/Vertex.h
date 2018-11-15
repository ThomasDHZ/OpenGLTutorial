#pragma once

#ifndef VERTEX_H
#define VERTEX_H

#include <glm/glm.hpp>

using namespace glm;

class Vertex
{
	private:
		vec3 Position;
		vec3 VertexColor;
		vec2 TextureCoordinates;

	public:
		Vertex(vec3 position, vec3 vertexcolor, vec2 texCoordinates);
		Vertex(vec3 position, vec2 texCoordinates);
		Vertex(vec3 position, vec3 vertexcolor);
		
		vec3 GetPosition()
		{
			return Position;
		}
		vec3 GetVertexColor()
		{
			return VertexColor;
		}
		vec2 GetTextureCoordinates()
		{
			return TextureCoordinates;
		}
};

#endif