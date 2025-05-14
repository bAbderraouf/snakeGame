#include "Makla.h"


Makla::Makla(float x, float y, float size)
{
    this -> size = size;
    this-> xpos = x;
    this-> ypos = y;
    
    // rectangle 
    this->makla.setSize(sf::Vector2f( float(size) , float(size)));
    this->makla.setFillColor(sf::Color::Green);
    this->makla.setOutlineColor(sf::Color::Green);
    this->makla.setOutlineThickness(0.f);
    this->makla.setPosition(sf::Vector2f(float(x), float(y)));
}

Makla::~Makla()
{
}

sf::RectangleShape Makla::getMakla()
{
    return makla;
}


float Makla::getSize()
{
    return this->size;
}

float Makla::getXpos()
{
    return this->xpos;
}

float Makla::getYpos()
{
    return this->ypos;
}


