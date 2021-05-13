#include "apple.hpp"

Apple::Apple(RenderWindow* window, const Vector2f& position) : m_window(window)
{   
    m_pos = position;

    m_apple.setFillColor(m_color);
    m_apple.setPosition(position);
}

void Apple::setPosition(const Vector2f& pos) { m_apple.setPosition(pos); }
void Apple::setColor(const Color& color) { m_apple.setFillColor(color); }
void Apple::setPointCount(size_t count) { m_apple.setPointCount(count); }

const Vector2f& Apple::getPosition() const { return m_apple.getPosition(); }
const Color& Apple::getColor() const { return m_apple.getFillColor(); }
size_t Apple::getPointCount() const { return m_apple.getPointCount(); }


void Apple::draw() { m_window->draw(m_apple); }

