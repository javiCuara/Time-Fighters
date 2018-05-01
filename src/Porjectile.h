#ifndef Projectile_h
#define Projectile_h
#include "TexRect.h"

#define MaxBolts 20 // max of 10 on screen projectiles

class bolts:public TexRect{
    // float x, y, w, h;
    bool hit, inRange;
    int damage;
public:
    bolts(const char* image, float xx, float yy, float ww, float hh):TexRect(image,xx,yy,ww,hh)
    {
        // x = xx, y = yy, w = ww, h = hh;
        damage = 1; // deault value 
    }

    // takes parent image pose 
    // to center the projectile 
    void shoot()
    {
        moveRight(0.5);
        draw();
    }
    void DrawBolt()
    {
        
        
    }


};

#endif