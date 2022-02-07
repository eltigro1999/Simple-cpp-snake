#include "Coords.h"

bool Coords::operator==(Coords coord)
{
    return this->x==coord.x && this->y==coord.y;
}
