#pragma once
#include "kygBug.h"
class kygDrunkenBug : public kygBug
{
public:

	kygDrunkenBug(char ch = 'D', int px = 0, int py = 0) : kygBug(ch ,px,py)	{ }

	~kygDrunkenBug(void)	{	}

	void Move(int rows, int cols ) {
		int dir = rand() %2;
		switch(dir){
		case 0: x++; break;
		case 1: x--; break;
		}
		if( x< 0 ) x=0;
		if(x ==cols) x= x-1;
		nMove++;
	}
	void PrintStatus(){
		printf("DrunkenBug ");
		kygBug::PrintStatus();
	}
};

