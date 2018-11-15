#include <iostream>
#include <GL/glew.h>
#include "Display.h"
#include "Shader.h"
#include "Mesh.h"
#include "Vertex.h"
#include "Texture.h"
#include "Transform.h"
#include "Camera.h"

using namespace std;

int main(int argc, char** argv)
{
	vec3 pos1 = vec3(-0.5f, -0.5f, 0.0f);
	vec3 pos2 = vec3(0.5f, -0.5f, 0.0f);
	vec3 pos3 = vec3(0.0f, 0.5f, 0.0f);

	vec2 Text1 = vec2(0, 0);
	vec2 Text2 = vec2(0.5, 1);
	vec2 Text3 = vec2(1, 0);

	Vertex vertices[] =
	{
		Vertex(pos1, Text1),
		Vertex(pos2, Text2),
		Vertex(pos3, Text3)
	};

	Display display(800, 600, "Helloworld");
	Shader shader("C://Users//dhz//source//repos//OpenGLEngine//OpenGLEngine//Shader");
	Texture texture("C://Users//dhz//source//repos//OpenGLTutorial//res//bricks.jpg");
	Camera camera(vec3(0, 0, -2), 70.0F, (float)800 / (float)600, 0.01f, 1000.0f);
	Transform transform;
	Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]));

	float counter = 0.0f;




	while (!display.IsClosed())
	{
		display.Clear(0.0F, 0.15F, 0.3F, 1.0F);

		float sinCounter = sinf(counter);
		float cosCounter = cosf(counter);

		transform.GetPosition().x = sinf(sinCounter);
		transform.GetPosition().z = sinf(cosCounter);
		transform.GetRotation().x = counter * 50;
		transform.GetRotation().y = counter * 50;
		transform.GetRotation().z = counter * 50;


		shader.Bind();
		texture.Bind(0);
		shader.Update(transform, camera);
		mesh.Draw();
		display.Update();
		cout << glGetString(GL_VERSION) << endl;
		counter++;
	}
	return 0;
}