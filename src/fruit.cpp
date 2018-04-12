#include "fruit.h"
#include <iostream>

Fruit::Fruit():
    mCoord(nConstants::DEFFODCOORD_Y, nConstants::DEFFOODCOORD_X)
{

}

sCoord Fruit::getCoord() const
{
    return mCoord;
}

void Fruit::setCoord()
{
    mCoord.X = std::rand() % nConstants::FIELDWIDTH;
    mCoord.Y = std::rand() % nConstants::FIELDHEIGHT;
}

