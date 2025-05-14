#include "Snake.h"

Snake::Snake() 
{
    Snake::setup();
}

Snake::~Snake()
{
    delete plan2D;
    delete head;
    delete makla;
    //delete gameOverWindow;

}

Snake::Snake(bool wall, bool sound, bool doubleSense, bool withCollisions)
{
    setup(wall,  sound,  doubleSense,  withCollisions);
}

/********************************
 *    Initial Setup
*********************************/

void Snake::setup()
{
    Snake::initializeVariables();
    Game::initWindow("Snake Game");
}

void Snake::setup(bool wall, bool sound, bool doubleSense, bool withCollisions)
{
    setup();
    setupConfigurationFlags(wall,  sound,  doubleSense,  withCollisions);
}

void Snake::setupConfigurationFlags(bool wall, bool soundActivated, bool doubleSense, bool withCollisions)
{
    wall_exist_flag = wall;
    double_sens_flag = doubleSense;
    collision_between_douda_parts_isActivated_flag = withCollisions;
    sound_activated_flag = soundActivated;

    // corect the collision flag
    if (double_sens_flag == true)
        collision_between_douda_parts_isActivated_flag = false;

    if(sound_activated_flag)
        playSound("doodle_pop.ogg", this->soundBuffer ,this->sound, true);
    
}



void Snake::deleteAllGameObjects()
{
    delete fenetre;
    douda.clear();
    delete plan2D;
    delete head;
    delete makla;
}

 /* Private fucntions */
 
void Snake::initializeVariables()
{
    Game::initializeVariables();

    // start clock
    startingTimer.restart();


    // additional code specifc to this game

    this->gameOver = false;
    this->videoMode.width = 600;
    this->videoMode.height = 700;

    // next & last direction
    nextDir = NEUTRAL;
    lastDir = NEUTRAL;
     
    crash_Flag = false;
    
    // set default config
    //-------------------
    setupConfigurationFlags();

    // init checkboxes
    //-----------------
    initCheckboxes();

    unsigned int h = Game::videoMode.height , l = Game::videoMode.width  ;

    // plan2D
    plan2D = nullptr;
    size7aba = 25;  // doit ettre entier
                // le size est a definir par le user plutard


    // 1er constructeur of plan2D
    //----------------------------
    // plan2D = new Plan2D(h , l , size7aba);

    

    distanceBetween7abat = 3 ; // doit etre entier
    int     nombreCollones = 14 , 
            nombreLignes = 23;
    float   margeDroite = 20, 
            margeBas = 25;

    // generate plan2D : 2eme constructeur 
    //-------------------------------------

    plan2D = new Plan2D(l , h,  size7aba,  distanceBetween7abat, nombreCollones, nombreLignes , margeDroite , margeBas , wall_exist_flag);

    // generate piassa   
    //-----------------
    
    float   xOrigin = plan2D->getXpos2dPlan() + distanceBetween7abat, 
            yOrigin = plan2D->getYpos2dPlan() + distanceBetween7abat;
        
    head =  nullptr;
    head =  new Piassa(xOrigin  , yOrigin  , size7aba , 1);
    douda.push_back(*head);
   

    // generate makla
    //-----------------
    generateMakla();

}

