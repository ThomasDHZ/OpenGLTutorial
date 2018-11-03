#pragma once

#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>
#include <GL/glew.h>


using namespace std;

class Texture
{
	private:

		GLuint m_Texture;

		Texture(const Texture& other) {}
		Texture& operator=(const Texture& other) {}
	
	public:

		Texture(const string& FileName);
		virtual ~Texture();
		
		void Bind(unsigned int unit);
};
#endif