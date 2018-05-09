#include "Game.h"
    Game* Current;
    Game::Game(){

        // some compatability stuff
        #if defined WIN32
            Space = new Background("..\\Textures\\TrentchRun.png",-1, 1, 2, 2);
            ani1 = new TexRect("..\\Textures\\start2.png",-1,1,2,2);
            ani2 = new TexRect("..\\Textures\\Start1.png",-1,1,2,2);
            Fighter = new fighter("..\\Textures\\Fighter1.png", 0, 0.67, 0.2, 0.2);
            
        #else
            Space = new Background("Textures/TrentchRun.png",-1.0, 1.0, 2, 2);
            ani1 = new TexRect("Textures/start2.png",-1,1,2,2);
            ani2 = new TexRect("Textures/Start1.png",-1,1,2,2);
            Fighter = new fighter("Textures/Fighter1.png", -.7, 0.67, 0.2, 0.3);
            Score = new score("Textures/ScoreLabel.png", -1, 1, 0.2, 0.05);
        #endif
        
        player = new Info();
        Current = this;
        game_over = false;
	    starpower = false;
	    trigunpower = false;
poisonpower = false;
        started = false;
        paused = false;
        animation = false;
        turn = false;
        Space->triggered = true;
    }

    // copy constructor 
    // for loading checkpoints
    Game::Game(const Game& prev){}

   void Game::upgradeShip(){
		if (player->returnScore() >= 100) {
			Fighter->upgradeFighter(1);
		}
	}
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
        else if(!game_over)
        {
			if (paused) {
				Space->Render();
				Score->displayScore();
				Score->updateScore(getScore());
			}
			else if (!paused) {
				// draw what is on screen
				Space->Render();
				Fighter->drawFihter();
				Score->displayScore();
				Score->updateScore(getScore());
				// End->draw();
			
				// draw enemy fighters 
				DrawBadies();
				DrawPowerup();
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
		}

        clock++;
    }
    void Game::DrawBadies()
    {
        // we need to generate random starting pose for the tie fighter 
        if(clock % 161 == 0 && Ties.size() != 10)
        {
            #if defined WIN32
                if(clock % 2 == 0)
                    Ties.push_back(new fighter("..\\Textures\\Tie1.png", .79, -.8*Fighter->getY(), 0.2, 0.3));
                else 
                    Ties.push_back(new fighter("..\\Textures\\OGTieFighter.png", .79,Fighter->getY(), 0.2, 0.3));
            #else 
                if(clock % 2 == 0)
                    Ties.push_back(new fighter("Textures/Tie1.png", .79, -.8*Fighter->getY(), 0.2, 0.3));
                else 
                    Ties.push_back(new fighter("Textures/OGTieFighter.png", .79,Fighter->getY(), 0.2, 0.3));
            #endif
        }
        else if( clock % 231 == 0 && Ties.size() != 10)
        {
            #if defined WIN32
                if(clock % 2 == 0)
                    Ties.push_back(new fighter("..\\Textures\\Tie1.png", .79, Fighter->getY(), 0.2, 0.3));
                else 
                    Ties.push_back(new fighter("..\\Textures\\OGTieFighter.png", .79, -.8 * Fighter->getY(), 0.2, 0.3));
            #else 
                if(clock % 3 == 0)
                    Ties.push_back(new fighter("Textures/Tie1.png", .79,  Fighter->getY(), 0.2, 0.3));
                else 
                    Ties.push_back(new fighter("Textures/OGTieFighter.png", .79, -.8 * Fighter->getY(), 0.2, 0.3));
            #endif 
        }
        else if(clock % 331 == 0 && bill.size() != 3)
        {
            #if defined WIN32
                bill.push_back(new fighter("..\\Textures\\Bill.png", .79,-.8*Fighter->getY(), 0.2, 0.2));
            #else 
                bill.push_back(new fighter("Textures/Bill.png", .79,Fighter->getY(), 0.2, 0.2));
           #endif
        }
	
	
        updateTies();
        updateBill();
        //  move them now on the screen 
    }
    void Game::DrawPowerup()//new
    {
	if(clock % 10000 == 0 && star.size() != 5)
	{
	    #if defined WIN32
                star.push_back(new fighter("..\\Textures\\star1.png", .79,Fighter->getY(), 0.1, 0.2));
            #else 
                star.push_back(new fighter("Textures/star1.png", .79*.2,Fighter->getY(), 0.1, 0.2));
           #endif
	}
	else if(clock % 3000 == 0 && trigun.size() != 5)
	{
	    #if defined WIN32
                trigun.push_back(new fighter("..\\Textures\\trigun1.png", .79,Fighter->getY(), 0.1, 0.2));
            #else 
                trigun.push_back(new fighter("Textures/trigun1.png", .79*.3,Fighter->getY(), 0.1, 0.2));
           #endif
	}
	else if(clock % 2061 == 0 && poison.size() != 5)
	{
	    #if defined WIN32
                poison.push_back(new fighter("..\\Textures\\poison.png", .79,Fighter->getY(), 0.1, 0.2));
            #else 
                poison.push_back(new fighter("Textures/poison.png", .79*.4,Fighter->getY(), 0.1, 0.2));
           #endif
	}


	updateStar();
	updateTrigun();
	updatePoison();
    }
    void Game::updateStar()//new
    {
        for(int i = 0; i < star.size(); i++)
        {
            star[i]->moveenemy(0.8);
        }
        if(star.size() > 0)
        {
            for(int i =0; i < star.size(); i++)
            {
                if(star[i]->getX() <= -.9)
                {
                    star.erase(star.begin()+i);
                }
                else
                {
                    FighterStar(star[i], i);
                }
            }
        }
    }
    void Game::updateTrigun()//new
    {
        for(int i = 0; i < trigun.size(); i++)
        {
            trigun[i]->moveenemy(0.8);
        }
        if(trigun.size() > 0)
        {
            for(int i =0; i < trigun.size(); i++)
            {
                if(trigun[i]->getX() <= -.9)
                {
                    trigun.erase(trigun.begin()+i);
                }
                else
                {
                    FighterTrigun(trigun[i], i);
                }
            }
        }
    }
