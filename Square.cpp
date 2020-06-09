#include "Square.h"
#include <iostream>
#include <vector>
#include <algorithm>

void Square::delete_zero(std::vector<double>& temp)
{
	temp.erase(std::remove(temp.begin(), temp.end(), 0), temp.end());
}

void Square::summ(std::vector<double>& temp)
{
	for (int k = 0; k < temp.size() - 1; k++)
	{
		if (temp[k] == temp[k + 1])
		{
			temp[k] = temp[k] * 2;
			temp[k + 1] = 0;
		}
	}
}

void Square::erase_column(int column)
{
	for (int i = 0; i < n; i++)
	{
		data[i][column] = 0;
	}
}

void Square::erase_row(int row)
{
	for (int i =0; i < n; i++)
	{
		data[row][i] = 0;
	}
}

int Square::empty()
{
	int a = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (data[i][j] == 0)
				a++;
		}
	}
	return a;
}

Square::Square()
{
	n = 4;
	data = new double* [n];
	for (int i = 0; i < n; i++)
		data[i] = new double[n];
	addRandom(rand() % 2 + 1);
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
	addRandom(3);
}

void Square::addRandom(int raz)
{
	bool i = false;;
	int a = empty();
	switch (a)
	{
	case 1:
	{
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
		break;
	}
	case 0:
	{
		break;
	}
	default:
	{
		for (int j = 0; j < raz; j++)
		{
			i = false;
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
		break;
	}
	}
}

void Square::move_right()
{
	std::vector<double> temp;
	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < n; k++)
		{
			temp.push_back(data[i][k]);
		}
		delete_zero(temp);
		if (temp.size() > 0)
		{
			std::reverse(temp.begin(), temp.end());
			summ(temp);
			delete_zero(temp);
			temp.resize(n);
			std::reverse(temp.begin(), temp.end());
			erase_row(i);
			for (int k = 0; k < temp.size(); k++)
			{
				data[i][k] = temp[k];
			}
		}
		temp.clear();
	}
	addRandom(rand() %2 +1);
}

void Square::move_left()
{
	std::vector<double> temp;
	for (int i = 0; i < n; i++)
	{
		for (int k = 0;	k < n; k++)
		{
			temp.push_back(data[i][k]);		
		}
		delete_zero(temp);
		if (temp.size() > 0)
		{
			summ(temp);
			delete_zero(temp);
			erase_row(i);
			for (int k = 0; k < temp.size(); k++)
			{
				data[i][k] = temp[k];
			}
		}
		temp.clear();
	}
	addRandom(rand() % 2 + 1);
}

void Square::move_down()
{
	std::vector<double> temp;
	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < n; k++)
		{
			temp.push_back(data[k][i]);
		}
		delete_zero(temp);
		if (temp.size() > 0)
		{
			std::reverse(temp.begin(), temp.end());
			summ(temp);
			delete_zero(temp);
			temp.resize(n);
			std::reverse(temp.begin(), temp.end());
			erase_column(i);
			for (int k = 0; k < temp.size(); k++)
			{
				data[k][i] = temp[k];
			}
		}
		temp.clear();
	}
	addRandom(rand() % 2 + 1);
}

void Square::move_up()
{
	std::vector<double> temp;
	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < n; k++)
		{
			temp.push_back(data[k][i]);
		}
		delete_zero(temp);
		if (temp.size() > 0)
		{
			summ(temp);
			delete_zero(temp);
			erase_column(i);
			for (int k = 0; k < temp.size(); k++)
			{
				data[k][i] = temp[k];
			}
		}
		temp.clear();
	}
	addRandom(rand() % 2 + 1);
}

double Square::getItem(int i, int k)
{
	return data[i][k];
}

bool Square::canGame()
{
	bool can = true;
	bool same = false;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n-1; j++)
		{
			if (data[i][j]==data[i][j+1])
			{
				same = true;
			}
		}
	}
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (data[i][j] == data[i + 1][j])
			{
				same = true;
			}
		}
	}
	if ((empty()>0)||same)
	{
		can = true;
	}
	else
	{
		can = false;
	}
	return can;
}

double Square::getMax()
{
	double max = data[0][0];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (data[i][j]>max)
			{
				max = data[i][j];
			}
		}
	}
	return max;
}


