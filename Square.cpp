#include "Square.h"
#include <iostream>


Square::Square()
{
	n = 4;
	data = new double* [n];
	for (int i = 0; i < n; i++)
		data[i] = new double[n];
	for (int i = 0; i < n - 1; i++)
		addRandom();
}

Square::Square(int N)
{
	n = N;
	data = new double* [n];
	for (int i = 0; i < n; i++)
		data[i] = new double[n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			data[i][j] = 0;
	for (int i = 0; i < n - 1; i++)
		addRandom();
}

void Square::show()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cout << data[i][j] << "\t";
		}
		std::cout << std::endl;
	}
}

void Square::addRandom()
{
	bool i = false;
	while (i == false)
	{
		int x = rand() % n;
		int y = rand() % n;
		if (data[x][y] == 0)
		{
			data[x][y] = 2;
			i = true;
		}
	}
}
