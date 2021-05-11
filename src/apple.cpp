#include "apple.h"

Apple::Apple(const Color& apple_color, float radius, const Vector2f& pos, RenderWindow* window) : 
																							m_apple(radius),
																							m_color(apple_color),
																							m_radius(radius),
																							m_pos(pos), 
																							m_window(window)
	{
		m_apple.setFillColor(apple_color);
		m_apple.setPosition(pos);
	}

Vector2f Apple::getPosition() const { return m_apple.getPosition(); }

void Apple::setPosition(const Vector2f& pos) { m_apple.setPosition(pos); }

void Apple::draw() { m_window->draw(m_apple); }

