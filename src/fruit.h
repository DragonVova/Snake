#ifndef FRUIT_H
#define FRUIT_H

#include "helper.h"

class Fruit
{
public:
    Fruit();
    sCoord getCoord() const;
    void setCoord();
private:
    sCoord mCoord;
};

#endif // FRUIT_H
