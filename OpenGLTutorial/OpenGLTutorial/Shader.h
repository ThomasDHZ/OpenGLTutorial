#pragma once

#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <iostream>
#include <fstream>
#include <GL/glew.h>
#include "Transform.h"
#include "Camera.h"

using namespace std;

class Shader
{
	private:
		static const unsigned int NUM_SHADER = 2;

		enum
		{
			CAMERAMATRIX_U,
			VIEWMATRIX_U,
			MODEL_TRANSFORM_U,
			LIGHTING_U,
			NUM_UNIFORMS
		};

		GLuint m_program;
		GLuint m_shaders[NUM_SHADER];
		GLuint m_uniform[NUM_UNIFORMS];

		float counter;
		float sinCounter;

		mat4 ModelMatrix;
		string LoadShader(const string& fileName);
		GLuint CreateShader(const string& text, GLenum ShaderType);
		void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const string& errorMessage);

	public:
		Shader(const string& fileNam);
		void Bind();
		void Update(const Transform& transform, const Camera& camera);
		GLuint GetShaderProgram()
		{
			return m_program;
		}
		GLuint GetShaderUniformLocation(GLchar *Variable)
		{
			return glGetUniformLocation(m_program, Variable);
		
		}
		GLuint GetShaderAttributeLocation(GLchar *Variable)
		{
			return glGetAttribLocation(m_program, Variable);
		}
		void SetVec3f(const GLchar* IDLocation, GLfloat x, GLfloat y, GLfloat z);
		void SetVec4f(const GLchar* IDLocation, GLfloat x, GLfloat y, GLfloat z, GLfloat w);

		virtual ~Shader();

};

#endif