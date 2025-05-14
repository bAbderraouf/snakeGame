#ifndef _Plan2D_H_
#define _Plan2D_H_


#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>

class Plan2D{


    private:

        float sizeBox;
        std::vector<std::vector<bool>> matrix;
       
        float xpos2dPlan , ypos2dPlan;
        float xSize2dPlan , ySize2dPlan;
        float widthCadre;

        float margeDroite, margeBas;

        int nombreCollones , nombreLignes;
        

        unsigned int matrixRows , matrixColls;

        bool wall_exists;

        sf::RectangleShape cadre;

    public :

        Plan2D(unsigned int H, unsigned int L , unsigned int S );
        Plan2D(unsigned int L, unsigned int H, float size7aba,  float distanceBetween7abat , int nombreCollones , int nombreLignes , float margeDroite , float margeBas , bool wall);
        ~Plan2D();

        void setWallFlag(bool state);
        bool getWallFlagState();
        float getXpos2dPlan();
        float getYpos2dPlan();
        float getXsize2dPlan();
        float getYsize2dPlan();
        float getWidthCadre();
        int getNombreCollones();
        int getNombreLignes();
        float getMargeDroite();
        float getMargeBas();
        sf::RectangleShape getCadre();
    
};


#endif