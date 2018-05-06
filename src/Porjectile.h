#ifndef Projectile_h
#define Projectile_h
#include "TexRect.h"
#include <iostream>

#define MaxBolts 20 // max of 10 on screen projectiles

class bolts:public TexRect{
    // float x, y, w, h;
    bool hit, inRange;
    int damage;
public:
    bolts(const char* image, float xx, float yy, float ww, float hh):TexRect(image,xx,yy,ww,hh)
    {
        damage = 1; // deault value 
        inRange = true;
    }

    void shoot()
    {
        if(inRange)
        {
            moveRight(0.5);
            draw();
        }
    }
    int getX()const
    {
        return (int)x;
    }
    void deleteBolt()
    {
        inRange = false;
    }
    void DrawBolt()
    {
        // std::cout <<"Hello\n";
        draw();
    }
    ~bolts()
    {
        delete this;
    }

};

#endif