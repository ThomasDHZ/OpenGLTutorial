#include "Vertex.h"

Vertex::Vertex(vec3 position, vec3 vertexcolor, vec2 texCoordinates)
{
	Position = position;
	VertexColor = vertexcolor;
	TextureCoordinates = texCoordinates;
}
Vertex::Vertex(vec3 position, vec2 texCoordinates)
{
	Position = position;
	TextureCoordinates = texCoordinates;
}
Vertex::Vertex(vec3 position, vec3 vertexcolor)
{
	Position = position;
	VertexColor = vertexcolor;
}