void Snake::initCheckboxes()
{

    // wall_checkbox , 

    this->wall_checkbox.setSize(sf::Vector2f(10.f, 10.f));
    this->wall_checkbox.setFillColor(sf::Color::Black);
    this->wall_checkbox.setOutlineColor(sf::Color::White);
    this->wall_checkbox.setOutlineThickness(3.f);
    this->wall_checkbox.setPosition(sf::Vector2f(20.f, 300.f));

    // sound_checkbox,

    this->sound_checkbox.setSize(sf::Vector2f(10.f, 10.f));
    this->sound_checkbox.setFillColor(sf::Color::Black);
    this->sound_checkbox.setOutlineColor(sf::Color::White);
    this->sound_checkbox.setOutlineThickness(3.f);
    this->sound_checkbox.setPosition(sf::Vector2f(20.f, 325.f));

    // doubleSense_checkbox;

    this->doubleSense_checkbox.setSize(sf::Vector2f(10.f, 10.f));
    this->doubleSense_checkbox.setFillColor(sf::Color::Black);
    this->doubleSense_checkbox.setOutlineColor(sf::Color::White);
    this->doubleSense_checkbox.setOutlineThickness(3.f);
    this->doubleSense_checkbox.setPosition(sf::Vector2f(20.f, 350.f));

    // collisions_checkbox

    this->collisions_checkbox.setSize(sf::Vector2f(10.f, 10.f));
    this->collisions_checkbox.setFillColor(sf::Color::Black);
    this->collisions_checkbox.setOutlineColor(sf::Color::White);
    this->collisions_checkbox.setOutlineThickness(3.f);
    this->collisions_checkbox.setPosition(sf::Vector2f(20.f, 375.f));

}

 void Snake::initText()
    {
        this->scoreText.setFont(this->font);
        this->scoreText.setCharacterSize(22);
        this->scoreText.setFillColor(sf::Color(125,125,125, 115));
        this->scoreText.setString(""); // initialised to nothing

        // time text
        this->timeText.setFont(this->font);
        this->timeText.setCharacterSize(22);
        this->timeText.setFillColor(sf::Color(125,125,125, 115));
        this->timeText.setString(""); // initialised to nothing

        // gameoverText
        this->gameOverText.setFont(this->gameOverFont);
        this->gameOverText.setString("");
        this->gameOverText.setFillColor( sf::Color::Black  );
        this->gameOverText.setCharacterSize(65);
        this->gameOverText.setOutlineThickness(2);
        this->gameOverText.setOutlineColor(sf::Color::Yellow);

        // setting text
        this->settingText_wall.setFont(this->font);
        this->settingText_wall.setCharacterSize(22);
        this->settingText_wall.setFillColor(sf::Color(125,125,125, 115));
        this->settingText_wall.setString(""); // initialised to nothing

            //settingText_sound
        this->settingText_sound.setFont(this->font);
        this->settingText_sound.setCharacterSize(22);
        this->settingText_sound.setFillColor(sf::Color(125,125,125, 115));
        this->settingText_sound.setString(""); // initialised to nothing

         // settingText_doubleSenses
        this->settingText_doubleSenses.setFont(this->font);
        this->settingText_doubleSenses.setCharacterSize(22);
        this->settingText_doubleSenses.setFillColor(sf::Color(125,125,125, 115));
        this->settingText_doubleSenses.setString(""); // initialised to nothing
        
         // settingText_doubleSenses
        this->settingText_noCollisions.setFont(this->font);
        this->settingText_noCollisions.setCharacterSize(22);
        this->settingText_noCollisions.setFillColor(sf::Color(125,125,125, 115));
        this->settingText_noCollisions.setString(""); // initialised to nothing
    }




/**********************
 *    Input()
***********************/



void Snake::input()
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
                case sf::Event::MouseButtonPressed:
                    if(this->evnt.mouseButton.button == sf::Mouse::Left)
                    {
                        // if mouse aerea = checkbox aera => set checkboxchecked
                        
                        // wall
                        if( (wall_checkbox.getGlobalBounds().contains(sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y)) )
                            || (settingText_wall.getGlobalBounds().contains(sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y) ) ) )
                            wall_exist_flag = ! wall_exist_flag;

                        // sound
                        if( (sound_checkbox.getGlobalBounds().contains(sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y))) 
                        || (settingText_sound.getGlobalBounds().contains(sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y) ) ) )
                            sound_activated_flag = ! sound_activated_flag;

                        //double sense
                        if((doubleSense_checkbox.getGlobalBounds().contains(sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y))) || 
                            (settingText_doubleSenses.getGlobalBounds().contains(sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y) ) ) )
                            double_sens_flag = ! double_sens_flag;

                        // collisions_checkbox
                        if((collisions_checkbox.getGlobalBounds().contains(sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y))) || 
                            (settingText_noCollisions.getGlobalBounds().contains(sf::Vector2f(evnt.mouseButton.x, evnt.mouseButton.y) ) ) )
                        {
                            collision_between_douda_parts_isActivated_flag = !collision_between_douda_parts_isActivated_flag;
                        }
                            

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


/**********************************************
 *          Update functions
***********************************************/







