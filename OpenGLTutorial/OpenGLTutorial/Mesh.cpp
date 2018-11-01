#include "Mesh.h"
#include <iostream>

Mesh::Mesh(Vertex* vertices, unsigned int numVertices)
{
	m_DrawCount = numVertices;
	
	glGenVertexArrays(1, &m_vertexArrayObject);
	glBindVertexArray(m_vertexArrayObject);

	glGenBuffers(NUM_BUFFERS, m_vertexArrayBuffers);
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[POSITION_VB]);
	glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(vertices[0]), vertices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glBindVertexArray(0);

	GLenum err;
	while (!(err = glGetError())) {
		std::cout << err;
	}
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


	GLenum err;
	while (!(err = glGetError())) {
		std::cout << err;
	}
}