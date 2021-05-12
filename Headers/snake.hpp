#ifndef __SNAKE_HPP__
#define __SNAKE_HPP__

#include <SFML/Graphics.hpp>
#include <list>
#include "apple.hpp"
#include "un.hpp"

class Snake
{

private:
	RenderWindow* m_window;

	Color m_snakeColor = Color(Color::Green);
	Vector2f m_pos = Vector2f(0.f, 0.f);
	Vector2f m_size = Vector2f(25.f, 25.f);

	Color m_outColor = Color(Color::Black);
	unsigned int m_thickness = 0;

	list<RectangleShape> m_snake = {};

public:
	Snake(RenderWindow* window);
	Snake(RenderWindow* window, const Vector2f& position);

	void setColor(const Color& color);
	void setPosition(const Vector2f& pos);
	void setOutlineColor(const Color& color = Color(Color::Black), unsigned int thickness = 1);

	const Color& getColor() const;
	const Vector2f&	getPosition() const;
	const Vector2f& getSize() const;
	const RectangleShape& getFirst();
	const RectangleShape& getLast();

	bool isDead();

	void addFirst(const Vector2f& pos);
	void addLast(const Vector2f& pos);

	void eraseLast();
	void eraseFirst();

	void setSpeed(unsigned int val);

	void move(const Vector2f& offset);

	void draw();
};


#endif //__SNAKE_HPP__