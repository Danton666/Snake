#include "run/run.hpp"

int main()
{
    RenderWindow window(VideoMode(800, 600), "~ Snake ~");

    return run(window);
}