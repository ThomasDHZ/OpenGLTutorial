#include <iostream>
#include <GL/glew.h>
#include "Display.h"
#include "Mesh.h"
#include "Shader.h"
#include "Texture.h"

using namespace std;

int main(int argc, char** argv)
{
	Display display(800, 600, "Helloworld");
	Shader shader("C://Users//dhz//source//repos//OpenGLTutorial//res//basicShader");
	Texture texture("C://Users//dhz//source//repos//OpenGLTutorial//res//bricks.jpg");

	vec3 pos1 = vec3(-1, -1, -1);
	vec3 pos2 = vec3(-1, -1, -1);
	vec3 pos3 = vec3(-1, -1, -1);

	vec2 Text1 = vec2(0, 0);
	vec2 Text2 = vec2(0.5, 1);
	vec2 Text3 = vec2(1, 0);

	Vertex vertices[] =
	{
		Vertex(pos1, Text1),
		Vertex(pos2, Text2),
		Vertex(pos3, Text3)
	};

	Mesh mesh(vertices, sizeof(vertices)/sizeof(vertices[0]));

	while (!display.IsClosed())
	{


		display.Clear(0.0F, 0.15F, 0.3F, 1.0F);
		shader.Bind();
		texture.Bind(0);
		mesh.Draw();

		display.SwapBuffers();
	}
	return 0;
}