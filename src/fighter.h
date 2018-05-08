#ifndef fighter_h
#define fighter_h
#include "TexRect.h"
#include "Porjectile.h"
#include "Game.h"
#include <vector>

class fighter: TexRect{

    const char* Fighter1;
    const char* Fighter2;
    const char* Fighter3;
    int cur_fighter;
    bool hits;
    bool shot; 
    int max = 10;
   
    //some compatability stuff
public:
    int counter = 0;
    bool trigun = false;
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
    void moveenemy(float rate = 0.002)
    {
         moveLeft(0.002);
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
                if(getPose()<= -.9)
                {
                    return;
                }
                else 
                {
                    moveLeft(moveSpeed);
                }
                // return true;
                break;
            }
            case(101):{
                if(get_yPose()<=.7)
                {
                    moveUp(moveSpeed);
                }
                // return true;
                break;
            }
            case(102):{
                if(getPose() <= .7)
                    moveRight(moveSpeed);
                // return true;
                break;
            }
            case(103):{
                if(get_yPose() >= -.5)
                {
                    moveDown(moveSpeed);
                }
                // return true;
                break;
            }
            // shooting
            case(32):{
		
				if(cannon.size() != max)
				{
				    
				        
				  	if(trigun)
					{
						if(counter != 10)
						{
							 cannon.push_back(new bolts("Textures/RedBlaster2.png",x,y-0.05,0.2,0.2));
							 cannon.push_back(new bolts("Textures/RedBlaster2.png",x,y+0.4,0.2,0.2));
							 cannon.push_back(new bolts("Textures/RedBlaster2.png",x,y-0.4,0.2,0.2));
							 counter ++;
						}
						else
						{
							trigun = false;
							counter = 0;
						}
					}
					else
						 cannon.push_back(new bolts("Textures/RedBlaster2.png",x,y-0.05,0.2,0.2));
				    // deleteCannon(); 
				    shot = true;
				}
				else
				{
				    deleteCannon(); 

				}
				break;
			    }
			    default:{
				break;
			    }
	
		
        }
    }
    // if ship upgrade availabe then update the skin
    void deleteCannon()
    {
        // std::cout<<"deleting check ...\n";
        if(cannon.size() > 0)
        {
            // std::cout<<"deleting check 1 ...\n";
            for(int i =0; i < cannon.size(); i++)
            {   
                // std::cout<<"This is the pose" << cannon[i]->getPose() << " ...\n";
                if(cannon[i]->getPose() >= 0.79)
                {
                    // std::cout<<"deleting check 2 ...\n";
                    cannon.erase(cannon.begin() + i);
                    break;
                }
            }
        }
    }
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
    bool myContains(float x, float y)
    {
        return contains(x,y);
    }
    
    float getY()
    {
        return get_yPose();
    }
    float getX()
    {
        return getPose();
    }

    bool hit();

    ~fighter(){

    }
};

#endif
