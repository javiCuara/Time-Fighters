#include "Game.h"
    Game* Current;
    Game::Game(){

        // some compatability stuff
        #if defined WIN32
            Space = new Background("..\\Textures\\rentchRun.png",-1, 1, 2, 2);
            ani1 = new TexRect("..\\Textures\\start2.png",-1,1,2,2);
            ani2 = new TexRect("..\\Textures\\Start1.png",-1,1,2,2);
            Fighter = new fighter("..\\Textures\\Fighter1.png", 0, 0.67, 0.2, 0.2);
        #else
            Space = new Background("Textures/TrentchRun.png",-1.0, 1.0, 2, 2);
            ani1 = new TexRect("Textures/start2.png",-1,1,2,2);
            ani2 = new TexRect("Textures/Start1.png",-1,1,2,2);
            Fighter = new fighter("Textures/Fighter1.png", -.7, 0.67, 0.2, 0.3);
        #endif
        
        player = new Info();
        Current = this;
        game_over = false;;
        started = false;
        paused = false;
        turn = false;
        Space->triggered = true;
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
            Space->Render();
            Fighter->drawFihter();
            
            // draw enemy fighters 
            DrawTies();
            if(Fighter->cannon.size() > 0)
            {
                for(int i = 0; i < Fighter->cannon.size(); i++)
                {
                    Fighter->deleteCannon();
                    Fighter->cannon[i]->moveRight(0.02);
                }
                for(int i = 0; i < Fighter->cannon.size(); i++)
                {
                    Fighter->cannon[i]->draw();
                }
            }
        }
        clock++;
    }
    void Game::DrawTies()
    {
        // we need to generate random starting pose for the tie fighter 
        if(clock % 91 == 0 && Ties.size() != 10)
        {
            #if defined WIN32
                Ties.push_back(new fighter("..\\Textures\\Tie1.png", .79, Fighter->getY(), 0.2, 0.3));
            #else 
                Ties.push_back(new fighter("Textures/Tie1.png", .79, Fighter->getY(), 0.2, 0.3));
            #endif
        }
        else if( clock % 101 == 0 && Ties.size() != 10)
        {
            #if defined WIN32
                Ties.push_back(new fighter("..\\Textures\\Tie1.png", .79, Fighter->getY(), 0.2, 0.3));
            #else 
                Ties.push_back(new fighter("Textures/Tie1.png", .79, -1 * Fighter->getY(), 0.2, 0.3));
            #endif 
        }
        updateTies();
        //  move them now on the screen 
    }
    void Game::updateTies()
    {
        // we need to also check if we need to delete them from the map 
        // as weell as detect any hits to delete them 
        for(int i = 0; i < Ties.size(); i++)
        {
            Ties[i]->moveenemy();
        }
        if(Ties.size() > 0)
        {
            for(int i =0; i < Ties.size(); i++)
            {
                if(Ties[i]->getX() <= -.9)
                {
                    Ties.erase(Ties.begin()+i);
                }
                if(Fighter->cannon.size() >0)
                {
                    checkCrits(i);
                }
            }
        }

    }
    void Game::checkCrits(int index)
    {
        for(int i = 0; i < Fighter->cannon.size(); i ++)
        {
            if(Ties[index]->myContains(Fighter->cannon[i]->get_myX(),Fighter->cannon[i]->get_myY()))
            {
                // we need to delete the tie and the bolt
                Ties.erase(Ties.begin()+index);
                Fighter->cannon.erase(Fighter->cannon.begin() + i);
                break;
            }
        }
    }
    void Game::moveBackground(int val)
    {
        
        
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
            moveBackground(val);
            GameDraw();
            
        }
    }