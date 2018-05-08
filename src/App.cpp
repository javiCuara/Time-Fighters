#include "App.h"
// #include "Game.h"

static App* singleton;

void timerStart(int val)
{
    singleton->value +=val;
    // singleton->
    if(!singleton->Mygame->game_over)
    {
        singleton->Mygame->GameDraw();
        singleton->redraw();
        glutTimerFunc(16,timerStart, val);
    }
    if(singleton->Mygame->game_over && ! singleton->start)
    {
        singleton->gameOver->animate();
        singleton->start = true;
    }
    if(singleton->Mygame->game_over)
    {
        singleton->gameOver->advance();
    }
    if (singleton->Mygame->game_over){
        singleton->redraw();
        glutTimerFunc(300, timerStart, val);
    }
    
}
App::App(const char* label, int x, int y, int w, int h): GlutApp(label, x, y, w, h){
    // Initialize state variables
    
    singleton = this;
    mx = 0.0;
    my = 0.0;
    
    Mygame = new Game();
    #if defined WIN32
        gameOver= new AnimatedRect("..\\Textures\\AlderonExplosion.png", 4, 4,-1, 1, 2, 2);
    #else
        gameOver= new AnimatedRect("Textures/AlderonExplosion.png", 4, 4,-1, 1, 2, 2);
    #endif
    
    timerStart(1);

}

void App::specialKeyPress(int key){

  Mygame->Game_Input(key);
}

/*100=Up Arrow , 101=Left Arrow, 102=Down Arrow, 103=Right Arrow*/
void App::specialKeyUp(int key){
    
   Mygame->Game_Input(key);
}

void App::draw() {

    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Set background color to black
    glClearColor(0.0, 0.0, 1.0, 1.0);
    
    // Set up the transformations stack
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    // background->draw();}   
    Mygame->GameDraw();
    gameOver->draw();
    glFlush();
    glutSwapBuffers();
}

void App::mouseDown(float x, float y){
    // Update app state
    mx = x;
    my = y;

}

void App::mouseDrag(float x, float y){
    // Update app state
    mx = x;
    my = y;

}

void App::idle(){

}

void App::keyPress(unsigned char key) {
    
    if(Mygame->started)
    {
        Mygame->Game_Input(key);
    }
    if (key == 27){
        
        delete this; 
        exit(0);
    }
    if(key == ' ')
    {
        Mygame->started = true;
        draw();
        // start = true;
    }
    if (key == 28){
       
    }
}

