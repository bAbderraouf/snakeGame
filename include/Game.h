#ifndef Game_h
#define Game_h

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>  // to store enmies
#include <ctime>  // for randomizing
#include <sstream>  // string streams for updatings texts
#include <string>

/* 
    defintion de la classe principale du jeux
*/

class Game
{
protected:

    // constructor of an abstract class should be protected
    Game();
    /* variables */
    sf::VideoMode videoMode;
    sf::RenderWindow *fenetre;  // its a pointer because we need to delete it if need (dynamiquement alouée )
    sf::Event evnt;
    sf::Vector2i mousePosWindow ; // position of mouse relative to window
    sf::Vector2f mousePosView;

    /* Fonts */
    sf::Font font , gameOverFont;
    

    /* Text */
    sf::Text guiText;

    /* Game logic */
    struct Button{bool left , right  , space , up , down ;};
    Button button;
    unsigned score; 
    bool gameOver;
    bool mouseClicked;
    int health;
    unsigned energy;

    /* Private fucntions */
    virtual void initializeVariables()  = 0;
    virtual void initWindow(std :: string gameName);
    virtual void initFont() ;
    virtual void initText() ;
    virtual void calculateScore() = 0; 
     

public:

    /* constructor / destructor */
    virtual ~Game();

    /* Accessors */
    virtual const bool getIfWindowIsOpen() const ; 
    virtual bool getGameOver() const ;

    /*  Public Functions */
    virtual void setup() = 0;
    virtual void input();
    virtual void update() = 0;
    virtual void render() = 0;

    // update sub functions
    virtual void updateMousePosition() ; 
    virtual void updateText() = 0;
    virtual void updateEnergy() = 0;


    // render sub functions
    virtual void renderText(sf::RenderTarget &target); /// to be able to render it on any target (not only window)

};


#endif