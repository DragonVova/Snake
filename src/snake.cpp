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

