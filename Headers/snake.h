#ifndef __SNAKE_H__
#define __SNAKE_H__

#include <SFML/Graphics.hpp>
#include <list>
#include "apple.h"

using namespace sf;
using namespace std;

class Snake
{

private:
	RenderWindow* m_window;

	Color m_snakeColor;
	Vector2f m_pos;
	Vector2f m_size;

	bool m_seps;
	Color m_sepColor;
	unsigned int m_thickness;

	list<RectangleShape> m_snake;

public:
	Snake(RenderWindow* window);
	Snake(const Color& snakeColor, bool seps, const Vector2f& position, const Vector2f& size, RenderWindow* window);

	Vector2f getPosition() const;

	RectangleShape& getHead();
	RectangleShape& getLast();

	void setPosition(const Vector2f& pos);

	bool isDead(const Vector2f& applePos);

	void addFirst(const Vector2f& pos);
	void addLast(const Vector2f& pos);

	void eraseLast();
	void eraseFirst();

	void move(const Vector2f& offset);
	void draw();

};


#endif //__SNAKE_H__