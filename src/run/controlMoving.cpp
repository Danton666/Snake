#include "run/controlMoving.hpp"

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
