#include "Snake.h"
#include <iostream>
#include <SFML/System.hpp>
//#include <SFML/Window.hpp>
#include <thread>
//#include <QtWidgets/QMainWindow>

using namespace std;

int main()
{

    // sound play
    //------------

    //std::thread t(f); //soundThread(playSound1 , "doodle_pop.ogg");
    //soundThread.join();


    std::srand(static_cast<unsigned> (time(NULL)));  // intialising srand

    // setup()  
    //--------

    bool wall = false, sound = true, doubleSense = false, withCollisions = true;
    Snake* game = new Snake; //( wall,  sound,  doubleSense,  withCollisions);

    // game loop 
    //-----------    

    while (game->getIfWindowIsOpen())
    {

        // Input() 
        game->input();

        // update()  = logic 
        game->update();

        // render() 
        game->render();

        if (game->getGameOver())
        {
            // 1. get the actual settings
            game->getCurrentSettings(wall, sound, doubleSense, withCollisions);

            // 1.5 wait until a key is pressed
            sf::sleep(sf::seconds(0.5)); //getchar(); 

            // 2. delete all objets 
            game->deleteAllGameObjects();

            // 3. renit with same setings
            game->setup(wall, sound, doubleSense, withCollisions);

        }

        //sf::sleep(sf::seconds(0.125));    

    }

    return 0;
}