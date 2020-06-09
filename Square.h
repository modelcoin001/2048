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
	int empty();
public:
	Square();
	Square(int);

	void addRandom(int);
	
	void move_right();
	void move_left();
	void move_down();
	void move_up();

	double getItem(int, int);
	bool canGame();
	double getMax();
};