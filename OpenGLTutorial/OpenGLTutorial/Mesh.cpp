#include "Mesh.h"
#include <iostream>
#include <vector>

Mesh::Mesh(Vertex* vertices, unsigned int numVertices)
{
	/*verticesz[0] = -0.5f;
verticesz[1] = -0.5f;
verticesz[2] = 0.0f;
verticesz[3] = 0.5f;
verticesz[4] = -0.5f;
verticesz[5] = 0.0f;
verticesz[6] = 0.0f;
verticesz[7] = 0.5f;
verticesz[8] = 0.0f;

texpos[0] = 1.0F;
texpos[1] = 0.0F;
texpos[2] = 0.0F;
texpos[3] = 0.0F;
texpos[4] = 0.5F;
texpos[5] = 1.0F;*/

	float verticesz[] = {
	-0.5f, -0.5f, 0.0f, // left  
	 0.5f, -0.5f, 0.0f, // right 
	 0.0f,  0.5f, 0.0f  // top   
	};

	float texpos[] =
	{
		1.0F, 0.0F,
		 0.0F, 0.0F,
		 0.5F, 1.0F
	};
	
	cout << "Vertex Memory:" << endl;
	for (int x = 0; x <= 8; x++)
	{
		cout << &verticesz[x] << ": " << verticesz[x] << endl;
	}
	cout << endl;
	cout << "Texture Coordinate Memory:" << endl;
	for (int x = 0; x <= 5; x++)
	{
		cout << &texpos[x] << ": " << texpos[x] << endl;
	}

	m_DrawCount = numVertices;
	
	glGenVertexArrays(1, &m_vertexArrayObject);
	glGenBuffers(1, &m_vertexArrayObject);
	
	vector<vec3> positions;
	vector<vec2> TexCoords;
	/*
	positions.reserve(numVertices);
	TexCoords.reserve(numVertices);

	for (unsigned int x = 0; x < numVertices; x++)
	{
		positions.push_back(*vertices[x].GetPos());
		TexCoords.push_back(*vertices[x].GetTextureCoordinates());
	}*/
	
	glBindVertexArray(m_vertexArrayObject);

	glGenBuffers(NUM_BUFFERS, m_vertexArrayBuffers);
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[POSITION_VB]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticesz), verticesz, GL_STATIC_DRAW);

	glEnableVertexAttribArray(POSITION_VB);
	glVertexAttribPointer(POSITION_VB, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glGenBuffers(NUM_BUFFERS, m_vertexArrayBuffers);
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[TexCOORD_VB]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(texpos), texpos, GL_STATIC_DRAW);

	glEnableVertexAttribArray(TexCOORD_VB);
	glVertexAttribPointer(TexCOORD_VB, 2, GL_FLOAT, GL_FALSE, 0, 0);

	glBindVertexArray(0);
}
Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &m_vertexArrayObject);
}

void Mesh::Draw()
{
	glBindVertexArray(m_vertexArrayObject);
	glDrawArrays(GL_TRIANGLES, 0, m_DrawCount);
	glBindVertexArray(0);
}