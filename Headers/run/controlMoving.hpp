#ifndef __CONTROL_MOVING_HPP__
#define __CONTROL_MOVING_HPP__

#include "un.hpp"
#include "snake.hpp"
#include <list>
#include <SFML/Graphics.hpp>

void controlMoving(const Event& event, Snake& snake, std::list<Event>& eventList);

#endif //__CONTROL_MOVING_HPP__