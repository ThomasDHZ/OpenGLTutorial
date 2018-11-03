#pragma once

#ifndef MESH_H
#define MESH_H

#include "vertex.h"
#include <glm/glm.hpp>
#include <GL/glew.h>

using namespace std;

class Mesh
{
	private:
		enum
		{
			POSITION_VB,
			TexCOORD_VB,
			NUM_BUFFERS
		};

		GLuint m_vertexArrayObject;
		GLuint m_vertexArrayBuffers[NUM_BUFFERS];
		unsigned int m_DrawCount;

		Mesh(const Mesh& other) {}
		Mesh& operator=(const Mesh& other) {}

		void Debug_ShowMeshMemory();
	public:
		Mesh(Vertex* vertices, unsigned int numVertices);
		virtual ~Mesh();

		void Draw();

};
#endif
