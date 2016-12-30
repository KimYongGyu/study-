#pragma once
#include "kygMatrixI.h"
#include <time.h>
#include <Windows.h>
 
//Random Walk를 위한 전역변수를 설정하는 함수
//입력: 행의 수와 열의수
//2차원 배열 _map을 동적으로 할당하고 초기화 함
class RandomWalk : public MatrixI
{
protected:
//	MatrixI map; //맵
	int nMove; //현재 이동 횟수
	int x;  // 현재 위치
	int y;  // 현재 위치
public:
 
	RandomWalk(int rows=0, int cols=0):MatrixI(rows,cols),nMove(0)	{	}
 
	~RandomWalk(void)
	{
	}
	int Rows() {return rows;}
	int Cols() {return cols;} 
	int& Map(int i, int j) {return mat[i][j];}
 
	//벌레의 초기 위치를 설정
	void setPosition(int yy, int xx) {x=xx;y=yy;}
 
	//벌레가 Random Walk map의 모든 부분을 지나갔는지를 판단
	bool isDone(){
 
		for( int i= 0; i<Rows(); i++)
			for(int j =0; j<Cols(); j++)
				if( Map(i,j) > 0)
					return false;
 
		return true;
	}
 
	//Random Walk map의 현재 상태를 화면에 출력함
	void print(){
		system("cls");
		printf(" < Random Walk >\n");
		printf("\t이동횟수 = %d\n",nMove);
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
 
	//벌레가 현재 위치에서 무작위로 8방향 이웃중 하나로 이동하는 함수
	//벌레가 map의 경계 밖으로 나가지 못하도록 처리해야 함
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
 
	//Random Walk의 메인 함수
	//입력: 최대 이동횟수(maxwalk)와 한번 이동 후 쉬는 시간(wait)를 입력
	//쉬는 시간을 위해 sleep(msec)함수 이용 (사용법은 인터넷 찾아 볼것)
	void play( int maxwalk, int wait = 10){
 
		setPosition(rand()%Rows(), rand() % Cols());
		set(1);
		print();
		fflush(stdin);
		printf(" 엔터를 누르면 시작합니다. ");
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