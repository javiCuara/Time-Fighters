#ifndef Game_h
#define Game_h

#include "GlutApp.h"
#include "TexRect.h"
#include "AnimatedRect.h"
#include "PlayerInfo.h"
// player infromation
class Game{
public:

    Info* player;

    // Game* saveGame;

    bool game_over;
    bool paused;
    bool started;
    bool turn;

    TexRect* ani1;
    TexRect* ani2;
    TexRect* Space;     // background  
    TexRect* Fighter1;  // standard fighter
    TexRect* Fighter2;  // upgrade 1
    TexRect* Fighter3;  // upgrade 2

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

    ~Game(){}
};

#endif