#include <iostream>
#include "map.h"
#include "snake.h"
#include "helper.h"

Map::Map():
    GameOver(false)
  , mScore(0)
{

    for(int i = 0; i < nConstants::FIELDHEIGHT; ++i)
    {
        for(int j = 0; j < nConstants::FIELDWIDTH; ++j)
        {
            if(0 == j ||
               j == nConstants::FIELDWIDTH - 1 ||
               0 == i ||
               i == nConstants::FIELDHEIGHT - 1 )
            {
                MapArray[i][j] = nObjects::OBSTACLE;
            }
            else if(i == nConstants::DEFSNAKECOORD_Y && j == nConstants::DEFSNAKECOORD_X)
            {
                MapArray[i][j] = nObjects::SNAKEHEAD;
            }
            else MapArray[i][j] = nObjects::CLEAR;
        }
    }
}
void Map::drawMap()
{
    for(int i = 0 ; i < nConstants::FIELDHEIGHT; ++i)
    {
        for (int j = 0; j < nConstants::FIELDWIDTH; ++j)
        {
            switch(MapArray[i][j])
            {
            case nObjects::OBSTACLE: std::cout << "#"; break;
            case nObjects::CLEAR: std::cout << " ";break;
            case nObjects::FOOD: std::cout << "*"; break;
            case nObjects::SNAKEHEAD: std::cout << "0"; break;
            default: break;
            }
        }
        std::cout<<std::endl;
    }
}


bool Map::getGameOver()
{
    return GameOver;
}
