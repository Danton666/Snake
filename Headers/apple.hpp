#ifndef __APPLE_HPP__
#define __APPLE_HPP__

#include <SFML/Graphics.hpp>
#include "un.hpp"

class Apple : public Drawable
{

private:

    CircleShape m_apple = CircleShape(12.f);
    Color m_color = Color(Color::Red);
    Vector2f m_pos = Vector2f(0.f, 0.f);


public:
    Apple(const Vector2f& position = Vector2f(0.f, 0.f));

    void setPosition(const Vector2f& pos);
    void setColor(const Color& color);
    void setPointCount(size_t count);

    const Vector2f& getPosition() const;
    const Color& getColor() const;
    size_t getPointCount() const;

    virtual void draw(RenderTarget& target, RenderStates states) const;
};

#endif //__APPLE_HPP__