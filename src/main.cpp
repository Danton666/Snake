#include "run.h"
#include <iostream>

int main()
{
	unsigned int fps = 5;

	RenderWindow window(VideoMode(600, 400), "~ Snake ~");
	window.setFramerateLimit(fps);

	return run(window, fps);
}