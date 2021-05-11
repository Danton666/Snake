#include "run.h"
#include "snake.h"
#include "apple.h"
#include <ctime>

void fillArrays(int* X, int* Y, size_t x, size_t y)
{
	for(int i = 0; i < x; ++i)
		X[i] = (i + 1) * 25;

	for (int i = 0; i < y; ++i)
		Y[i] = (i + 1) * 25;
}

void controlMoving(const Event& event, Snake& snake, std::list<Event>& eventList, const Vector2u& winSize)
{
	if(event.key.code == Keyboard::Up)
	{
		snake.addLast(Vector2f(snake.getLast().getPosition().x, snake.getLast().getPosition().y - 25.f));
		snake.eraseFirst();
	}
	else if(event.key.code == Keyboard::Down)
	{
		snake.addLast(Vector2f(snake.getLast().getPosition().x, snake.getLast().getPosition().y + 25.f));
		snake.eraseFirst();
	}
	else if(event.key.code == Keyboard::Left)
	{
		snake.addLast(Vector2f(snake.getLast().getPosition().x - 25.f, snake.getLast().getPosition().y));
		snake.eraseFirst();
	}
	else if(event.key.code == Keyboard::Right)
	{
		snake.addLast(Vector2f(snake.getLast().getPosition().x + 25.f, snake.getLast().getPosition().y));
		snake.eraseFirst();
	}
	else 
	{
		eventList.pop_back();

		switch(eventList.back().key.code)
		{
			case Keyboard::Up:
				snake.addLast(Vector2f(snake.getLast().getPosition().x, snake.getLast().getPosition().y - 25.f));
				snake.eraseFirst();
				break;

			case Keyboard::Down:
				snake.addLast(Vector2f(snake.getLast().getPosition().x, snake.getLast().getPosition().y + 25.f));
				snake.eraseFirst();
				break;

			case Keyboard::Left:
				snake.addLast(Vector2f(snake.getLast().getPosition().x - 25.f, snake.getLast().getPosition().y));
				snake.eraseFirst();
				break;

			case Keyboard::Right:
				snake.addLast(Vector2f(snake.getLast().getPosition().x + 25.f, snake.getLast().getPosition().y));
				snake.eraseFirst();
				break;

			default:
				break;
		}
	}
}

void appleIsEaten(Snake& snake, Apple& apple,  RenderWindow& window, int* X, int* Y, size_t x, size_t y)
{
	snake.addLast(Vector2f(snake.getLast().getPosition().x, snake.getLast().getPosition().y));

	size_t first = 0 + rand() % x;
	size_t second = 0 + rand() % y;	

	apple.setPosition(Vector2f(X[first], Y[second]));

	window.clear();
	snake.draw();
	window.display();

}

int run(RenderWindow& window, unsigned int fps)
{
	srand(time(0));

	std::list<Event> eventList;

	size_t x = (window.getSize().x / 25) - 1;
	size_t y = (window.getSize().y / 25) - 1;

	int X[x];
	int Y[y];

	fillArrays(X, Y, x, y);

	Snake snake(&window);
	Apple apple(Color::Red, 12.5f, Vector2f(200.f, 300.f), &window);

	snake.setPosition(Vector2f(300.f, 200.f));

	/*
	* The window are opening
	* Until the cross was clicked
	*/
	while(window.isOpen())
	{
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
		if((snake.getLast().getPosition().x == apple.getPosition().x) && 
			snake.getLast().getPosition().y == apple.getPosition().y)
		{
			appleIsEaten(snake, apple, window, X, Y, x, y);
			/*increase snake's speed*/
			window.setFramerateLimit(++fps);
		}
		else if(snake.getLast().getPosition().x >= window.getSize().x ||
				snake.getLast().getPosition().x <= 0.0 ||
				snake.getLast().getPosition().y >= window.getSize().y || 
				snake.getLast().getPosition().y <= 0.0
				)
			return 1;
		else if(snake.isDead(apple.getPosition()))
			return 1;

		/*
		* Snake's moving when keys were pressed
		* The snake is controlled by <Up>, <Down>, <Right>, <Left>
		*/
		controlMoving(event, snake, eventList, window.getSize());

		window.clear();

		apple.draw(); /*window.draw(apple)*/
		snake.draw(); /*window.draw(snake)*/

		window.display();
	}

	return 0;
}
