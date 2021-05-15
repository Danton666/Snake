#include "snake.hpp"

/*Constructors {...*/

// Makes default snake with default position
Snake::Snake(RenderWindow* window) : Snake(window, Vector2f(0.f, 0.f)) {}

// Makes default snake with position [default position is (0.0, 0.0)]
Snake::Snake(RenderWindow* window, const Vector2f& position) : m_window(window) 
{
    init(position);
}
/* ...} Constructors*/

//Destructor
Snake::~Snake() {}

/*Private methods {...*/
void Snake::init(const Vector2f& pos)
{
    RectangleShape head;

    head.setSize(m_size);
    head.setFillColor(m_snakeColor);
    head.setPosition(pos);

    m_snake.push_back(head);       
}
/*...} Private methods*/

/*Public methods {...*/
// Sets the color(const sf::Color&) of the snake
void Snake::setColor(const Color& color)
{
    for(auto& el : m_snake)
        el.setFillColor(color);
}

// Sets the position (const sf::Vector2f&) of the snake's head
void Snake::setPosition(const Vector2f& pos) { m_snake.back().setPosition(pos); }

/*
* Sets the outline color (const Color&) of the snake
* this method doesn't actually set the color
* it change varialble m_isOutColor to 'true'
* regardless of its previous value
*/
void Snake::setOutlineColor(const Color& color, unsigned int thickness)
{
    m_isOutColor = true;
    m_outColor = color;
    m_thickness = thickness;
}

// Removes the outline color of the snake
void Snake::unsetOutlineColor() { m_isOutColor = false; }

// Gets the color of the snake
const Color& Snake::getColor() const { return m_snake.back().getFillColor(); }

/*
* Gets the position of the last part of snake 
* which is its head
*/
const Vector2f& Snake::getPosition() const { return m_snake.back().getPosition(); }

// Gets the size of one snake's element (const sf::Vector2f&)
const Vector2f& Snake::getSize() const { return m_snake.back().getSize(); }

// Gets the fisrt element of the snake
const RectangleShape& Snake::getFirst() { return m_snake.front(); } 

// Gets the last element of the snake
const RectangleShape& Snake::getLast() { return m_snake.back(); }

// Checks the snake has eaten itself or not
// Return true if it has and false if it has not
bool Snake::isDead()
{
    for(auto it = m_snake.begin(); it != --(m_snake.end()); ++it)
        if((*it).getPosition() == m_snake.back().getPosition())
            return true;

    return false;
}

// Adds a new element to the snake at its beginning
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

// Adds a new element to the snake at the its ending
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

// Removes the element of the snake at its ending
void Snake::eraseLast() { m_snake.pop_back(); }

// Removes the element of the snake at its beginnig
void Snake::eraseFirst() { m_snake.pop_front(); }

//Zeros the snake, needed for a new game
void Snake::eraseAll(const Vector2f& pos) 
{ 
    m_snake.clear(); 

    init(pos);
}

// Sets the speed of the snake
void Snake::setSpeed(unsigned int val) { m_window->setFramerateLimit(val); }

// Moves the snake's head to offset
void Snake::move(const Vector2f& offset) { m_snake.back().move(offset); }

// Draws the snake on the window
void Snake::draw(RenderTarget& target, RenderStates states) const
{
	for(const auto& el : m_snake)
		target.draw(el, states);
}

/*...} Public methods*/