void Snake::update(){

    /*
        IMPORTANT : 
        for me the difenition of update() is the switch(event.type) => we are taking actions according to inputs
    */
    
    // get mouse position (relative to the screen)
    //std::cout << "Mouse pos: " << sf::Mouse::getPosition().x  << " , " << sf::Mouse::getPosition().y << std::endl;

    // get mouse position (relative to the window)
    //std::cout << "Mouse pos: " << sf::Mouse::getPosition(*this->fenetre).x  << " , " << sf::Mouse::getPosition(*this->fenetre).y << std::endl;
        

        if( this->gameOver == false)
        {
            this->updateText();
            this->updateEnergy();
            this->updateFlags();
            this->updateCheckboxes();
            this->updateDouda();
            this->calculateScore();
            this->updateSound();
            this->updatePlan2D();
            
            
            
        }

        if(this->health <= 0 || crash_Flag == true)
        {
            sound.pause();

            sf::sleep(sf::seconds(1));
            
            this->playSound("gameOver.wav",gameOverSoundBuffer , gameOverSound, false);

            this->showGameOverMessage();

            //sf::sleep(sf::seconds(3));

            // afficher le gameOver message
            //this->gameOverWindow = new GameOver(500, 100);
            //this->gameOverWindow->afficheGameOver();

            // attendre une action pour recomencer le game

            this->gameOver = true;
        }
            
        
        
}

//---------------
// update Text
//---------------

void Snake::updateText(){

    // way1
    std::stringstream ss;
    ss << "Score : " << this->score 
        << "\nHealth : " << this->health   
        << "\nEnergy : " << this->energy ;// then use : ss.str()

        // way2
    sf::Time elapsedTime = startingTimer.getElapsedTime();
    unsigned int totalElapsedSeconds = elapsedTime.asSeconds(),
                elapsedMinutes = 0 ,
                 elapsedHours = 0,
                 elapsedSeconds = 0;

    // count H:Min:Sec
    elapsedHours = totalElapsedSeconds / 3600;
    elapsedMinutes = (totalElapsedSeconds % 3600) / 60;
    elapsedSeconds = (totalElapsedSeconds % 3600) % 60;

    /*
    if(elapsedSeconds > 15)
        this->sound_activated_flag = false;
    if(elapsedSeconds > 45 && elapsedSeconds <= 59)
    {
        this->wall_exist_flag = true;
        this->sound_activated_flag = true;
    }
    if(elapsedMinutes == 1 )
    {
        this->wall_exist_flag = false;
        this->sound_activated_flag = false; 
        this->double_sens_flag = true;
    }*/
        

    std::string scoreTextString , 
                timeTextString , 
                gameOverTextString,
                settingText_sound_String , 
                settingText_wall_String ,  
                settingText_doubleSense_String,
                settingText_noCollisions_string;

    scoreTextString = "   Score : " + std::to_string(this->score) 
                    //+ "\n   Health : " + std::to_string(this->health)  // then use s
                    //+ "\n   Energy : " + std::to_string(this->energy)
                    + "\n   Size : " + std::to_string(this->douda.size());

    timeTextString  = "Elapsed Time : " + std::to_string(elapsedHours) + "h "
                    + std::to_string(elapsedMinutes) + "m "
                    + std::to_string(elapsedSeconds) + "s.";

    gameOverTextString = "Game Over ! \n Score: " + std::to_string(this->score)  
                +"\n Size:" + std::to_string(this->douda.size())
                +"\n Time: " 
                + std::to_string(elapsedHours) + "h "
                + std::to_string(elapsedMinutes) + "m "
                + std::to_string(elapsedSeconds) + "s.\n\nPress any key.."; 

    settingText_wall_String = "Wall activated.";   
    settingText_sound_String = "Sound activated."; 
    settingText_doubleSense_String = "Double sense."; 
    settingText_noCollisions_string = "Collisions activated.";

        // update ScoreText
    this->scoreText.setString(scoreTextString);
    this->scoreText.setPosition( 6 , plan2D->getYpos2dPlan());
    this->scoreText.setFillColor( sf::Color::Yellow  );

        // update timeText
    this->timeText.setString(timeTextString);
    this->timeText.setPosition(  plan2D->getXpos2dPlan() , plan2D->getYpos2dPlan() + plan2D->getYsize2dPlan());
    this->timeText.setFillColor( sf::Color::Yellow  );
    this->timeText.setCharacterSize(20);
    
        // update gameOverText
    this->gameOverText.setString(gameOverTextString);
    this->gameOverText.setPosition(  plan2D->getXpos2dPlan() + 10  , plan2D->getYpos2dPlan() /2 );
    this->gameOverText.setFillColor( sf::Color::Black  );
    this->gameOverText.setCharacterSize(65);
    this->gameOverText.setOutlineThickness(2);
    this->gameOverText.setOutlineColor(sf::Color::Yellow);

    // update setting texts
        // wall
    this->settingText_wall.setString(settingText_wall_String);
    this->settingText_wall.setPosition(  wall_checkbox.getPosition().x + wall_checkbox.getSize().x + 10.f , 
                    wall_checkbox.getPosition().y - wall_checkbox.getSize().y + 2.f);
    this->settingText_wall.setFillColor( sf::Color(125, 125, 125, 115) );
    this->settingText_wall.setCharacterSize(20);

        // sound
    this->settingText_sound.setString(settingText_sound_String);
    this->settingText_sound.setPosition(  sound_checkbox.getPosition().x + sound_checkbox.getSize().x + 10.f, 
                    sound_checkbox.getPosition().y - sound_checkbox.getSize().y + 2.f);
    this->settingText_sound.setFillColor( sf::Color(125, 125, 125, 115) );
    this->settingText_sound.setCharacterSize(20);

        // double sense
    this->settingText_doubleSenses.setString(settingText_doubleSense_String);
    this->settingText_doubleSenses.setPosition(  doubleSense_checkbox.getPosition().x + doubleSense_checkbox.getSize().x + 10.f, 
                    doubleSense_checkbox.getPosition().y - doubleSense_checkbox.getSize().y + 2.f);
    this->settingText_doubleSenses.setFillColor( sf::Color(125, 125, 125, 115) );
    this->settingText_doubleSenses.setCharacterSize(20);

        // collisions
    this->settingText_noCollisions.setString(settingText_noCollisions_string);
    this->settingText_noCollisions.setPosition(  collisions_checkbox.getPosition().x + collisions_checkbox.getSize().x + 10.f, 
                    collisions_checkbox.getPosition().y - collisions_checkbox.getSize().y + 2.f);
    this->settingText_noCollisions.setFillColor( sf::Color(125, 125, 125, 115) );
    this->settingText_noCollisions.setCharacterSize(20);
}

