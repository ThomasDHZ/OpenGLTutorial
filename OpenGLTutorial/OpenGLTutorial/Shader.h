#pragma once

#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <iostream>
#include <fstream>
#include <GL/glew.h>

using namespace std;

class Shader
{
	private:
		static const unsigned int NUM_SHADER = 2;

		GLuint m_program;
		GLuint m_shaders[NUM_SHADER];

		string LoadShader(const string& fileName);
		GLuint CreateShader(const string& text, GLenum ShaderType);
		void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const string& errorMessage);

		
		Shader(const Shader& other) {}
		Shader& operator=(const Shader& other) {}
	public:
		Shader(const string& fileNam);
		void Bind();

		virtual ~Shader();

};

#endif