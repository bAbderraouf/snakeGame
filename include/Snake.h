#ifndef _Snake_H_
#define _Snake_H_

#include "Game.h"
#include "Plan2D.h"
#include "ctime"
#include "Douda.h"
#include "Piassa.h"
#include "Makla.h"
//#include "gameOver.h"
#include <cmath>
#include <iostream>
#include <SFML/Audio.hpp>


class Snake : public Game {
    
    public :
        Snake();
        ~Snake();

        Snake(bool wall , bool sound, bool doubleSense, bool withCollisions);

        /*  Public Functions */
        void setup() ;
        void setup(bool wall , bool sound, bool doubleSense, bool withCollisions);
        void setupConfigurationFlags(bool wall = false , bool sound = true, bool doubleSense = false, bool withCollisions = true);

        void input() override;
    
        void deleteAllGameObjects();
        void initText() override;


        //void input() ;
        void update() ;
        void render() ;

        void renderDouda();
        void renderText(sf::RenderTarget &target) override;
        void renderCheckboxes();
    

        // update sub functions
        void updateText() ;
        void updateEnergy() ;
        void updateDouda();
        void generateMakla();
        void generatePosMakla(float &xMakla , float &yMakla);
        void updateSound();
        void updatePlan2D();
        void updateFlags();
        void updateCheckboxes();

        void showGameOverMessage();
        
        

        //supplimentary functions
        void setUnsetWalls();
        void playSound(std::string file, sf::SoundBuffer &_soundBuffer ,sf::Sound &_sound, bool loop);
        void getCurrentSettings(bool &wall, bool &sound, bool &doubleSense, bool &collisions);


    private :

        float size7aba;  // le size est a definir par le user plutard
        float distanceBetween7abat;

        enum Dir{LEFT, RIGHT, UP, DOWN, NEUTRAL};
        Dir lastDir, nextDir;
        
        bool    crash_Flag, 
                wall_exist_flag,
                double_sens_flag,
                collision_between_douda_parts_isActivated_flag,
                sound_activated_flag;

        /* game objects */
        
        
        Plan2D *plan2D;
        Piassa *head;
        std::vector<Piassa> douda;
        Makla *makla;

        sf::Clock startingTimer;
        sf::Text    scoreText, 
                    gameOverText,
                    timeText , 
                    settingText_wall,  
                    settingText_sound, 
                    settingText_doubleSenses,
                    settingText_noCollisions;

        sf::Sound sound , bipSound , gameOverSound;
        sf::SoundBuffer soundBuffer, bipSoundBuffer , gameOverSoundBuffer;

        // checkbox list

        sf::RectangleShape  wall_checkbox , 
                            sound_checkbox,
                            doubleSense_checkbox,
                            collisions_checkbox;


        /* Private fucntions */
        void initializeVariables()  ;
        void initCheckboxes();
        void calculateScore() ; 
        
    

};

#endif