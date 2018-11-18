#pragma once

#ifndef MESH_H
#define MESH_H

#include "vertex.h"
#include "OBJloader.h"
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
			NORMAL_VB,
			Index_VB,
			NUM_BUFFERS
		};
		//float testing = 0.0f;
		//float verticesz[8];
		//float texpos[5];
		mat4x4 ModelMatrix;
		GLuint m_vertexArrayObject;
		GLuint m_vertexArrayBuffers[NUM_BUFFERS];
		unsigned int m_DrawCount;

		Mesh(const Mesh& other) {}
		Mesh& operator=(const Mesh& other) {}

		void MeshLoader(const IndexedModel& Model);
	public:
		Mesh(const string& FileName);
		Mesh(Vertex* vertices, unsigned int numVertices, unsigned int* indices, unsigned int numIndices);
		virtual ~Mesh();
		void Draw();
};
#endif
