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
    if(nObjects::OBSTACLE != MapArray[coord.Y][coord.X])
    {
        isMove = true;
        if(MapArray[coord.Y][coord.X] == nObjects::FOOD)
        {
            sLogic();
        }
        MapArray[coord.Y][coord.X] = nObjects::SNAKEHEAD;
        sLogic();
    }
    return isMove;
}

void Map::userInput()
{
    sCoord mCoord = mSnake.getGoord();

    if (_kbhit())
    {
        switch (_getch())
        {
        case nButtons::DOWN : mSnake.setMove(Down); break;
        case nButtons::LEFT : mSnake.setMove(Left); break;
        case nButtons::RIGHT : mSnake.setMove(Right); break;
        case nButtons::UP : mSnake.setMove(Up); break;
        default: break;
        }
    }

    if (Stop != mSnake.getDirection())
    {
        switch(mSnake.getDirection())
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
            mSnake.setMove(eDirection::Up);
            if(true == isMove(mCoord))
            {
                mSnake.move(mCoord);
                ++mCoord.Y;
                clearCoord(mCoord);
            }
            break;
        case eDirection::Right :
            mCoord.X +=1;
            mSnake.setMove(eDirection::Right);
            if(true == isMove(mCoord))
            {
                mSnake.move(mCoord);
                --mCoord.X;
                clearCoord(mCoord);
            }
            break;
        case eDirection::Left :
            mCoord.X -=1;
            mSnake.setMove(eDirection::Left);
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

void Map::sLogic()
{
     if(mSnake.getGoord() == mFood.getCoord())
     {
         mFood.setCoord();
         MapArray[mFood.getCoord().Y][mFood.getCoord().X] = nObjects::FOOD;

     }

}


bool Map::getGameOver()
{
    return GameOver;
}
