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

    // Make the event list, which 
    // will be contain events of the key pressed
    std::list<Event> eventList;

    unsigned int speed = 5;

    /*Speed of the snake*/
    window.setFramerateLimit(speed);

    size_t x = (window.getSize().x / 25) - 4;
    size_t y = (window.getSize().y / 25) - 4;

    // Arrays for random apple position
    int X[x];
    int Y[y];

    fillArrays(X, Y, x, y);

    // Make the snake
    Snake snake(&window);
    snake.setOutlineColor(Color::Black, 1);

    Vector2f startSnakePos = Vector2f(window.getSize().x / 2, window.getSize().y / 2);

    snake.setPosition(startSnakePos);

    //Make the apple
    Apple apple(&window, Vector2f(X[0 + rand() % x], Y[0 + rand() % y]));

    /*Line making {*/
    //These are borders of the window
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

    //This string will help to update counter
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
        bool isEatItself = snake.isDead();

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
            // Increase the length of the snake
            snake.addFirst(snake.getPosition());

            // Set a new position for the apple
            apple.setPosition(Vector2f(X[0 + rand() % x], Y[0 + rand() % y]));
            
            // Increase the counter of the scores
            ++sc;
            strScore = cpStrScore;
            strScore += to_string(sc);

            scores.setString(strScore);

            /*increase the speed of the snake*/
            snake.setSpeed(++speed);
        }

        /*
        * Snake's moving when keys were pressed
        * The snake is controlled by <Up>, <Down>, <Right>, <Left>
        */
        controlMoving(event, snake, eventList);

        // if the snake's out of bounds or it has eaten itself
        if(isOutOfBounds(snake, window) || isEatItself)
        {
            // Main thread sleeps for 1 second before the end of the game
            this_thread::sleep_for(1s);

            //Text 'Do you want to start a new game?'
            Text new_game;
            new_game.setString("Do you wnat to start\n\t\t a new game?\n\t\t\t\t\tY/N");
            new_game.setFont(font);
            new_game.setCharacterSize(30);
            new_game.setPosition(window.getSize().x / 2 - 200, window.getSize().y / 2 - 100);

            /*Clearing the window*/
            window.clear();

            /*Line drawing*/
            window.draw(line1);
            window.draw(line2);
            window.draw(line3);
            window.draw(line4);
            /*Line drawing*/

            window.draw(new_game);

            /*Displaying everything that was drawn*/
            window.display();            

            bool y_n_event(true);

            while(y_n_event)
            {
                if(window.waitEvent(event))
                {
                    if(event.key.code == Keyboard::N)
                        return 0;
                    else if(event.key.code == Keyboard::Y)
                    {
                        //Zeros the snake
                        snake.eraseAll(startSnakePos);

                        //Set default speed of the snake
                        speed = 5;
                        snake.setSpeed(speed);

                        //Zeros scores
                        sc = 0;
                        strScore = cpStrScore;
                        strScore += to_string(sc);
                        scores.setString(strScore);

                        //Clear list of the events
                        eventList.clear();

                        // Set a new random position for the apple
                        apple.setPosition(Vector2f(X[0 + rand() % x], Y[0 + rand() % y]));

                        /*Clearing the window*/
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

                        window.draw(apple);
                        window.draw(snake);

                        /*Displaying everything that was drawn*/
                        window.display();

                        y_n_event = false;
                    }
                    else {}
                }
            }
        }

        // In order to make the array too large 
        // Make it no more than 5
        if(eventList.size() > 5)
            eventList.pop_front();

        /*Clearing the window*/
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

        window.draw(apple); 
        window.draw(snake); 

        /*Displaying everything that was drawn*/
        window.display();
    }

    return 0;
}
