    #include "Game.h"
    

    /*-------------------------------*/
    /* Private fucntions */
    /*-------------------------------*/

    void Game::initializeVariables()
    {
        this->fenetre = NULL;
        // no need to initialise event (it has a default initialisation)
        // video mode 
        this->videoMode.height = 600 ;
        this->videoMode.width = 800;

        this->gameOver = false;
        this->score = 0;
        this->mouseClicked = false;
        this->health = 20;
        this->energy = 0;

        this->button.left = false;
        this->button.right = false;
        this->button.space = false;
        this->button.up = false;
        this->button.down = false;

        this->initFont();
        this->initText();
 

    }

    void Game::initWindow(std :: string gameName)
    {
        this->fenetre = new sf::RenderWindow( this->videoMode , gameName , sf::Style::Titlebar  | sf::Style::Close );  // titre + fermeture
        this->fenetre->setFramerateLimit(10);  // min = 10, max = 60 (ou 50)
    }

 

    void Game::initFont()
    {
        if ( this->font.loadFromFile("assets/fonts/Dosis-Light.ttf") == false )
            std::cout << "ERROR :: Font :: Failed to load.\n";
        if ( this->gameOverFont.loadFromFile("assets/fonts/PixellettersFull.ttf") == false )
            std::cout << "ERROR :: Font :: Failed to load.\n";
    }

    void Game::initText()
    {
        this->guiText.setFont(this->font);
        this->guiText.setCharacterSize(22);
        this->guiText.setFillColor(sf::Color::Yellow);
        //this->guiText.setOutlineColor(sf::Color::White);
        // this->guiText.setOutlineThickness(1.f);
        this->guiText.setString(""); // initialised to nothing

    }

 


    /*-------------------------------*/
    /*  Public Functions */
    /*-------------------------------*/

    /*-------------------------------*/
    /*  constructor / destructor   */
    /*-------------------------------*/
    Game::Game()
    {
        // configure the setup of the game
       // this->setup();  // class abstraite
    }


    Game::~Game()
    {
        delete this->fenetre; 
    }


    /*-------------------------------*/
    /* Accessors */
    /*-------------------------------*/

    const bool Game::getIfWindowIsOpen() const
    {
        return this->fenetre->isOpen();
    }

    bool Game::getGameOver() const
    {
        return this->gameOver;
    }



    void Game::input()
    {
        while (this->fenetre->pollEvent(this->evnt))  // we dont have to use this (just to see that its a part of the classs )
        {
            switch (this->evnt.type) 
            {
                case sf::Event::Closed:
                    this->fenetre->close();
                    break;
                
                case sf::Event::KeyPressed:
                    if(evnt.key.code == sf::Keyboard::Escape)
                    {
                        this->fenetre->close();
                        break;
                    }
                    if(this->evnt.key.code == sf::Keyboard::Left)
                    {
                        this->button.left = true;
                        break;
                    }
                    if(this->evnt.key.code == sf::Keyboard::Right)
                    {
                        this->button.right = true;
                        break;
                    }
                    if(this->evnt.key.code == sf::Keyboard::Space)
                    {
                        this->button.space = true;
                        break;
                    }
                    if(this->evnt.key.code == sf::Keyboard::Up)
                    {
                        this->button.up = true;
                        break;
                    }
                    if(this->evnt.key.code == sf::Keyboard::Down)
                    {
                        this->button.down = true;
                        break;
                    }
                 
              

                case sf::Event::KeyReleased :
                    if(this->evnt.key.code == sf::Keyboard::Left)
                    {
                        this->button.left = false;
                        break;
                    }
                    if(this->evnt.key.code == sf::Keyboard::Right)
                    {
                        this->button.right = false;
                        break;
                    }
                    if(this->evnt.key.code == sf::Keyboard::Space)
                    {
                        this->button.space = false;
                        break;
                    }
                     if(this->evnt.key.code == sf::Keyboard::Up)
                    {
                        this->button.up = false;
                        break;
                    }
                    if(this->evnt.key.code == sf::Keyboard::Down)
                    {
                        this->button.down = false;
                        break;
                    }

            }
        }

    }







    /* Other functions */
    // update sub function

    void Game::updateMousePosition()
    {
        this->mousePosWindow = sf::Mouse::getPosition(*this->fenetre);
        this->mousePosView = this->fenetre->mapPixelToCoords(this->mousePosWindow);  // its a coordinate from pixel in float
    }


 void Game::renderText(sf::RenderTarget &target)
    {   
        target.draw(guiText);  // draw the text on the selected target (ex: window or other targets)
    }