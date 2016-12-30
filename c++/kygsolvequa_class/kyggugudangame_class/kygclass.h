#include <stdio.h>
#include <stdlib.h>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#pragma once
class GuguGame
{
	int test;// 테스트할 갯수
	int an;;   // 내가말한정답 
	int num;
	int su;
	int rul;
	int q; //앞에 곱
	int w;  //뒤에 곱
	int e;  //정답
	int i;  //문제갯수
	int gugu;
	double duration;

public:

	GuguGame(void)
	{
	}

	~GuguGame(void)
	{
	}
	void paly(){
		printf("\t\t몇번 테스트 하시겠습니까? :   ");
		scanf("%d",&test);
		fflush(stdin);
		printf("\t\t %d 번 테스트하겠습니다.\n",test);
		printf("\t심호흡을 크게한번 하시고 준비가 되면 엔터를 누르세요.");
		getchar();
		system("cls");   //화면을 깨끗하게 바꾼다.
		time_t start;
		time_t finish;
		
		start = clock();  // 시작시간


		for(i=1;i<=test;i++){

			srand(unsigned int(time(NULL)));        // 랜덤으로 만들어준다.
			q=range_set(2);
			w=range_set();
			printf("\n\t[문제%d]: %d x %d =  ",i,q,w);
			scanf("%d",&an);
			e=q*w;
			if(an==e){

				su++;
				num++;
				printf("\t\t\t\t\t정답!! <현재 정답률 :  %d %% >\n",100*su/num);


			}
			if(an!=e){
				num++;
				printf("\t\t\t\t\t땡  !! <현재 정답률 :  %d %% >\n",100*su/num);
			}

		}
		rul =100*su/num;
		finish = clock();   //종료시간시
		duration = (double)(finish-start)/CLOCKS_PER_SEC;  //종료시간에서 시작시간을뺸후 호출되었을때의 시스템 시각으로 나눈다.
		printf("\t\t  전체 %d 번 중에서 %d 번을 맞추셨습니다.\n",test,su);
		printf("\t\t   한 문제에 평균 %.1lf초가 걸렸습니다.\n",duration);

		if(100*su/num == 100){
			printf("\t\t 전체 정답률 %d %로 Ranking에 등록됩니다!!\n\n",rul);
		}
		else{
			printf("\t\t 전체 정답률 %d %로 Ranking에 등록되지 않습니다!!\n\n",rul);
		}
	}
};
inline int range_set(int from =1 ,int to = 9 )    // 랜덤으로 만들어준다. 인라인함수와 디폴트를 함께사용
{
	return ( rand()%(to-from)+from );
}