//---------------
// update energy
//---------------

void Snake::updateEnergy(){
     this->energy = static_cast<int>(score / 20) ; 
        if(this->energy == 10)
        {
            this->energy = 0;
            this->health += 1;
        }
}

//---------------
// update douda
//---------------

void Snake::updateDouda()
{    

    // check actual button state
    //---------------------------
    if ( button.down  ){

        lastDir = nextDir; 
        
        if(double_sens_flag == false)
        {
            if (lastDir != UP)
            {
                // check if 180d
                nextDir = DOWN;
            } 
        } 
        else
            nextDir = DOWN;      
    }   
    if ( button.up){

        lastDir = nextDir;

        if(double_sens_flag == false)
        {
            if( lastDir != DOWN )
            { 
                // check if 180d
                nextDir = UP;
            }
        }
        else
            nextDir = UP; 
         
    }
    if ( button.left){

        lastDir = nextDir;

        if(double_sens_flag == false)
        {
            if( lastDir != RIGHT )
            {
                // check if 180d
                nextDir = LEFT;
            }
        }
        else
            nextDir = LEFT; 
    }
    if ( button.right){

        lastDir = nextDir;

        if(double_sens_flag == false)
        {
            if( lastDir != LEFT )
            {   
                // check if 180d
                nextDir = RIGHT;
            }
        }
        else
            nextDir = RIGHT; 
    }

    // update douda state
    //--------------------
    float       xpos = douda[0].getXpos(),
                ypos = douda[0].getYpos();

    float     step =  size7aba + distanceBetween7abat;

    int     sizeDouda = douda.size();

    
    // set new postions
    //-----------------
    if ( nextDir == DOWN ){
        
        douda[0].setYpos(ypos + step);     

        // update last xpos if direction changed
        if(  lastDir == LEFT ||  lastDir == RIGHT)
            douda[0].setLastXpos(xpos);
    }
    if ( nextDir == UP )
    {
    
        douda[0].setYpos(ypos - step);
        
        // update last xpos if direction changed
        if(   lastDir == LEFT ||  lastDir == RIGHT)
            douda[0].setLastXpos(xpos);
    }
    if ( nextDir == LEFT )
    {
        douda[0].setXpos(xpos - step);
      
         // update last ypos if direction changed
        if(   lastDir == UP ||  lastDir == DOWN)
            douda[0].setLastYpos(ypos);
    }
    if (  nextDir == RIGHT  )
    {
        douda[0].setXpos(xpos + step);     

        // update last ypos if direction changed
        if(   lastDir == UP ||  lastDir== DOWN)
            douda[0].setLastYpos(ypos); 
    }

    // add elements to douda
    //-----------------------
    if(douda[0].getXpos() == makla->getXpos() && douda[0].getYpos()== makla->getYpos())
    {
        Piassa lastDoudaElement = douda[sizeDouda - 1];
        douda.push_back(lastDoudaElement);
        
        if(sound_activated_flag)
            playSound("whoosh.wav" , this->bipSoundBuffer , this->bipSound , false);
    }

    // attach elements
    //-----------------
    for(int i = 0 ; i< sizeDouda - 1; i++)
    {
            douda[i+1].setYpos( douda[i].getLastYpos() );
            douda[i+1].setXpos( douda[i].getLastXpos() );
    }


    // check plan2D limite
    //---------------------
    bool    xCondRight = (xpos >= (plan2D->getXsize2dPlan() + plan2D->getXpos2dPlan() - step ) ) && ( nextDir == RIGHT) ,
            xCondLeft = (xpos <=  (plan2D->getXpos2dPlan()  + distanceBetween7abat )) && ( nextDir== LEFT),
            yCondUp =  (ypos <= (plan2D->getYpos2dPlan() + distanceBetween7abat )) && ( nextDir == UP),
            yCondDown = (ypos >= (  plan2D->getYsize2dPlan() + plan2D->getYpos2dPlan() - step )) && ( nextDir== DOWN);

    int   xposMax =     plan2D->getXsize2dPlan() + plan2D->getXpos2dPlan() - step  ,
          xposMin =     plan2D->getXpos2dPlan() + distanceBetween7abat,
          yposMax =     plan2D->getYsize2dPlan() + plan2D->getYpos2dPlan() - step  ,
          yposMin =     plan2D->getYpos2dPlan() + distanceBetween7abat;

    if( xCondLeft ){

        if( wall_exist_flag)
        {
            crash_Flag = true;
            douda[0].setXpos(xposMin );
        }
            
        else {

            douda[0].setXpos(xposMax );
            xCondLeft = false;
        }    
        
    }
    if( xCondRight ){

        if( wall_exist_flag)
        {
            crash_Flag = true;
            douda[0].setXpos(xposMax );
        }

        else {

            douda[0].setXpos(xposMin );
            xCondRight = false;
        } 
        
    }
    if( yCondUp ){

        if( wall_exist_flag)
        {
            crash_Flag = true;
            douda[0].setYpos(yposMin );
        }

        else {
            douda[0].setYpos(yposMax );
            yCondUp = false;
        } 
        
    }
    if( yCondDown ){

        if( wall_exist_flag)
        {
            crash_Flag = true;
            douda[0].setYpos(yposMax );
        }
        else {
            douda[0].setYpos(yposMin );
            yCondDown = false;
        } 
        
    }
     
   
    // check collisions
    //------------------
    if( collision_between_douda_parts_isActivated_flag )
    {
        for(int i = 1 ; i< sizeDouda ; i++)
        {
            float   xHead = douda[0].getXpos() , yhead = douda[0].getYpos() ,
                    xOthers = douda[i].getXpos() , yOthers = douda[i].getYpos() ;
            // cas 1

            bool    conditionUp =  ( (((xHead - xOthers < step ) && (xHead -xOthers >= 0 ) ) || ((  xOthers - xHead < step ) && (xOthers -xHead >= 0))  )  
                                        &&  (yhead < yOthers + step)  && (yhead - yOthers >= 0) &&  (nextDir == UP) ),

                    conditionDown = ( ( ((xHead - xOthers < step ) && (xHead -xOthers >= 0 ) ) || ((  xOthers - xHead < step ) && (xOthers -xHead >= 0))  )  
                                        && (yOthers < yhead + step)  && ( yOthers - yhead>= 0) &&   (nextDir == DOWN) ),

                    conditionRight = ( ( ((yhead - yOthers < step ) && (yhead -yOthers >= 0 ) ) || ((  yOthers - yhead < step ) && (yOthers -yhead >= 0))  )  
                                        &&  (xOthers < xHead + step)  && ( xOthers - xHead>= 0) &&   (nextDir == RIGHT) ),

                    conditionLeft = ( ( ((yhead - yOthers < step ) && (yhead -yOthers >= 0 ) ) || ((  yOthers - yhead < step ) && (yOthers -yhead >= 0))  )  
                                        &&   (xHead  < xOthers + step)  && (  xHead- xOthers>= 0) &&   (nextDir == LEFT) );

            if (conditionUp)
                crash_Flag = true;
                //std::cout << "collision UP" << std::endl;
            if (conditionDown)
                crash_Flag = true;
                //std::cout << "collision Down" << std::endl;
            if (conditionRight)
                crash_Flag = true;
                //std::cout << "collision Right" << std::endl;
            if (conditionLeft)
                crash_Flag = true;
                //std::cout << "collision Left" << std::endl;        
        } 
    }

}

