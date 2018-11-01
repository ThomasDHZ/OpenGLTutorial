#include <iostream>
#include <GL/glew.h>
#include "Display.h"
#include "Mesh.h"
#include "Shader.h"

using namespace std;

int main(int argc, char** argv)
{
	Display display(800, 600, "Helloworld");
	Shader shader("C://Users//dhz//source//repos//OpenGLTutorial//res//basicShader");
	Vertex vertices[] =
	{
		Vertex(vec3(-0.5,-0.5,0)),
		Vertex(vec3(0,0.5,0)),
		Vertex(vec3(0.5,-0.5,0))
	};

	Mesh mesh(vertices, sizeof(vertices)/sizeof(vertices[0]));

	while (!display.IsClosed())
	{


		display.Clear(0.0F, 0.15F, 0.3F, 1.0F);
		shader.Bind();
		mesh.Draw();
		cout << glGetError() << std::endl;
		display.Update();
	}
	return 0;
}