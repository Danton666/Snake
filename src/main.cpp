#include "run.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	unsigned int fps = 5;

	RenderWindow window(VideoMode(600, 400), "~ Snake ~");
	window.setFramerateLimit(fps);

	return run(window, fps);
}