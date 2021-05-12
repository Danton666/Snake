#include "run/isOutOfBounds.hpp"

bool isOutOfBounds(const Snake& snake, const RenderWindow& window)
{
	return
	(	
		snake.getPosition().x >= window.getSize().x ||
		snake.getPosition().x <= 0.0 ||
		snake.getPosition().y >= window.getSize().y || 
		snake.getPosition().y <= 0.0
	);
}