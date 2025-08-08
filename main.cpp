#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include "snake.h"
#include "food.h"

using namespace std;

#define width 48
#define height 24

snake s({width / 2, height / 2}, 1);
food f;
int score = 0;

void board()
{
    COORD food_pos = f.get_pos();
    const auto& body = s.getBody();

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0, 0});

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            bool printed = false;

            // Draw border
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
            {
                cout << "#";
                continue;
            }

            for (size_t k = 0; k < body.size(); ++k)
            {
                if (i == body[k].Y && j == body[k].X)
                {
                    cout << (k == 0 ? '@' : 'o');
                    printed = true;
                    break;
                }
            }

            if (printed) continue;

            if (i == food_pos.Y && j == food_pos.X)
                cout << '*';
            else
                cout << ' ';
        }
        cout << "\n";
    }

    cout << "Score: " << score << "\n";
    cout << "                                          \n";
}

int main()
{
    srand(time(NULL));
    bool collided = false;
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hOut, &cursorInfo);
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hOut, &cursorInfo);

    while (!collided)
    {
        board();

        if (kbhit())
        {
            switch (getch())
            {
            case 'w': s.changedir('u'); break;
            case 'a': s.changedir('l'); break;
            case 's': s.changedir('d'); break;
            case 'd': s.changedir('r'); break;
            }
        }

        s.move_snake();

        if (s.eaten(f.get_pos()))
        {
            f.genfood();
            s.grow();
            score += 10;
        }

        if (s.collided())
        {
            collided = true;
        }

        Sleep(100);
    }

    system("cls");
    cout << "\nGame Over! Snake collided with the wall.\n";
    cout << "Final Score: " << score << "\n";
}
