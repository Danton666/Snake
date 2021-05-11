#ifndef __APPLE_H__
#define __APPLE_H__

#include <SFML/Graphics.hpp>
#include "un.h"

class Apple
{

private:
	RenderWindow* m_window;

	CircleShape m_apple = CircleShape(12.f);
	Color m_color = Color(Color::Red);
	Vector2f m_pos = Vector2f(0.f, 0.f);


public:
	Apple(RenderWindow* window, const Vector2f& position = Vector2f(0.f, 0.f));

	void setPosition(const Vector2f& pos);
	void setColor(const Color& color);
	void setPointCount(size_t count);

	const Vector2f&	getPosition() const;
	const Color& getColor() const;
	size_t getPointCount() const;

	void draw();
};

#endif //__APPLE_H__