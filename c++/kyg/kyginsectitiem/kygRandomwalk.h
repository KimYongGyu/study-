#pragma once
#include "kygMatrixI.h"
#include <time.h>
#include <Windows.h>
 
//Random Walk�� ���� ���������� �����ϴ� �Լ�
//�Է�: ���� ���� ���Ǽ�
//2���� �迭 _map�� �������� �Ҵ��ϰ� �ʱ�ȭ ��
class RandomWalk : public MatrixI
{
protected:
//	MatrixI map; //��
	int nMove; //���� �̵� Ƚ��
	int x;  // ���� ��ġ
	int y;  // ���� ��ġ
public:
 
	RandomWalk(int rows=0, int cols=0):MatrixI(rows,cols),nMove(0)	{	}
 
	~RandomWalk(void)
	{
	}
	int Rows() {return rows;}
	int Cols() {return cols;} 
	int& Map(int i, int j) {return mat[i][j];}
 
	//������ �ʱ� ��ġ�� ����
	void setPosition(int yy, int xx) {x=xx;y=yy;}
 
	//������ Random Walk map�� ��� �κ��� ������������ �Ǵ�
	bool isDone(){
 
		for( int i= 0; i<Rows(); i++)
			for(int j =0; j<Cols(); j++)
				if( Map(i,j) > 0)
					return false;
 
		return true;
	}
 
	//Random Walk map�� ���� ���¸� ȭ�鿡 �����
	void print(){
		system("cls");
		printf(" < Random Walk >\n");
		printf("\t�̵�Ƚ�� = %d\n",nMove);
		printf("----------------------------------\n");
		for( int i= 0; i<Rows(); i++){
			printf(" ");
			for(int j =0; j<Cols(); j++){
				if( i==y && j ==x)
					printf("@");
				else if( Map(i,j) == 0 )
					printf(".");
				else  printf("*");
			}
			printf("\n");
		}
		printf("----------------------------------\n");
	}
 
	//������ ���� ��ġ���� �������� 8���� �̿��� �ϳ��� �̵��ϴ� �Լ�
	//������ map�� ��� ������ ������ ���ϵ��� ó���ؾ� ��
	void nextPosition(){
		int dir;
		dir = rand()% 8;
		switch(dir)
		{
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
		if(x == Cols())  x=x-1;
		if(y<0) y=0;
		if(y ==Rows()) y=y-1;
		nMove++;
	}
	void move(){
		nextPosition();
		Map(y,x) =0;
		
	}
 
	//Random Walk�� ���� �Լ�
	//�Է�: �ִ� �̵�Ƚ��(maxwalk)�� �ѹ� �̵� �� ���� �ð�(wait)�� �Է�
	//���� �ð��� ���� sleep(msec)�Լ� �̿� (������ ���ͳ� ã�� ����)
	void play( int maxwalk, int wait = 10){
 
		setPosition(rand()%Rows(), rand() % Cols());
		set(1);
		print();
		fflush(stdin);
		printf(" ���͸� ������ �����մϴ�. ");
		getchar();
 
		for( int i=0; i<maxwalk; i++){
			move();
			print();
 
			if(isDone())
				break;
			Sleep(wait);
 
		}
	}
 
 
};