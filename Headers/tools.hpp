#ifndef __TOOLS_HPP__
#define __TOOLS_HPP__

/*My headers*/
#include "un.hpp"
#include "snake.hpp"

/*standard library*/
#include <list>

/*SFML*/
#include <SFML/Graphics.hpp>

void controlMoving(const Event& event, Snake& snake, std::list<Event>& eventList);
void fillArrays(int* X, int* Y, size_t x, size_t y);
bool isOutOfBounds(const Snake& snake, const RenderWindow& window);

#endif //__TOOLS_HPP__