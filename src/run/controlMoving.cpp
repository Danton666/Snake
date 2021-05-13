#include "run/controlMoving.hpp"

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
