#include "run/run.hpp"

int main()
{
	RenderWindow window(VideoMode(600, 400), "~ Snake ~");

	return run(window);
}