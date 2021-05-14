#include "run/run.hpp"

int main()
{
    RenderWindow window(VideoMode(800, 600), "~ Snake ~");

    //Everything happens in the 'run'
    return run(window);
}