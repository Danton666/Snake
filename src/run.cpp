#include "run.h"
#include "snake.h"
#include "apple.h"
#include <ctime>

void fillArrays(int* X, int* Y, size_t x, size_t y)
{
	for(size_t i = 0; i < x; ++i)
		X[i] = (i + 1) * 25;

	for (size_t i = 0; i < y; ++i)
		Y[i] = (i + 1) * 25;
}

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

int run(RenderWindow& window, unsigned int speed)
{
	srand(time(0));

	std::list<Event> eventList;

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
