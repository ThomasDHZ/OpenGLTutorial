#include <iostream>
#include <GL/glew.h>
#include "Display.h"

using namespace std;

int main(int argc, char** argv)
{
	Display display(800, 600, "Helloworld");

	while (!display.IsClosed())
	{
		display.Clear(0.0F, 0.15F, 0.3F, 1.0F);
		display.Update();
	}
	return 0;
}