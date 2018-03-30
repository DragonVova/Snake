#ifndef HELPER_H
#define HELPER_H


namespace nConstants
{
   const int FIELDWIDTH = 40;
   const int FIELDHEIGHT = 25;
   const int DEFSNAKECOORD_X = 15;
   const int DEFSNAKECOORD_Y = 15;
   const int DEFFOODCOORD_X = 5;
   const int DEFFODCOORD_Y = 5;
}

namespace nObjects
{
   const int SNAKEHEAD = 2;
   const int OBSTACLE = 1;
   const int CLEAR = 0;
   const int FOOD = 3;
}

struct sCoord
{
    int X;
    int Y;
    sCoord(int x, int y): X(x), Y(y)
    {

    }
};


namespace nButtons
{
    const int LEFT             = 75;
    const int RIGHT            = 77;
    const int DOWN             = 80;
    const int UP               = 72;
}


enum eDirection {Stop = 0, Left, Right, Up, Down};

#endif // HELPER_H
