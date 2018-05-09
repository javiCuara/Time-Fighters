#ifndef Background_h
#define Background_h
#include "TexRect.h"

class Background : public TexRect{
private:
    float incX, incY;
public:
    Background(const char*, float, float, float, float);
    void  Render();
    void updateMove(int);
};

#endif