void Game::updatePoison()//new
    {
        for(int i = 0; i < poison.size(); i++)
        {
            poison[i]->moveenemy(0.8);
        }
        if(poison.size() > 0)
        {
            for(int i =0; i < poison.size(); i++)
            {
                if(poison[i]->getX() <= -.9)
                {
                    poison.erase(poison.begin()+i);
                }
                else
                {
                    FighterPoison(poison[i], i);
                }
            }
        }
    }
    void Game::updateBill()
    {
        for(int i = 0; i < bill.size(); i++)
        {
            bill[i]->moveenemy(0.8);
        }
        if(bill.size() > 0)
        {
            for(int i =0; i < bill.size(); i++)
            {
                if(bill[i]->getX() <= -.9)
                {
                    bill.erase(bill.begin()+i);
                }
                else if(!starpower)
                {
                    FighterDamage(bill[i]);
                }
            }
        }
    }
    
    void Game::FighterDamage(fighter* tmp)
    {
        if(Fighter->myContains(tmp->getX(), tmp->getY()))
        {
          game_over = true;  
        }
    }
    void Game::FighterStar(fighter* tmp, int index)//new
    {
	if(Fighter->myContains(tmp->getX(), tmp->getY()))
	{
          star.erase(star.begin()+ index);
	  starpower = true;
	}
    }
    void Game::FighterTrigun(fighter* tmp, int index)//new
    {
	if(Fighter->myContains(tmp->getX(), tmp->getY()))
	{
          trigun.erase(trigun.begin()+ index);
	  trigunpower = true;
	  Fighter->trigun = true;
	}
    }
 void Game::FighterPoison(fighter* tmp, int index)//new
    {
	if(Fighter->myContains(tmp->getX(), tmp->getY()))
	{
          poison.erase(poison.begin()+ index);
	  starpower = false;
	  Fighter->trigun = false;
	}
    }
    void Game::updateTies()
    {
        // we need to also check if we need to delete them from the map 
        // as weell as detect any hits to delete them 
        for(int i = 0; i < Ties.size(); i++)
        {
            if(clock % 15 == 0)
            {
                Ties[i]->moveenemy();
            }
            else if (clock % 21 == 0 )
            {
                Ties[i]->moveenemy(0.5);
            }
            else
            {
                FighterDamage(Ties[i]);
                Ties[i]->moveenemy(0.005);
            }
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
                player->IncScore(5);
		        upgradeShip();
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
        
            ani1->draw();
    }
    void Game::Game_Timer(int val)
    {
        clock++;
        GameStartScreen();
        
    }
    void Game::Game_Input(int val)
    {
        if(!game_over)
		{
	    	if (val == 13)
			{
				if (!paused)
					paused = true;
				else
					paused = false;
				GameDraw();
			}
			if (!paused) {
		        Fighter->updateFighter(val);
		        moveBackground(val);
		        GameDraw();
			}
        }
    }
