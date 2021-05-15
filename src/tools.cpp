#include "tools.hpp"

// Snake movement control
void controlMoving(const Event& event, Snake& snake, std::list<Event>& eventList)
{
    if(event.key.code == Keyboard::Up)
        snake.move(Vector2f(0.f, -25.f));
    else if(event.key.code == Keyboard::Down)
        snake.move(Vector2f(0.f, 25.f));
    else if(event.key.code == Keyboard::Left)
        snake.move(Vector2f(-25.f, 0.f));
    else if(event.key.code == Keyboard::Right)
        snake.move(Vector2f(25.f, 0.f));
    else
    {
        eventList.pop_back();

        // The snake will stop because nothing
        // was pressed, simulate pressing a button so
        // that the snake continues to move
        switch(eventList.back().key.code)
        {
            case Keyboard::Up:
                snake.move(Vector2f(0.f, -25.f));
                break;

            case Keyboard::Down:
                snake.move(Vector2f(0.f, 25.f));
                break;

            case Keyboard::Left:
                snake.move(Vector2f(-25.f, 0.f));
                break;

            case Keyboard::Right:
                snake.move(Vector2f(25.f, 0.f));
                break;

            default:
                break;
        }
    }
}

// Fill the array with certain numbers (positions)
// to generate a random position for the apple
void fillArrays(int* X, int* Y, size_t x, size_t y)
{
    for(size_t i = 0; i < x; ++i)
        X[i] = (i + 2) * 25;

    for (size_t i = 0; i < y; ++i)
        Y[i] = (i + 2) * 25;

}

// If the snake is out of bounds return true
// else return false
bool isOutOfBounds(const Snake& snake, const RenderWindow& window)
{
    return
    (   
        snake.getPosition().x > window.getSize().x - 50.0 ||
        snake.getPosition().x < 20.0 ||
        snake.getPosition().y > window.getSize().y - 50.0 || 
        snake.getPosition().y < 20.0
    );
}