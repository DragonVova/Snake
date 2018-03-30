#ifndef MAP_H
#define MAP_H

#include "helper.h"
class Map
{
public:
    Map();
    void drawMap();
    void isMove();
    void setcur(int x, int y);
    bool getGameOver();
private:
    int MapArray[nConstants::FIELDHEIGHT][nConstants::FIELDHEIGHT];
    int mScore;
    bool GameOver;
};

#endif // MAP_H
