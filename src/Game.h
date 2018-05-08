#ifndef Game_h
#define Game_h

#include "GlutApp.h"
#include "TexRect.h"
#include "AnimatedRect.h"
#include "PlayerInfo.h"
#include "fighter.h"
#include "Background.h"
#include <vector>

class Game{
public:

    Info* player;

    // Game* saveGame;
    long int clock;
    int translate;
    
    bool game_over;
    bool starpower;
    bool trigunpower;
    bool poisonpower;
    bool animation;
    bool paused;
    bool started;
    bool turn;
    bool shoot;

    std::vector<fighter*> Ties;
    
    // Bullet Bills cannot be destroyed 
    // They do the destroying so avoid them at all costs
    std::vector<fighter*> bill;
   
    //powerups cant be destroyed
    std::vector<fighter*> star;
    std::vector<fighter*> trigun;
    std::vector<fighter*> poison;


    TexRect* ani1;
    TexRect* ani2;

    Background* Space;     // background  
    fighter* Fighter;  // standard fighter

    AnimatedRect* End;       

    Game();

    // copy constructor 
    // for loading checkpoints
    Game(const Game& prev);

    void upgradeShip();
    void Paused();
    void Checkpoint();
    
    int getScore()const;
    int getLives()const;

    void GameDraw();
    void GameStartScreen();
    void scoreTally();

    void Game_Timer(int);
    void Game_Input(int);
    void moveBackground(int);
    void DrawBadies();
    void DrawPowerup();
    void updateTies();
    void updateBill();
    void updateStar();
    void updateTrigun();
    void updatePoison();
    void checkCrits(int);
    void FighterDamage(fighter* tmp);
    void FighterStar(fighter* tmp, int);
    void FighterTrigun(fighter* tmp, int);
    void FighterPoison(fighter* tmp, int);
    ~Game(){}
};

#endif
