#pragma once
#include "kygRandomwalk.h"
class RandomItemWalk : public RandomWalk
{
	int nitem;//아이템 획득점수
public:

	RandomItemWalk(int rows = 0, int cols = 0) : RandomWalk(rows, cols)	{nitem = 0;	}

	~RandomItemWalk(void)	{	}

	//Random하게 item을 맵에 추가함
	void setRandomitems(int numitems) {

		for(int a=0; a<numitems; a++){
				Map(rand() % Rows(),rand() % Cols())=(rand()%4+3);
			
		}
	}

	//벌레가 현재 위치에서 무작위로 8방향 이웃중 하나로 이동하는 함수
	//벌레가 map의 경계 밖으로 나가지 못하도록 처리해야함
	void move() {
		nextPosition();

		if(Map(y,x) > 1){
			Map(y,x)--;
			nitem++;
		}
		if(Map(y,x)==1)
			Map(y,x) =0;



	}
	//Random Walk map의 현재 상태를 화면에 출력함
	void print(){
		system("cls");
		printf(" < Random Walk >\n");
		printf("\t이동횟수 = %d\n",nMove);
		printf("\t아이템 획득 횟수 = %d\n",nitem);
		printf("----------------------------------\n");
		for( int i= 0; i<Rows(); i++){
			printf("\t");
			for(int j =0; j<Cols(); j++){
				printf(" ");
				if( i==y && j ==x)
					printf("@");
				else if( Map(i,j) == 0 )
					printf(".");
				else if( Map(i,j)>1)
					printf("%d",Map(i,j)-1);
				else  printf("*");
			}
			printf("\n");
		}
		printf("----------------------------------\n");
	}

	//Random walk의 메인함수
	//입력: 최대 이동 횟수(maxwalk)와 한번 이동 후 쉬는시간(wait)을 입력
	//쉬는 시간을 위해 sleep(msec) 함수 이용 ( 사용법은 인터넷 찾아볼 것)
	void play( int maxwalk, int wait = 20 ){

		setPosition(rand()%Rows(), rand() % Cols());
		set(1);
		setRandomitems(9);
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
		getchar();
		getchar();
	}

};