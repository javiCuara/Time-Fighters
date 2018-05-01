#ifndef fighter_h
#define fighter_h
#include "TexRect.h"
#include "Porjectile.h"
#include <vector>

class fighter: TexRect{

    const char* Fighter1;
    const char* Fighter2;
    const char* Fighter3;
    int cur_fighter;
    bool hits;
    bool shot; 
    int max = 10;
     
public:
    float moveSpeed;
    std::vector<bolts*> cannon;
    fighter(const char* name,float x =0.0, float y =0.0, float w =.5, float h =0.5):TexRect(name,x,y,w,h)
    {
        Fighter1 = name;
        cur_fighter = 1;
        hits = false;
        moveSpeed = 0.05;
        shot = false;
    }
    void drawFihter()
    {
        if(!hits)
            draw();
    }
    void drawBolt()
    {
        // pro->draw();
    }
    /*100=Up Arrow , 101=Left Arrow, 102=Down Arrow, 103=Right Arrow*/
    void updateFighter(int val)
    {
        switch (val){
            case(100):{
                moveLeft(moveSpeed);
                // return true;
                break;
            }
            case(101):{
                moveUp(moveSpeed);
                // return true;
                break;
            }
            case(102):{
                moveRight(moveSpeed);
                // return true;
                break;
            }
            case(103):{
                moveDown(moveSpeed);
                // return true;
                break;
            }
            // shooting
            case(32):{
                if(cannon.size() != max)
                {
                cannon.push_back(new bolts("Textures/RedBlaster2.png",x,y,0.2,0.2));
                shot = true;
                }
                else
                {
                    // we need to delete any that reached boundry 

                }
                break;
            }
            default:{
                break;
            }
        }
        // return false;
    }
    // if ship upgrade availabe then update the skin
    void newFighter()
    {
        switch (cur_fighter){
            case(1):{
                break;
            }
            case(2):{
                break;
            }
            case(3):{
                
                break;
            }
            default:{
                break;
            }
        }
    }
    void shoot();
    
    bool hit();

    ~fighter(){

    }
};

#endif