#include "snake.h"
snake::snake(COORD pos, int val)
{
    this->pos=pos;
    this->val=val;
    len=1;
    direction='n';
    body.push_front(pos);
}
void snake::changedir(char dir){
    direction=dir;
}
void snake::move_snake()
{
     switch(direction)
     {
        case 'u' :pos.Y-=val;break;
        case 'd':pos.Y+=val;break;
        case 'r':pos.X+=val;break;
        case 'l':pos.X-=val;break;
     }
     body.push_front(pos);
  while (body.size() > len) {
        body.pop_back();
    }
    }

COORD snake::getpos()
{
    return pos;
}

bool snake::eaten(COORD foodpos)
{
    if(foodpos.X== pos.X && foodpos.Y==pos.Y)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void snake::grow()
{
    len++;
}

bool snake::collided()
{
    if(pos.X <= 0 || pos.X >= width - 1 || pos.Y <= 0 || pos.Y >= height - 1)
    {
        return true;
    }
    else{
        return false;
    }
}

const std::deque<COORD> &snake::getBody()
{
    return body;
}