//---------------
// update Makla
//---------------

void Snake::generateMakla()
{

    makla = nullptr;
    float    xMakla, yMakla;

    generatePosMakla(xMakla , yMakla);

    // check if x,y are used
    for(auto &e : this->douda)
    {
        //while(xMakla == e.getXpos() && yMakla ==  e.getYpos()) 
        // pour eviter le temps important perdu (on limite a 5itterations)
        for(int i = 0 ; i < 5 ; i++)
        {
            generatePosMakla(xMakla , yMakla);
        }
    }

    makla = new Makla(xMakla, yMakla , size7aba );
}


void Snake::generatePosMakla(float &xMakla, float &yMakla)
{
    int     nbreX, nbreY;
    float   xplan2D =  plan2D->getXpos2dPlan() , 
            yplan2D =  plan2D->getYpos2dPlan();
    
    srand(time(0));

    nbreX = rand() % plan2D->getNombreCollones(), 
    nbreY = rand() % plan2D->getNombreLignes(); 

    xMakla = nbreX*(size7aba + distanceBetween7abat) + distanceBetween7abat + xplan2D , 
    yMakla = nbreY*(size7aba + distanceBetween7abat) + distanceBetween7abat + yplan2D  ;  // a modifier par des random values
}

//---------------
// update sound
//---------------

