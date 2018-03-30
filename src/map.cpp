#include <iostream>
#include "map.h"

Map::Map():
    GameOver(false)
  , mScore(0)
{

}

void Map::drawMap()
{
    system("cls");
    //Upper
    for(int i = 0; i < nConstants::FIELDWIDTH; ++i)
    {
        std::cout<<"#";
    }
    std::cout<<std::endl;

    for(int i = 0; i < nConstants::FIELDHEIGHT; ++i)
    {
        for(int j = 0; j < nConstants::FIELDWIDTH; ++j)
        {
            if(j==0 || j == nConstants::FIELDWIDTH-1)
            {
                std::cout<<"#";
            }
            else std::cout<<" ";
        }
        std::cout<<std::endl;
    }

    //Down
    for(int i = 0; i < nConstants::FIELDWIDTH; ++i)
    {
        std::cout<<"#";
    }
    std::cout<<std::endl;
}


bool Map::getGameOver()
{
    return GameOver;
}
