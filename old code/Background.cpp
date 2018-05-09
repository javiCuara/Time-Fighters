#include "Background.h"

Background::Background(const char* scene, float x = 0, float y = 0, float w = 0.5, float h = 0.5) : TexRect(scene, x, y, w, h)
{
    this->incX = w; this->incY = h;
}
// check to see if player moves L or R
void Background::updateMove(int LR)
{
    if (LR == 1)
    {
        incX += -0.01;
        incY += -0.01;
        // newH(incY);
        newW(incX);
    }
    if(LR == 2) 
    {
        incX += 0.01;
        incY += 0.01;
        // newH(incY);
        newW(incX);
    }
}
void Background::Render()
{
    draw();
}