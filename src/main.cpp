#include <iostream>
#include "helper.h"
#include "map.h"

using namespace std;

int main()
{
    Map obj_Map;

    while(obj_Map.getGameOver() == false)
    {
        system("cls");
        obj_Map.drawMap();
    }
    return 0;
}
