#include "snake.hpp"

/*Constructors {...*/

Snake::Snake(RenderWindow* window) : Snake(window, Vector2f(0.f, 0.f)) {}

Snake::Snake(RenderWindow* window, const Vector2f& position) : m_window(window) 
{
    RectangleShape head(position);

    head.setSize(m_size);
    head.setFillColor(m_snakeColor);

    m_snake.push_back(head);    
}
/* ...} Constructors*/

/*Methods {...*/
void Snake::setColor(const Color& color)
{
    for(auto& el : m_snake)
        el.setFillColor(color);
}

void Snake::setPosition(const Vector2f& pos) { m_snake.back().setPosition(pos); }

void Snake::setOutlineColor(const Color& color, unsigned int thickness)
{
    m_isOutColor = true;
    m_outColor = color;
    m_thickness = thickness;
}

void Snake::unsetOutlineColor() { m_isOutColor = false; }

const Color&    Snake::getColor() const { return m_snake.back().getFillColor(); }
const Vector2f& Snake::getPosition() const { return m_snake.back().getPosition(); }

const Vector2f& Snake::getSize() const { return m_snake.back().getSize(); }

const RectangleShape& Snake::getFirst() { return m_snake.front(); } 
const RectangleShape& Snake::getLast() { return m_snake.back(); }

bool Snake::isDead()
{
    for(auto it = m_snake.begin(); it != --(m_snake.end()); ++it)
        if((*it).getPosition() == m_snake.back().getPosition())
            return true;
    return false;
}

void Snake::addFirst(const Vector2f& pos)
{
    RectangleShape part(m_size);

    part.setFillColor(m_snakeColor);
    part.setPosition(pos);

    if(m_isOutColor)
    {
        part.setOutlineColor(m_outColor);
        part.setOutlineThickness(m_thickness);
    }

    m_snake.push_front(part);
}

void Snake::addLast(const Vector2f& pos)
{
        RectangleShape part(m_size);

        part.setFillColor(m_snakeColor);
        part.setPosition(pos);

        if(m_isOutColor)
        {
            part.setOutlineColor(m_outColor);
            part.setOutlineThickness(m_thickness);
        }

        m_snake.push_back(part);
}

void Snake::eraseLast() { m_snake.pop_back(); }
void Snake::eraseFirst() { m_snake.pop_front(); }

void Snake::setSpeed(unsigned int val) { m_window->setFramerateLimit(val); }

void Snake::move(const Vector2f& offset) { m_snake.back().move(offset); }

void Snake::draw()
{
    for(const auto& el : m_snake)
        m_window->draw(el);
}

/*...} Methods*/