void Snake::updateSound()
{
    if( !sound_activated_flag)
        sound.pause();
    else if(sound.getStatus() == sf::SoundSource::Status::Paused && sound_activated_flag)
        sound.play();
        
}

//---------------
// update plan2D
//---------------

void Snake::updatePlan2D()
{
    // check if the state is changed then set the new state
    if(  (plan2D->getWallFlagState() && !wall_exist_flag) || ( !plan2D->getWallFlagState() && wall_exist_flag) )
        plan2D->setWallFlag(wall_exist_flag);

}

void Snake::updateFlags()
{
    if(double_sens_flag)
        collision_between_douda_parts_isActivated_flag = false;
}

//--------------------
// update checkboxes
//--------------------

void Snake::updateCheckboxes()
{
    // wall_checkbox
    
    if(wall_exist_flag)
    {
        this->wall_checkbox.setFillColor(sf::Color::Yellow);
        this->wall_checkbox.setOutlineColor(sf::Color(125,125,125, 115));
    }
    else
    {
        this->wall_checkbox.setFillColor(sf::Color::Black);
        this->wall_checkbox.setOutlineColor(sf::Color(125,125,125, 115));
    }

    // sound_activated_flag

    if(sound_activated_flag)
    {
        this->sound_checkbox.setFillColor(sf::Color::Yellow);
        this->sound_checkbox.setOutlineColor(sf::Color(125,125,125, 115));
    }
    else
    {
        this->sound_checkbox.setFillColor(sf::Color::Black);
        this->sound_checkbox.setOutlineColor(sf::Color(125,125,125, 115));
    }

    // double_sens_flag

     if(double_sens_flag)
    {
        this->doubleSense_checkbox.setFillColor(sf::Color::Yellow);
        this->doubleSense_checkbox.setOutlineColor(sf::Color(125,125,125, 115));
    }
    else
    {
        this->doubleSense_checkbox.setFillColor(sf::Color::Black);
        this->doubleSense_checkbox.setOutlineColor(sf::Color(125,125,125, 115));
    }

    // collisions

    if(collision_between_douda_parts_isActivated_flag)
    {
        this->collisions_checkbox.setFillColor(sf::Color::Yellow);
        this->collisions_checkbox.setOutlineColor(sf::Color(125,125,125, 115));
    }
    else
    {
        this->collisions_checkbox.setFillColor(sf::Color::Black);
        this->collisions_checkbox.setOutlineColor(sf::Color(125,125,125, 115));
    }

}


