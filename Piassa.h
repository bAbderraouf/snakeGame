#ifndef _PIASSA_H_
#define _PIASSA_H_

#include <iostream>
#include <SFML/Graphics.hpp>

class Piassa{

    public :

    // Piassa();
    Piassa(int x, int y, int size , int _outlineThickness = 1 );
    int getSize();
    int getXpos();
    int getYpos();
    int getLastXpos();
    int getLastYpos();
    void updateLastPos();
    void setXpos(int x);
    void setYpos(int y);
    void setLastXpos(int x);
    void setLastYpos(int y);
    sf::RectangleShape getRectPiassa();
    int getOutlineThinkness();
    // ~Piassa();

    private:

   // struct State {Stoping , Moving; };
   // State piassaState;
    
   // struct Direction {left , right , up , down;};
   // Direction piassaDirection;

    int ypos , xpos , size;
    int lastXpos , lastYpos;
    int outlineThickness;
    sf::RectangleShape rectPissa ;


};


#endif