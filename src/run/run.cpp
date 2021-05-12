#include "run/run.hpp"
#include "run/fillArrays.hpp"
#include "run/controlMoving.hpp"
#include "run/isOutOfBounds.hpp"

#include "snake.hpp"
#include "apple.hpp"
#include <ctime>

int run(RenderWindow& window)
{
	srand(time(0));

	std::list<Event> eventList;

	unsigned int speed = 5;

	/*Speed of the snake*/
	window.setFramerateLimit(speed);

	size_t x = (window.getSize().x / 25) - 1;
	size_t y = (window.getSize().y / 25) - 1;

	int X[x];
	int Y[y];

	fillArrays(X, Y, x, y);

	Snake snake(&window);
	snake.setOutlineColor();
	snake.setPosition(Vector2f(300.f, 200.f));

	Apple apple(&window, Vector2f(X[0 + rand() % x], Y[0 + rand() % y]));

	/*
	* The window are opening
	* Until the cross was clicked
	*/
	while(window.isOpen())
	{
		snake.addLast(snake.getPosition());

		bool isEatYourself = snake.isDead(snake.getPosition());

		snake.eraseFirst();

		Event event;
		eventList.push_back(event);
		while(window.pollEvent(event))
			if(event.type == Event::Closed)	
				window.close();

		/*
		* <<Compare positions>>
		* If postions are equal then
		* It means apple is eaten
		*/
		if((snake.getPosition().x == apple.getPosition().x) && 
			snake.getPosition().y == apple.getPosition().y)
		{
			snake.addFirst(snake.getPosition());
			apple.setPosition(Vector2f(X[0 + rand() % x], Y[0 + rand() % y]));
			/*increase snake's speed*/
			snake.setSpeed(++speed);
		}
		else if(isOutOfBounds(snake, window))
			return 1;
		else if(isEatYourself)
			return 1;

		/*
		* Snake's moving when keys were pressed
		* The snake is controlled by <Up>, <Down>, <Right>, <Left>
		*/
		controlMoving(event, snake, eventList);

		if(eventList.size() > 5)
			eventList.pop_front();

		window.clear();

		apple.draw(); /*window.draw(apple)*/
		snake.draw(); /*window.draw(snake)*/

		window.display();
	}

	return 0;
}
