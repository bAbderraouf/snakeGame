#include "gameOver.h"

GameOver::GameOver(int score, int elapsedTime)
{
    // init variables
        this->videoMode.width = 100;
        this->videoMode.height = 150;
}

GameOver::~GameOver()
{
    delete this->window;
}

void GameOver::closeGameOver()
{
    this->~GameOver();
}

void GameOver::afficheGameOver()
{
    // init window
    
    this->window = new sf::RenderWindow( this->videoMode , "Game Over!" , sf::Style::Titlebar  | sf::Style::Close );  // titre + fermeture
    this->window->setFramerateLimit(10);  // min = 10, max = 60 (ou 50)
    

}
