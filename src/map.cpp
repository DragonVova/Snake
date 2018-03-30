#include <iostream>
#include "map.h"
#include "snake.h"
#include "helper.h"
#include <conio.h>

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
            else if(i == nConstants::DEFFODCOORD_Y && j == nConstants::DEFFOODCOORD_X)
            {
                MapArray[i][j] = nObjects::FOOD;
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

void Map::clearCoord(const sCoord& coord)
{
    MapArray[coord.Y][coord.X] = nObjects::CLEAR;
}

bool Map::isMove(const sCoord &coord)
{
    bool isMove = false;
    if(MapArray[coord.Y][coord.X] == nObjects::CLEAR)
    {
        isMove = true;
        MapArray[coord.Y][coord.X] = nObjects::SNAKEHEAD;
    }
    return isMove;
}

void Map::userInput()
{
    eDirection mDirection = eDirection::Stop;
    sCoord mCoord = mSnake.getGoord();

    if (_kbhit())
    {
        switch (_getch())
        {
        case nButtons::DOWN : mDirection = Down; break;
        case nButtons::LEFT : mDirection = Left; break;
        case nButtons::RIGHT : mDirection = Right; break;
        case nButtons::UP : mDirection = Up; break;
        default: break;
        }
    }

    if (Stop != mDirection)
    {
        switch(mDirection)
        {
        case eDirection::Down :
            mCoord.Y +=1;
            mSnake.setMove(eDirection::Down);
            if(true == isMove(mCoord))
            {
                mSnake.move(mCoord);
                --mCoord.Y;
                clearCoord(mCoord);
            }
            break;
        case eDirection::Up :
            mCoord.Y -=1;
            mSnake.setMove(eDirection::Down);
            if(true == isMove(mCoord))
            {
                mSnake.move(mCoord);
                ++mCoord.Y;
                clearCoord(mCoord);
            }
            break;
        case eDirection::Right :
            mCoord.X +=1;
            mSnake.setMove(eDirection::Down);
            if(true == isMove(mCoord))
            {
                mSnake.move(mCoord);
                --mCoord.X;
                clearCoord(mCoord);
            }
            break;
        case eDirection::Left :
            mCoord.X -=1;
            mSnake.setMove(eDirection::Down);
            if(true == isMove(mCoord))
            {
                mSnake.move(mCoord);
                ++mCoord.X;
                clearCoord(mCoord);
            }
            break;
        }
    }
}


bool Map::getGameOver()
{
    return GameOver;
}
