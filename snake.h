#ifndef SNAKE_H
#define SNAKE_H
#include<windows.h>
#include <deque>
#define width 48
#define height 24
class snake
{
private:
    COORD pos;
int len;
int val;
char direction;
  std::deque<COORD> body; 
public:
snake(COORD pos,int val);
void changedir(char dir);
void move_snake();
COORD getpos();
bool eaten(COORD foodpos);
void grow();
bool collided();
const std::deque<COORD>& getBody();
};
#endif