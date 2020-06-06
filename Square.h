#pragma once
#include <stdlib.h>
#include<vector>

class Square
{
private:
	int n;
	double** data;
	void delete_zero(std::vector<double>& temp);
	void summ(std::vector<double>& temp);
	void erase_column(int);// забить столбец нулями
	void erase_row(int);// забить строку нулями
public:
	Square();
	Square(int);

	bool canGame();
	void addRandom();
	
	void move_right();
	void move_left();
	void move_down();
	void move_up();

	int getItem(int, int);
};