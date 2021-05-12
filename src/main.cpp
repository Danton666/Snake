#include "run.hpp"
#include <iostream>

int main()
{
	RenderWindow window(VideoMode(600, 400), "~ Snake ~");

	return run(window);
}