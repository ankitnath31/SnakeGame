#include "food.h"

food::food()
{
    genfood();
}

void food::genfood()
{
 pos.X = rand() % (width - 2) + 1;
pos.Y = rand() % (height - 2) + 1;
}

COORD food::get_pos()
{
    return pos;
}
