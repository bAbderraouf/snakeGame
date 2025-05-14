#ifndef _GAME_OVER_
#define _GAME_OVER_

#include <iostream>
#include <SFML/Graphics.hpp>

class GameOver{
    public:
    GameOver(int score, int elapsedTime);
    ~GameOver();

    sf::VideoMode videoMode;
    sf::RenderWindow *window; 

    void afficheGameOver();
    void closeGameOver();

    private:
    int xSizeWindow, ySizeWindow, score, elapsedTime , textSizeGameOver, textSizeScore;
};

#endif