void Snake::showGameOverMessage()
{
     
    this->fenetre->draw(gameOverText);
    this->fenetre->display();

    sf::Event event;
    while (fenetre->waitEvent(event))
    {
        if (event.type == sf::Event::Closed)
            fenetre->close();
        else if (event.type == sf::Event::KeyPressed)
            break; // break out of both loops when a key is pressed
    }
}
//---------------
// update score
//---------------

void Snake::calculateScore()
{
    for(int i = 0 ; i< douda.size(); i++)
        if(douda[i].getXpos() == makla->getXpos() && douda[i].getYpos()== makla->getYpos())
        {
            score += 10;
            delete makla;
            generateMakla();
        }  

}


void Snake::setUnsetWalls()
{
    this->wall_exist_flag = ! this->wall_exist_flag ;
}




/***********************************
 *      Render Functions
************************************/







void Snake::render(){
        
        /* 
            Always :
            1 - clear old frame
            2 - draw 
            3 - then display new frame
         */
    if (this->gameOver == false)
    {    
            // clear the window (with last config)
            //-------------------------------------
            this->fenetre->clear();  //(sf::Color(255 , 250 , 150 , 255)); 

            // render plan2D (cadre)
            //-----------------------
            this->fenetre->draw(this->plan2D->getCadre());

            // render douda
            //-------------
            this->renderDouda();

            // render checkbox
            //-----------------
            this->renderCheckboxes();

            // Render Text
            //-------------
            this->renderText(*this->fenetre); // render text on window target

            // render makla
            //-------------
            this->fenetre->draw(makla->getMakla());

            // display the new window
            //------------------------
            this->fenetre->display();

            sf::sleep(sf::milliseconds(50));
    }
}

void Snake::renderDouda()
{
    for(auto &e :  douda)
        {
             fenetre->draw(e.getRectPiassa());
        }
}

void Snake::renderText(sf::RenderTarget &target)
{
    target.draw(scoreText);
    target.draw(timeText);
    target.draw(settingText_wall);
    target.draw(settingText_doubleSenses);
    target.draw(settingText_sound);
    target.draw(settingText_noCollisions);
    //target.draw(gameOverText);
}



void Snake::renderCheckboxes()
{
    this->fenetre->draw(wall_checkbox);
    this->fenetre->draw(sound_checkbox);
    this->fenetre->draw(doubleSense_checkbox);
    this->fenetre->draw(collisions_checkbox);
}


/************************
 *   Other functions
*************************/


void Snake::playSound(std::string file, sf::SoundBuffer &_soundBuffer, sf::Sound &_sound ,bool loop){

    if(! _soundBuffer.loadFromFile(file))
    {
        std::cout << "audio file can't load.\"" << file << "\"." << std::endl;
    }
    _sound.setBuffer(_soundBuffer);
    _sound.setLoop(loop);
    _sound.setVolume(50);
    _sound.play();

    // sound.pause();  // Pause the sound
    // sound.resume(); // Resume the sound
    // sound.stop();   // Stop the sound

}

void Snake::getCurrentSettings(bool &wall, bool &sound, bool &doubleSense, bool &collisions)
{
    wall = wall_exist_flag;
    sound = sound_activated_flag;
    collisions = collision_between_douda_parts_isActivated_flag;
    doubleSense = double_sens_flag;
}
