#pragma once
#include "

class Bug
{
protected:
	int x,y;  //현재 좌표
	char name;  //벌레 이름
	int nMove;  //현재 이동횟수
	int nItem;  //먹은 아이템 수


public:

	Bug(char ch = 'b', int py = 0, int px = 0) : nMove(0), nItem(0) , name(ch), x(px), y(py){	}

	~Bug(void)	{	}

	char GetName()  {return name;}
	void GetPosition(int& c, int& r) { c= x; r=y;}
	void Eat() {nItem++;}

	virtual void Move(int rows, int cols) =0;
	virtual void PrintStatus(){
	printf
	}
};

