#pragma once

#ifndef MESH_H
#define MESH_H

#include "vertex.h"
#include <glm/glm.hpp>
#include <GL/glew.h>

class Mesh
{
	private:
		enum
		{
			POSITION_VB,
			NUM_BUFFERS
		};

		GLuint m_vertexArrayObject;
		GLuint m_vertexArrayBuffers[NUM_BUFFERS];
		unsigned int m_DrawCount;

		Mesh(const Mesh& other) {}
		Mesh& operator=(const Mesh& other) {}
	public:
		Mesh(Vertex* vertices, unsigned int numVertices);
		virtual ~Mesh();

		void Draw();

};
#endif
