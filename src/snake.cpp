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

Snake::~Snake() {}

/*Methods {...*/
/*
* Describing:   set the color(const sf::Color&) to the snake
* Params:       const sf::Color& - color that will be set to the snake
* Return type:  void
*/
void Snake::setColor(const Color& color)
{
    for(auto& el : m_snake)
        el.setFillColor(color);
}

/*
* Describing:   set position (const sf::Vector2f&) to head of the snake
* Params:       const sf::Vector2f& - position that will be set to the head of the snake
* Return type:  void
*/
void Snake::setPosition(const Vector2f& pos) { m_snake.back().setPosition(pos); }

/*
* Describing:   set outline color (const Color&) to the snake
*               this method doesn't actually set the color
*               it change varialble m_isOutColor to 'true'
*               regardless of its previous value
*
* Params:       const sf::Color& - color which will be set to the snake
*               unsigned int thickness - thickness of outline color
*
* Return type:  void
*/
void Snake::setOutlineColor(const Color& color, unsigned int thickness)
{
    m_isOutColor = true;
    m_outColor = color;
    m_thickness = thickness;
}

/*
* Describing:   removes outline color
* Params:       none
* Return type:  void
*/
void Snake::unsetOutlineColor() { m_isOutColor = false; }

/*
* Describing:   get color of the snake
* Params:       none
* Return type:  const sf::Color& - color of the snake
*/
const Color&    Snake::getColor() const { return m_snake.back().getFillColor(); }

/*
* Describing:   get Position of the last part of snake 
*               which is the head of snake
*
* Params:       none
* Return type:  const sf::Vector2f& - position of the last part of the snake
*/
const Vector2f& Snake::getPosition() const { return m_snake.back().getPosition(); }

/*
* Describing:   get size of one snake's element (const sf::Vector2f&)
* Params:       none
* Return type:  const Vector2f& - size of snake's part
*/
const Vector2f& Snake::getSize() const { return m_snake.back().getSize(); }

/*
* Describing:   get the fisrt element of the snake
* Params:       none
* Return type:  const RectangleShape& - the fisrt part of the snake
*/
const RectangleShape& Snake::getFirst() { return m_snake.front(); } 

/*
* Describing:   get the last element of the snake
* Params:       none
* Return type:  const RectangleShape& - the last part of the snake
*/
const RectangleShape& Snake::getLast() { return m_snake.back(); }

/*
* Desribing:    checks the snake has eaten itself or not
* Params:       none
* Return type:  bool - if the snake has eaten itself return true
*               if It's not return false
*/
bool Snake::isDead()
{
    for(auto it = m_snake.begin(); it != --(m_snake.end()); ++it)
        if((*it).getPosition() == m_snake.back().getPosition())
            return true;
    return false;
}

/*
* Describing:   add new element to the snake to the begin of it
* Params:       const Vector2f& - position of the new element
*               other params are default which the snake already has
*
* Return type:  void
*/
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

/*
* Describing:   add new element to the snake to the end of it
* Params:       const Vector2f& - position of the new element
*               other params are default which the snake already has
*
* Return type:  void
*/
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

/*
* Describing:   removes the element of the snake at the end of it
* Parmas:       none
* Return type:  void
*/
void Snake::eraseLast() { m_snake.pop_back(); }

/*
* Describing:   removes the element of the snake at the begin of it
* Parmas:       none
* Return type:  void
*/
void Snake::eraseFirst() { m_snake.pop_front(); }

/*
* Describing:   set the speed of the snake
* Params:       unsigned int - speed value
* Return type:  void
*/
void Snake::setSpeed(unsigned int val) { m_window->setFramerateLimit(val); }

/*
* Describing:   moves the head of the snake to offset
* Params:       const Vector2f& - offset value
* Return type:  void
*/
void Snake::move(const Vector2f& offset) { m_snake.back().move(offset); }

/*
* Describing:   draws the snake on the window
* Params:       none
* Return type:  void
*/
void Snake::draw()
{
    for(const auto& el : m_snake)
        m_window->draw(el);
}

/*...} Methods*/