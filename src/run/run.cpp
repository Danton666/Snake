#include "run/run.hpp"
#include "run/fillArrays.hpp"
#include "run/controlMoving.hpp"
#include "run/isOutOfBounds.hpp"

#include "snake.hpp"
#include "apple.hpp"

#include <string>
#include <ctime>
#include <thread>

int run(RenderWindow& window)
{
    srand(time(0));

    std::list<Event> eventList;

    unsigned int speed = 5;

    /*Speed of the snake*/
    window.setFramerateLimit(speed);

    size_t x = (window.getSize().x / 25) - 4;
    size_t y = (window.getSize().y / 25) - 4;

    int X[x];
    int Y[y];

    fillArrays(X, Y, x, y);

    Snake snake(&window);
    snake.setOutlineColor(Color::Black, 1);
    snake.setPosition(Vector2f(300.f, 200.f));

    Apple apple(&window, Vector2f(X[0 + rand() % x], Y[0 + rand() % y]));

    /*Line making {*/
    Color lineColor(153, 157, 201);

    RectangleShape line1(Vector2f(window.getSize().x - 200, 25));
    line1.setPosition(175, 0);
    line1.setFillColor(lineColor);

    RectangleShape line2(Vector2f(25, window.getSize().y));
    line2.setPosition(window.getSize().x - 25, 0);
    line2.setFillColor(lineColor);

    RectangleShape line3(Vector2f(window.getSize().x - 50, 25));
    line3.setPosition(25, window.getSize().y - 25);
    line3.setFillColor(lineColor);

    RectangleShape line4(Vector2f(25, window.getSize().y));
    line4.setPosition(0, 0);
    line4.setFillColor(lineColor);
    /*} Line making*/

    /*Make text 'Scores: ' {*/
    int sc = 0;
    string strScore("Scores:  ");
    string cpStrScore = strScore;
    strScore += to_string(sc);

    Font font;

    if(!font.loadFromFile("../../Fonts/snake.otf"))
        return -1;

    Text scores;
    scores.setString(strScore);
    scores.setFont(font);
    scores.setCharacterSize(20);
    scores.setPosition(35.f, 2.f);
    /*}Make text 'Scores: '*/

    /*
    * The window are opening
    * Until the cross was clicked
    */
    while(window.isOpen())
    {
        bool isEatYourself = snake.isDead();

        snake.addLast(snake.getPosition());
        snake.eraseFirst();

        Event event;
        eventList.push_back(event);
        while(window.pollEvent(event))
            if(event.type == Event::Closed) 
                window.close();

        /*
        * <<Compare positions>>
        * If postions are equal then
        * It means apple is eaten
        */
        if(((snake.getPosition().x == apple.getPosition().x) && 
            snake.getPosition().y == apple.getPosition().y))
        {
            snake.addFirst(snake.getPosition());
            apple.setPosition(Vector2f(X[0 + rand() % x], Y[0 + rand() % y]));
            
            ++sc;
            strScore = cpStrScore;
            strScore += to_string(sc);

            scores.setString(strScore);

            /*increase snake's speed*/
            snake.setSpeed(++speed);
        }
        else if(isOutOfBounds(snake, window) || isEatYourself)
        {
            this_thread::sleep_for(1s);

            return 1;
        }

        /*
        * Snake's moving when keys were pressed
        * The snake is controlled by <Up>, <Down>, <Right>, <Left>
        */
        controlMoving(event, snake, eventList);

        if(eventList.size() > 5)
            eventList.pop_front();

        window.clear();

        /*Line drawing*/
        window.draw(line1);
        window.draw(line2);
        window.draw(line3);
        window.draw(line4);
        /*Line drawing*/

        /*Text drawing*/
        window.draw(scores);
        /*Text drawing*/

        apple.draw(); /*window.draw(apple)*/
        snake.draw(); /*window.draw(snake)*/

        window.display();
    }

    return 0;
}
