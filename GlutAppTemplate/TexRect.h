#ifndef TexRect_h
#define TexRect_h

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

#include "RgbImage.h"

class TexRect {
     float x, xx;
    float y, yy;
    float w, ww;
    float h, hh;
    GLuint texture_id;
    GLuint texture_id2; // added for second animation or image 
    bool triggred; // change animation 

    int rows;
    int cols;
    
    int curr_row;
    int curr_col;
    
    bool complete;

public:
    // TexRect (const char*, int, int, int, int, int, int);
    TexRect(float x, float y, float w, float h);
    TexRect (const char*, int, int, float, float, float, float);
    TexRect(const char*,const char*, int, int, float, float, float, float, bool);
    
    // TexRect(const char*, int , int , int, int, int, int);

    void draw();
    
    bool contains(float, float);
    
    void moveUp(float rate=0.01);
    void moveDown(float rate=0.01);
    void moveLeft(float rate=0.01);
    void moveRight(float rate=0.01);
    
    void jump();
    bool done();
    
    void advance();
    
    void incY();
    
    void reset();
    
    void updateCR(int a, int b);
   
    void updateTrigger(bool a);
   
    bool rising;

};

#endif
