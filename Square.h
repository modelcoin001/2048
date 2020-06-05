#pragma once
#include <stdlib.h>
class Square
{
private:
	int n;
	double** data;
public:
	Square();
	Square(int);

	void show();
	bool canGame();
	void move(int);//1 for UP, 2 for DOWN, 3 for LEFT, 4 for Right
	void removeZero(double[],int); //1 for UP, 2 for DOWN, 3 for LEFT, 4 for Right
	void summ(double[], int); //1 for UP, 2 for DOWN, 3 for LEFT, 4 for Right
	void addRandom();
};