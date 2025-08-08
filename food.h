#ifndef FOOD_H
#define FOOD_H
#include<windows.h>
#include<cstdlib>
#define width 48
#define height 24
class food {
      private:
      COORD pos;
      public:
      food();
      void genfood();
      COORD get_pos();
};
#endif 