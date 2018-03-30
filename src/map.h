#ifndef MAP_H
#define MAP_H

#include "snake.h"
#include "fruit.h"
#include "helper.h"
class Map
{
public:
    Map();
    void drawMap();
    void clearCoord(const sCoord &coord);
    bool isMove(const sCoord& coord);
    void userInput();
    void setcur(int x, int y);
    bool getGameOver();
private:
    Snake mSnake;
    Fruit mFood;
    int MapArray[nConstants::FIELDHEIGHT][nConstants::FIELDWIDTH];
    int mScore;
    bool GameOver;
};

#endif // MAP_H
