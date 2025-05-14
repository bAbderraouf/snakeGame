#ifndef _MAKLA_H_
#define _MAKLA_H_


#include <iostream>
#include <SFML/Graphics.hpp>

class Makla{

    public :
    Makla(float x, float y, float size );
    ~Makla();
    sf::RectangleShape getMakla();

    float getSize();
    float getXpos();
    float getYpos();

    private:
    float ypos , xpos , size;
    sf::RectangleShape makla; 

};


#endif