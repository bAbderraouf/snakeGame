#include "Plan2D.h"


Plan2D::Plan2D(unsigned int H, unsigned int L,unsigned int S)
{

    // a modifier après
    xpos2dPlan = 200;
    ypos2dPlan = 15;
    widthCadre = 1;   // il va consomer des dimensions du bas et de la droite
                        // il ne consome pas de haut et de la gauche (il prends de lexterieur pour ces 2 là)

   //  douda = nullptr;
    // douda = new Douda(xpos2dPlan, ypos2dPlan , S );

    this->sizeBox = S;
    xSize2dPlan = L - xpos2dPlan - widthCadre - 14;
    ySize2dPlan = H - ypos2dPlan - widthCadre - 14 ; // 14 jusute pour corriger 


    // init cadre 

    this->cadre.setSize(sf::Vector2f(static_cast<float>(xSize2dPlan), static_cast<float>(ySize2dPlan) ));
    this->cadre.setFillColor(sf::Color(70,15,10,100));
    this->cadre.setOutlineColor(sf::Color::Yellow);
    this->cadre.setOutlineThickness(static_cast<float>(widthCadre));
    this->cadre.setPosition(sf::Vector2f(static_cast<float>(xpos2dPlan), static_cast<float>(ypos2dPlan)));
 
}

Plan2D::Plan2D(unsigned int L, unsigned int H,  float size7aba, float distanceBetween7abat, int nombreCollones, int nombreLignes ,float margeDroite , float margeBas, bool wall)
{

    this->nombreCollones =  nombreCollones;
    this->nombreLignes =    nombreLignes;

    this->margeDroite =     margeDroite ;
    this->margeBas =        margeBas;

    sizeBox = size7aba;

    // calcul largeur
    float largeurPlan2D = nombreCollones*size7aba  + (nombreCollones + 1)* distanceBetween7abat;

    //calcul hauteur
    float hauteurPlan2D = nombreLignes*size7aba + (nombreLignes + 1 )*distanceBetween7abat;

    xpos2dPlan = L - largeurPlan2D - margeDroite;
    ypos2dPlan = H - hauteurPlan2D - margeBas;

    xSize2dPlan = largeurPlan2D;
    ySize2dPlan = hauteurPlan2D; // 14 jusute pour corriger 
    
    setWallFlag(wall);
   
    

    // init cadre 

    this->cadre.setSize(sf::Vector2f(static_cast<float>(xSize2dPlan), static_cast<float>(ySize2dPlan) ));
    this->cadre.setFillColor(sf::Color(70,15,10,255));
    this->cadre.setPosition(sf::Vector2f(static_cast<float>(xpos2dPlan), static_cast<float>(ypos2dPlan)));

}

Plan2D::~Plan2D()
{
  
}

void Plan2D::setWallFlag(bool state)
{
    wall_exists = state;
    sf::Color wall_color ;
    if(state)
    {
        widthCadre = 3;
        wall_color = sf::Color(125,125,125, 115); //sf::Color(255,255,255,255);
    }
    else
    {
        widthCadre = 1;
        wall_color = sf::Color::Yellow;
    }
          
    this->cadre.setOutlineColor(wall_color);
    this->cadre.setOutlineThickness(static_cast<float>(widthCadre));
}

bool Plan2D::getWallFlagState()
{
    return wall_exists;
}

float Plan2D::getXpos2dPlan()
{
    return this->xpos2dPlan;
}

float Plan2D::getYpos2dPlan()
{
    return this->ypos2dPlan;
}

float Plan2D::getXsize2dPlan()
{
    return xSize2dPlan;
}

float Plan2D::getYsize2dPlan()
{
    return this->ySize2dPlan;
}

float Plan2D::getWidthCadre()
{
    return widthCadre;
}

int Plan2D::getNombreCollones()
{
    return nombreCollones;
}

int Plan2D::getNombreLignes()
{
    return nombreLignes;
}

float Plan2D::getMargeDroite()
{
    return margeDroite;
}

float Plan2D::getMargeBas()
{
    return margeBas;
}

sf::RectangleShape Plan2D::getCadre()
{
    return this->cadre;
}

