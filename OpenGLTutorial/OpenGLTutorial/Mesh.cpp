#include "Mesh.h"
#include <iostream>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

Mesh::Mesh(const string& FileName)
{
	IndexedModel Model = OBJModel(FileName).ToIndexedModel();
	MeshLoader(Model);
}
Mesh::Mesh(Vertex* vertices, unsigned int numVertices, unsigned int* indices, unsigned int numIndices)
{
	IndexedModel Model;
	for (unsigned int x = 0; x < numVertices; x++)
	{
		Model.positions.push_back(vertices[x].GetPosition());
		Model.texCoords.push_back(vertices[x].GetTextureCoordinates());
		Model.normals.push_back(vertices[x].GetNormals());
	}
	for (unsigned int x = 0; x < numIndices; x++)
	{
		Model.indices.push_back(indices[x]);
	}

	MeshLoader(Model);
}

Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &m_vertexArrayObject);
}
void Mesh::MeshLoader(const IndexedModel& Model)
{
	m_DrawCount = Model.indices.size();

	glGenVertexArrays(1, &m_vertexArrayObject);
	glBindVertexArray(m_vertexArrayObject);

	glGenBuffers(NUM_BUFFERS, m_vertexArrayBuffers);

	glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[POSITION_VB]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Model.positions[0]) * Model.positions.size(), &Model.positions[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(POSITION_VB);
	glVertexAttribPointer(POSITION_VB, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[TexCOORD_VB]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Model.texCoords[0]) * Model.texCoords.size(), &Model.texCoords[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(TexCOORD_VB);
	glVertexAttribPointer(TexCOORD_VB, 2, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[NORMAL_VB]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Model.normals[0]) * Model.normals.size(), &Model.normals[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(NORMAL_VB);
	glVertexAttribPointer(NORMAL_VB, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_vertexArrayBuffers[Index_VB]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(Model.indices[0]) * Model.indices.size(), &Model.indices[0], GL_STATIC_DRAW);

	glBindVertexArray(0);

	Position = vec3(0.0f);
	Rotation = vec3(0.0f);
	Scale = vec3(1.0f);

	UpdateModelMatrix();
}
void Mesh::UpdateModelMatrix()
{
	ModelMatrix = mat4(1.0f);
	ModelMatrix = translate(ModelMatrix, Position);
	ModelMatrix = rotate(ModelMatrix, radians(Rotation.x), vec3(1.0f, 0.0f, 0.0f));
	ModelMatrix = rotate(ModelMatrix, radians(Rotation.y), vec3(0.0f, 1.0f, 0.0f));
	ModelMatrix = rotate(ModelMatrix, radians(Rotation.z), vec3(0.0f, 0.0f, 1.0f));
	ModelMatrix = scale(ModelMatrix, Scale);
}
void Mesh::Draw(Shader shader)
{
	UpdateModelMatrix();

	glUniformMatrix4fv(glGetUniformLocation(5, "ModelMatrix"), 1, GL_FALSE, &ModelMatrix[0][0]);

	glBindVertexArray(m_vertexArrayObject);
	glDrawElements(GL_TRIANGLES, m_DrawCount, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}