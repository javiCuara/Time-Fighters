#ifndef PlayerInfo_h
#define PlayerInfo_h

#define NoID -9999
#define MAXLIVES 3

enum Boosters{
    movement = 111999,
    health = 111888,
    Slugg = 77777 
};

struct Info{
public:
    int score, lives, t;
    bool power;
    int boostId;

    Info()
    {
        score = 0; lives = 0; t = 0;
        power = false;
        boostId NoID;
    }
    Info(const Info &p)
    {
        // copy what is necessary 
    }
    // by default the score will incement by 5
    void IncScore(int inc = 5)
    {  
        this->score += inc;
    }
    int returnScore()const
    {
        return score;
    }
    void InceLives(int inc = 1)
    {
        if(lives != MAXLIVES)
            lives += inc;
    }
    int getLives()const
    {
        return lives;
    } 
    int boostDetected(int pot)
    {
        switch (pot)
        {
            case movement:
                power = true;
                // do something
                break;
            default:
                break;
        }
    }

    ~Info(){};
};

#endif
