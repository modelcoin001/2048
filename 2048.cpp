
#include <iostream>
#include "Square.h";
#include <conio.h>


void print(Square& a, int n)
{
    for (int j = 0; j < n; j++)
    {
        for (int l = 0; l < n; l++)
        {
            if (a.getItem(j,l)==0)
            {
                std::cout << ".";
            }
            else
            {
                std::cout << a.getItem(j, l);
            }
            std::cout << "\t";
        }
        std::cout << std::endl;
    }
    for (int i = 0; i < n; i++)
    {
        std::cout << "---" << "\t";
    }
    std::cout << std::endl;
    std::cout << "a left" << std::endl << "s down" << std::endl << "d right" << std::endl << "w up" << std::endl << "ESC exit" << std::endl << std::endl;
}

int main()
{
    int n = 4;
    char c;
    system("cls");
    Square a(4);

    do {
        system("cls");
        print(a, n);
        c = _getch();
        switch (c)
        {
        case 72: case 'w': a.move_up();
               break;
        case 80: case 's': a.move_down();
               break;
        case 75: case 'a': a.move_left();
               break;
        case 77: case 'd': a.move_right();
               break;
        default:;
        }
        
    } while (a.canGame() && (c != 27)); // Esc
    std::cout << "Game Over!" << std::endl << "Your result is " << a.getMax();
}