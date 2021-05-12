#include "run/isOutOfBounds.hpp"

bool isOutOfBounds(const Snake& snake, const RenderWindow& window)
{
	return
	(	
		snake.getPosition().x >= window.getSize().x - 50.0 ||
		snake.getPosition().x <= 25.0 ||
		snake.getPosition().y >= window.getSize().y - 50.0 || 
		snake.getPosition().y <= 25.0
	);
}