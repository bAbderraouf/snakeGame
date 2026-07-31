#include "Piassa.h"


Piassa::Piassa(int x, int y, int size , int _outlineThickness  )
{
    this -> size = size;
    this-> xpos = x;
    this-> ypos = y;
    // last position = the actuasl position
    this->lastXpos = this->xpos;
    this->lastYpos = this->ypos;

    this->outlineThickness  = _outlineThickness;
    
    // rectangle 
    this->rectPissa.setSize(sf::Vector2f(float(size),float(size)));
    this->rectPissa.setFillColor(sf::Color::White);
    this->rectPissa.setOutlineColor(sf::Color::Black);
    this->rectPissa.setOutlineThickness(float(outlineThickness));
    this->rectPissa.setPosition(sf::Vector2f(x, y));
}

int Piassa::getSize()
{
    return this->size;
}

int Piassa::getXpos()
{
    return this->xpos;
}

int Piassa::getYpos()
{
    return this->ypos;
}

int Piassa::getLastXpos()
{
    return this->lastXpos;
}

int Piassa::getLastYpos()
{
    return this->lastYpos;
}

void Piassa::updateLastPos()
{
    // update last xpos & ypos
    this->lastXpos = this-> xpos;
    this->lastYpos = this-> ypos;
}

void Piassa::setXpos(int x)
{
    // update last xpos & ypos
   // updateLastPos();
    setLastXpos(this->xpos );

    // set new xpos
    this->xpos = x;
    this->rectPissa.setPosition(sf::Vector2f(float(xpos), float(ypos)));
}

void Piassa::setYpos(int y)
{
    // update last xpos & ypos
    //updateLastPos(); 
    setLastYpos(this->ypos );

    // set new ypos
    this->ypos = y;
    this->rectPissa.setPosition(sf::Vector2f(float(xpos), float(ypos)));

}

void Piassa::setLastXpos(int x)
{
    this->lastXpos = x;
}

void Piassa::setLastYpos(int y)
{
    this->lastYpos = y;
}

sf::RectangleShape Piassa::getRectPiassa()
{
    return this->rectPissa;
}

int Piassa::getOutlineThinkness()
{
    std:: cout << "valuer par def = " << outlineThickness << std::endl;
    return outlineThickness;
}
