#pragma once
#include "kygBug.h"

class kygLadyBug : public kygBug
{
public:

	kygLadyBug(char ch = 'L', int px = 0, int py = 0) : kygBug(ch ,px,py)	{ }

	~kygLadyBug(void)	{	}

	void Move(int rows, int cols ) {
		int dir = rand() %8;
		switch(dir){
		case 0: x++;y--; break;
		case 1: x++;y  ; break;
		case 2: x++;y++; break;
		case 3: x  ;y++; break;
		case 4: x--;y++; break;
		case 5: x--;y  ; break;
		case 6: x--;y--; break;
		case 7: x  ;y--; break;
		}
		if(x<0) x=0;
		if(x == cols)  x=x-1;
		if(y<0) y=0;
		if(y ==rows) y=y-1;
		nMove++;
	}
	void PrintStatus(){
		printf("LadyBug ");
		kygBug::PrintStatus();
	}
};

