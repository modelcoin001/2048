
#include <iostream>
#include "Square.h";


void print(Square& a, int n)
{
    for (int j = 0; j < n; j++)
    {
        for (int l = 0; l < n; l++)
        {
            std::cout << a.getItem(j, l) << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main()
{
    int n = 4;
    std::cout << "Hello World!\n";
    system("cls");
    Square a(4);
    print(a, n);
    a.move_left();
    print(a, n);
    a.move_up();
    print(a, n);
    a.move_right();
    print(a, n);
    a.move_down();
    print(a, n);
}
