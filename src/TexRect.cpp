#include "TexRect.h"

TexRect::TexRect(float x, float y, float w, float h)
{
    this->x = x; this->y = y;
    this->w = w; this->h = h;
    xx = x; yy = y; ww = w; hh = h;
}
// type int for backgrounds 
// TexRect::TexRect (const char* filename, int rows, int cols, int x=0, int y=0, int w=0.5, int h=0.5){
//     glClearColor (0.0, 0.0, 0.0, 0.0);
//     glShadeModel(GL_FLAT);
//     glEnable(GL_DEPTH_TEST);
    
//     RgbImage theTexMap( filename );
    
//     glGenTextures( 1, &texture_id );
//     glBindTexture( GL_TEXTURE_2D, texture_id );
    
//     gluBuild2DMipmaps(GL_TEXTURE_2D, 3, theTexMap.GetNumCols(), theTexMap.GetNumRows(),
//                       GL_RGB, GL_UNSIGNED_BYTE, theTexMap.ImageData() );
//     this->texture_id = texture_id;
    
//     this->rows = (float)rows;
//     this->cols = (float)cols;
    
//     this->x = (float)x;
//     this->y = (float)y;
//     this->w = (float)w;
//     this->h = (float)h;
    
//     curr_row = 1;
//     curr_col = 1;
    
//     complete = false;
// }
TexRect::TexRect (const char* filename,const char* file2, int rows, int cols, float x=0, float y=0, float w=0.5, float h=0.5, bool boo= false){
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);
    
    RgbImage theTexMap( filename );
    
    glGenTextures( 1, &texture_id );
    glBindTexture( GL_TEXTURE_2D, texture_id );
    
    gluBuild2DMipmaps(GL_TEXTURE_2D, 3, theTexMap.GetNumCols(), theTexMap.GetNumRows(),
                      GL_RGB, GL_UNSIGNED_BYTE, theTexMap.ImageData() );
    this->texture_id = texture_id;
    
    //second image
    RgbImage theTexMap2(file2);
    
    glGenTextures( 1, &texture_id2 );
    glBindTexture( GL_TEXTURE_2D, texture_id2 );
    
    gluBuild2DMipmaps(GL_TEXTURE_2D, 3, theTexMap2.GetNumCols(), theTexMap2.GetNumRows(),
                      GL_RGB, GL_UNSIGNED_BYTE, theTexMap2.ImageData() );
    this->texture_id2 = texture_id2;

    this->rows = rows;
    this->cols = cols;
    
    triggred = boo; // bool to change if we need to change state

    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    
    curr_row = 1;
    curr_col = 1;
    
    complete = false;
}

TexRect::TexRect (const char* filename, int rows, int cols, float x=0, float y=0, float w=0.5, float h=0.5){
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);
    
    
    RgbImage theTex( filename );
    
    glGenTextures( 1, &texture_id );
    glBindTexture( GL_TEXTURE_2D, texture_id );
    
    gluBuild2DMipmaps(GL_TEXTURE_2D, 3, theTex.GetNumCols(), theTex.GetNumRows(),
                      GL_RGB, GL_UNSIGNED_BYTE, theTex.ImageData() );
    this->texture_id = texture_id;
    
    
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    
    rising = true;

}


void TexRect::moveUp(float rate){
    y += rate;
}
void TexRect::moveDown(float rate){
    y -= rate;
}
void TexRect::moveLeft(float rate){
    x -= rate;
}
void TexRect::moveRight(float rate){
    x += rate;
}


void TexRect::jump(){
    if(rising){
        y+=0.01;
    }
    else {
        y-=0.01;
    }
    
    if (y > 0.99){
        rising = false;
    }
    if ((y-h) < -0.99){
        rising = true;
    }
}



void TexRect::draw(){

    glBindTexture( GL_TEXTURE_2D, texture_id );
    glEnable(GL_TEXTURE_2D);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    
    
    glBegin(GL_QUADS);
    
    glTexCoord2f(0, 0);
    glVertex2f(x, y - h);
    
    glTexCoord2f(0, 1);
    glVertex2f(x, y);
    
    glTexCoord2f(1, 1);
    glVertex2f(x+w, y);
    
    glTexCoord2f(1, 0);
    glVertex2f(x+w, y - h);
    
    glEnd();
    
    glDisable(GL_TEXTURE_2D);
    
}


bool TexRect::contains(float mx, float my){
    return mx >= x && mx <= x+w && my <= y && my >= y - h;
}

void TexRect::incY(){
    y+=0.01;
}

void TexRect::advance(){
    if (curr_col < cols){
        curr_col++;
    }
    else {
        if (curr_row < rows){
            curr_row++;
            curr_col = 1;
        }
        else{
            curr_row = 1;
            curr_col = 1;
        }
    }
    
    if (curr_row == rows && curr_col == cols){
        complete = true;
    }
}

void TexRect::reset(){
    complete = false;
}
void TexRect::updateCR(int a, int b)
{
    rows = a; cols = b;
}
void TexRect::updateTrigger(bool a)
{
    triggred = a;
}


