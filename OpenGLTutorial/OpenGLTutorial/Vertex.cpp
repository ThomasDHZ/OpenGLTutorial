#include "Vertex.h"

Vertex::Vertex(const vec3& pos, vec2& texCoordinates)
{
	this->Pos = pos;
	this->TextureCoordinates = texCoordinates;
}
