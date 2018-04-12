#include "snake.h"

Snake::Snake():
    mDirection(Stop)
  , mSnakeCoord(nConstants::DEFSNAKECOORD_Y , nConstants::DEFSNAKECOORD_X)

{

}

sCoord Snake::getGoord()
{
    return mSnakeCoord;
}

void Snake::setMove(eDirection move)
{
    mDirection = move;
}

eDirection Snake::getDirection() const
{
    return mDirection;
}

void Snake::move(sCoord coord)
{
    mSnakeCoord.X = coord.X;
    mSnakeCoord.Y = coord.Y;
}
