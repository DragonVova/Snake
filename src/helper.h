#ifndef HELPER_H
#define HELPER_H


namespace nConstants
{
   const int FIELDWIDTH = 40;
   const int FIELDHEIGHT = 25;
   const int DEFSNAKECOORD_X = 15;
   const int DEFSNAKECOORD_Y = 15;
   const int DEFFOODCOORD_X = 5;
   const int DEFOODCOORD_Y = 5;
}

struct sCoord
{
    int X;
    int Y;
    sCoord(int x, int y): X(x), Y(y)
    {

    }
};

enum eDirection {Stop = 0, Left, Right, Up, Down};

#endif // HELPER_H