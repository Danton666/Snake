#ifndef __APPLE_H__
#define __APPLE_H__

#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Apple
{

private:
	RenderWindow* m_window;

	CircleShape m_apple;
	float m_radius;
	Color m_color;
	Vector2f m_pos;


public:
	Apple(const Color& apple_color, float radius, const Vector2f& pos, RenderWindow* window);

	Vector2f getPosition() const;

	void setPosition(const Vector2f& pos);

	void draw();
};

#endif //__APPLE_H__