#include "Game.h"

    Game::Game(){
        player = new Info();
        game_over = false;
        started = false;
        paused = false;
        turn = false;
        Space = new TexRect("Textures/TrentchRun.png", -1, 1, 2, 2);
        ani1 = new TexRect("Textures/start2.png",-1,1,2,2);
        ani2 = new TexRect("Textures/Start1.png",-1,1,2,2);
        Fighter1 = new TexRect("Textures/Fighter1.png", 0, 0.67, 0.2, 0.2);

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
            GameStartScreen();
        }
        else 
        {
            // draw what is on screen
            Space->draw();
        }
    }
    void Game::GameStartScreen()
    {
        if (turn)
        {
            for(int i=0; i <80000000; i++);
            ani1->draw();
            turn = false;
        }
        else
        {
            for(int i=0; i <80000000; i++);
            ani2->draw();
            turn = true;
        }
    }