#include "Game.h"
    Game* Current;
    Game::Game(){
        player = new Info();
        Current = this;
        game_over = false;
        started = false;
        paused = false;
        turn = false;

        Space = new TexRect("Textures/TrentchRun.png", -1, 1, 2, 2);
        ani1 = new TexRect("Textures/start2.png",-1,1,2,2);
        ani2 = new TexRect("Textures/Start1.png",-1,1,2,2);
        Fighter = new fighter("Textures/Fighter1.png", 0, 0.67, 0.2, 0.2);
    }

    // copy constructor 
    // for loading checkpoints
    Game::Game(const Game& prev){}

    void Game::upgradeShip(){}
    void Game::Paused(){}
    void Game::Checkpoint(){}
    
    int Game::getScore()const{return player->returnScore();}
    int Game::getLives()const{return player->getLives();}

    void Game::scoreTally(){}

    void Game::GameDraw()
    {
        if(!started)
        {
            Game_Timer(clock);
        }
        else 
        {
            // draw what is on screen
            Space->draw();
            Fighter->drawFihter();
            if(Fighter->cannon.size() > 0)
            {
                for(int i = 0; i < Fighter->cannon.size(); i++)
                {
                    Fighter->cannon[i]->draw();
                    Fighter->cannon[i]->moveRight(Fighter->moveSpeed);
                }
            }
        }
    }
    void animateStart(int val)
    {
        if(val == 1)
        {
            Current->ani1->draw();
        }
        if(val == 2)
        {
        }
    }
    void Game::GameStartScreen()
    {
        if (clock %11 == 0)
        {
            ani1->draw();
        }
        else
        {
            ani2->draw();
        }
    }
    void Game::Game_Timer(int val)
    {
        clock++;
        if(clock%17 == 0 && !started)
        {   
            GameStartScreen();
        }
        else{
            GameStartScreen();
        }
    }
    void Game::Game_Input(int val)
    {
        if(!game_over)
        {
            Fighter->updateFighter(val);
            GameDraw();
            
        }
    }