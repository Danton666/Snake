#include "snake.h"

Snake::Snake(RenderWindow* window) :
									 m_seps(true), 
									 m_snakeColor(Color::Green), 
									 m_thickness(1),  
									 m_window(window),
									 m_size(Vector2f(25.f, 25.f)),
									 m_pos(Vector2f(300.f, 200.f))
	{
		RectangleShape head(m_pos);
		head.setSize(m_size);
		head.setFillColor(m_snakeColor);

		if(m_seps)
		{
			head.setOutlineColor(m_sepColor);
			head.setOutlineThickness(m_thickness);
		}

		m_snake.push_back(head); 
	}

Snake::Snake(const Color& snakeColor, bool seps, const Vector2f& position, const Vector2f& size, RenderWindow* window) : 
																											m_snakeColor(snakeColor), 
																											m_seps(seps), 
																											m_pos(position), 
																											m_size(size), 
																											m_window(window),
																											m_thickness(3)
	{
		RectangleShape head(position);
		head.setSize(size);
		head.setFillColor(snakeColor);

		if(seps)
		{
			head.setOutlineColor(m_sepColor);
			head.setOutlineThickness(m_thickness);
		}

		m_snake.push_back(head);
	}

Vector2f Snake::getPosition() const { return m_snake.front().getPosition(); }

RectangleShape& Snake::getHead() { return m_snake.front(); } 
RectangleShape& Snake::getLast() { return m_snake.back(); }

void Snake::addFirst(const Vector2f& pos)
	{
		RectangleShape part(m_size);
		part.setFillColor(m_snakeColor);
		part.setOutlineColor(m_sepColor);
		part.setOutlineThickness(m_thickness);
		part.setPosition(pos);

		m_snake.push_front(part);
	}

void Snake::addLast(const Vector2f& pos)
{
		RectangleShape part(m_size);
		part.setFillColor(m_snakeColor);
		part.setOutlineColor(m_sepColor);
		part.setOutlineThickness(m_thickness);
		part.setPosition(pos);

		m_snake.push_back(part);
}

void Snake::eraseLast() { m_snake.pop_back(); }
void Snake::eraseFirst() { m_snake.pop_front(); }

void Snake::setPosition(const Vector2f& pos) { m_snake.back().setPosition(pos); }

bool Snake::isDead(const Vector2f& applePos)
{
	if(applePos == m_snake.back().getPosition())
		return false;

	for(auto it = m_snake.begin(); it != --(m_snake.end()); ++it)
		if((*it).getPosition() == m_snake.back().getPosition())
			return true;
	return false;
}

void Snake::move(const Vector2f& offset) { m_snake.front().setPosition(m_snake.front().getPosition() + offset); }

void Snake::draw()
{
	for(const auto& el : m_snake)
		m_window->draw(el);
}
