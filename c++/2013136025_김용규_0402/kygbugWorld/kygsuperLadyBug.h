#pragma once
#include "kygBug.h"
class kygsuperLadyBug : public kygLadyBug
{
public:

	kygsuperLadyBug(char ch = 'S', int px = 0, int py = 0) : kygLadyBug(ch ,px,py)	{ }

	~kygsuperLadyBug(void)	{	}

	void Move(int rows, int cols ) {
		int dir = rand() %8;
		switch(dir){
		case 0: x=x+rand()%2+1; y=y-rand()%2+1; break;
		case 1: x=x+rand()%2+1;y  ; break;
		case 2: x=x+rand()%2+1;y=y+rand()%2+1; break;
		case 3: x  ;y=y+rand()%2+1; break;
		case 4: x=x-rand()%2+1;y=y+rand()%2+1; break;
		case 5: x=x-rand()%2+1;y  ; break;
		case 6: x=x-rand()%2+1;y=y-rand()%2+1; break;
		case 7: x  ;;y=y-rand()%2+1; break;
		}
		if(x<0) x=0;
		if(x >= cols)  x=cols-1;
		if(y<0) y=0;
		if(y >=rows) y=rows-1;
		nMove++;
	}
	void PrintStatus(){
		printf("kygsuperLadyBug ");
		kygBug::PrintStatus();
	}
};

