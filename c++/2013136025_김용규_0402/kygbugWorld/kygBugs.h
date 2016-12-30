#pragma once
#include "kygBug.h"
class kygBugs : public kygBug
{
public:

	kygBugs(char ch = 'K', int px = 0, int py = 0) : kygBug(ch ,px,py)	{ }

	~kygBugs(void)	{	}

	void Move(int rows, int cols ) {
		int dir = rand() %4;
		switch(dir){
		case 0: x++;y++; break;
		case 1: x--;y++; break;
		case 2: x--;y--; break;
		case 3: x++;y--; break;
		
		}
		if(x<0) x=0;
		if(x == cols)  x=x-1;
		if(y<0) y=0;
		if(y ==rows) y=y-1;
		nMove++;
	}
	void PrintStatus(){
		printf("kygBugs ");
		kygBug::PrintStatus();
	}
};

