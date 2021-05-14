#include "run/isOutOfBounds.hpp"

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