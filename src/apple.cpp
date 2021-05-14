#include "apple.hpp"

//Makes default apple
Apple::Apple(RenderWindow* window, const Vector2f& position) : m_window(window)
{   
    m_pos = position;

    m_apple.setFillColor(m_color);
    m_apple.setPosition(position);
}

//Sets the position of the apple
void Apple::setPosition(const Vector2f& pos) { m_apple.setPosition(pos); }

//Sets the color of the apple
void Apple::setColor(const Color& color) { m_apple.setFillColor(color); }

//Sets the point count of the apple 
//(the larger the count, the clearer the image of the apple)
void Apple::setPointCount(size_t count) { m_apple.setPointCount(count); }

// Gets the position of the apple
const Vector2f& Apple::getPosition() const { return m_apple.getPosition(); }

// Gets the color of the apple
const Color& Apple::getColor() const { return m_apple.getFillColor(); }

// Gets the point count of the apple (see also setPointCount)
size_t Apple::getPointCount() const { return m_apple.getPointCount(); }

// Draws the apple on the window
void Apple::draw() { m_window->draw(m_apple); }

