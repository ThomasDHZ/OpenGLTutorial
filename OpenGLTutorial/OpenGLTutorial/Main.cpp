#include <iostream>
#include <GL/glew.h>
#include "Display.h"
#include "Shader.h"
#include "Mesh.h"
#include "Vertex.h"
#include "Texture.h"
#include "Transform.h"
#include "Camera.h"
#include "LightManager.h"


using namespace std;

int main(int argc, char** argv)
{
	Vertex vertices[] =
	{
		Vertex(glm::vec3(-1, -1, -1), glm::vec2(1, 0), glm::vec3(0, 0, -1)),
		Vertex(glm::vec3(-1, 1, -1), glm::vec2(0, 0), glm::vec3(0, 0, -1)),
		Vertex(glm::vec3(1, 1, -1), glm::vec2(0, 1), glm::vec3(0, 0, -1)),
		Vertex(glm::vec3(1, -1, -1), glm::vec2(1, 1), glm::vec3(0, 0, -1)),

		Vertex(glm::vec3(-1, -1, 1), glm::vec2(1, 0), glm::vec3(0, 0, 1)),
		Vertex(glm::vec3(-1, 1, 1), glm::vec2(0, 0), glm::vec3(0, 0, 1)),
		Vertex(glm::vec3(1, 1, 1), glm::vec2(0, 1), glm::vec3(0, 0, 1)),
		Vertex(glm::vec3(1, -1, 1), glm::vec2(1, 1), glm::vec3(0, 0, 1)),

		Vertex(glm::vec3(-1, -1, -1), glm::vec2(0, 1), glm::vec3(0, -1, 0)),
		Vertex(glm::vec3(-1, -1, 1), glm::vec2(1, 1), glm::vec3(0, -1, 0)),
		Vertex(glm::vec3(1, -1, 1), glm::vec2(1, 0), glm::vec3(0, -1, 0)),
		Vertex(glm::vec3(1, -1, -1), glm::vec2(0, 0), glm::vec3(0, -1, 0)),

		Vertex(glm::vec3(-1, 1, -1), glm::vec2(0, 1), glm::vec3(0, 1, 0)),
		Vertex(glm::vec3(-1, 1, 1), glm::vec2(1, 1), glm::vec3(0, 1, 0)),
		Vertex(glm::vec3(1, 1, 1), glm::vec2(1, 0), glm::vec3(0, 1, 0)),
		Vertex(glm::vec3(1, 1, -1), glm::vec2(0, 0), glm::vec3(0, 1, 0)),

		Vertex(glm::vec3(-1, -1, -1), glm::vec2(1, 1), glm::vec3(-1, 0, 0)),
		Vertex(glm::vec3(-1, -1, 1), glm::vec2(1, 0), glm::vec3(-1, 0, 0)),
		Vertex(glm::vec3(-1, 1, 1), glm::vec2(0, 0), glm::vec3(-1, 0, 0)),
		Vertex(glm::vec3(-1, 1, -1), glm::vec2(0, 1), glm::vec3(-1, 0, 0)),

		Vertex(glm::vec3(1, -1, -1), glm::vec2(1, 1), glm::vec3(1, 0, 0)),
		Vertex(glm::vec3(1, -1, 1), glm::vec2(1, 0), glm::vec3(1, 0, 0)),
		Vertex(glm::vec3(1, 1, 1), glm::vec2(0, 0), glm::vec3(1, 0, 0)),
		Vertex(glm::vec3(1, 1, -1), glm::vec2(0, 1), glm::vec3(1, 0, 0)),
	};

	unsigned int indices[] = { 0, 1, 2,
							  0, 2, 3,

							  6, 5, 4,
							  7, 6, 4,

							  10, 9, 8,
							  11, 10, 8,

							  12, 13, 14,
							  12, 14, 15,

							  16, 17, 18,
							  16, 18, 19,

							  22, 21, 20,
							  23, 22, 20
	};

	Display display(800, 600, "OpenGL Engine");
	Shader shader("..//res//Shader");
	Texture texture("..//res//bricks.jpg");
	Camera camera(vec3(0, 0, -4), 70.0F, (float)800 / (float)600, 0.01f, 1000.0f);
	Transform transform;
	LightManager lightManager;
	//lightManager.AddLight(Light(vec3(0.0f, 0.0f, 1.0f)));
	lightManager.AddLight(Light(vec3(0.0f, 0.0f, 1.0f), vec3(0.8f, 0.8f, 0.8f)));
	//Mesh mesh(vertices, sizeof(vertices)/sizeof(vertices[0]), indices, sizeof(indices) / sizeof(indices[0]));
	Mesh mesh("..//res//monkey3.obj");

	float counter = 0.0f;
	while (!display.IsClosed())
	{
		display.Clear(0.0F, 0.15F, 0.3F, 1.0F);

		float sinCounter = sinf(counter);
		float cosCounter = cosf(counter);

		//transform.GetPosition().x = sinf(sinCounter/5);
		//transform.GetPosition().z = sinf(cosCounter/5);
		//transform.GetRotation().x = counter /5000;
		transform.GetRotation().y = counter / 50;
		//transform.GetRotation().z = counter /5000;

		lightManager.SetAmbientLight(0.2f,0.2f,0.2f,1.0f);

		Light light = lightManager.GetLight(0);
		//lightManager.UpdateLightPosition(0, light.GetLightPosition().x, sinCounter, light.GetLightPosition().z);
		lightManager.UpdateLightColor(0, light.GetLightColor().y, sinCounter, sinCounter);
		//vec3 GetLightPos = lightManager.GetLight(0).GetLightPosition();
		//lightManager.GetLight(0).SetLightPosition(vec3(GetLightPos.x, sinCounter, GetLightPos.z));
	    //lightManager.GetLight(0).SetLightColor(vec3(sinCounter, 0.0f, 0.0f));

	
		shader.Bind();
		texture.Bind(0);
		lightManager.Update(shader);
		shader.Update(transform, camera);
		mesh.Draw(shader);
		display.Update(camera);
		counter++;
	}
	return 0;
}