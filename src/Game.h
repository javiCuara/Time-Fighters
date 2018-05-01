#ifndef Game_h
#define Game_h

#include "GlutApp.h"
#include "TexRect.h"
#include "AnimatedRect.h"
#include "PlayerInfo.h"
// #include "Porjectile.h"
#include "fighter.h"
// #include <chrono>
// #include <thread>
// player infromation
class Game{
public:

    Info* player;

    // Game* saveGame;
    long int clock;
    bool game_over;
    bool paused;
    bool started;
    bool turn;
    bool shoot;

    TexRect* ani1;
    TexRect* ani2;

    TexRect* Space;     // background  
    fighter* Fighter;  // standard fighter
    // TexRect* Fighter2;  // upgrade 1
    // TexRect* Fighter3;  // upgrade 2

    // End screen
    AnimatedRect* End;       

    // Start screen 

    // standard default no need for custom 
    // setting to load into game
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
    ~Game(){}
};

#endif