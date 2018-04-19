#include "actor.h"

Actor::Actor():Grid(tile_size)
{


}

bool Actor::moveLeft()
{
    if (call2>0)
    {
        loc->x -= tile_size;
        call2--;
    }
    return true;

}
bool Actor::moveRight()
{
    if (call2<call_horiz)
    {
        loc->x += tile_size;
        call2++;
    }
    return true;
}

bool Actor::moveUp()
{
    if (call<4)
    {
        loc->x += yHoriz;
        loc->y -= yVert;
        call++;
    }
    return true;
}
bool Actor::moveDown()
{
    if (call>0)
    {
        loc->x -= yHoriz;
        loc->y += yVert;
        call--;
    }
    return true;
}

Actor::~Actor()
{


}
