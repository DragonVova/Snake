#ifndef SNAKE_H
#define SNAKE_H

#include "helper.h"

class Snake
{
public:
    Snake();
    sCoord getGoord();
    void move(sCoord coord);
    void setMove(eDirection move);
private:
    eDirection mDirection;
    sCoord mSnakeCoord;
};

#endif // SNAKE_H
