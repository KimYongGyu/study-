#pragma once
#include "

class Bug
{
protected:
	int x,y;  //���� ��ǥ
	char name;  //���� �̸�
	int nMove;  //���� �̵�Ƚ��
	int nItem;  //���� ������ ��


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

