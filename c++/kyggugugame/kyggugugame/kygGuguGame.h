#pragma once
#include "kygRanking.h"

class GuguGame
{
	int nGames;  //게임횟수
	int nWins;   //게임이긴수
	Ranking rank;
	void reset(){ nGames = 0; nWins=0;}
	int range_set(int from =1 ,int to = 9 )    // 랜덤으로 만들어준다. 인라인함수와 디폴트를 함께사용
	{
		return ( rand()%(to-from)+from );
	}
public:
	GuguGame(char *filename = "Ranking.txt") 	{	}
	void playOnce(){
		int q;
		int w;
		int e;
		int an=1;
		srand(unsigned int(time(NULL)));        // 랜덤으로 만들어준다.
		q=range_set(2);
		w=range_set();
		printf("\n\t[문제] : %d x %d =  ",q,w);
		scanf("%d",&an);
		e=q*w;
		if(an==e){
			printf(" 정답입니다!!");
			nWins++;
		}
		if(an!=e){
			printf(" 틀렷습니다!! ");
		}
	}
	void play(char* name , int n){
		Player a;		
		double duration;
		reset();
		nGames=n;
		time_t start;
		time_t finish;
		start = clock();  //시작시간
		for(int i=1;i<=nGames;i++){
			printf("\n\n%s 님 준비가 되면  엔터를 누르세요",name);
			getchar();
			system("cls");   //화면을 깨끗하게 바꾼다.
			playOnce();
		}
		finish = clock();   //종료시간시
		duration = (double)(finish-start)/CLOCKS_PER_SEC;  //종료시간에서 시작시간을뺸후 호출되었을때의 시스템 시각으로 나눈다.
		a.set(name, duration/nGames);
		printf("\n\t\t  전체 %d 번 중에서 %d 번을 맞추셨습니다.\n",nGames,nWins);
		printf("\n\t\t   한 문제에 평균 %.1lf초가 걸렸습니다.\n",a.getPoint());
		if( nWins==nGames)	{
			printf("\n\t\t 모두 맞추셧으므로 랭킹에 기록됩니다.");
			rank.add(name,a.getPoint());
			rank.store("Ranking.txt");
		}
		printf("\n\t\t\t 랭킹을 출력합니다.\n");
		rank.print();
		nGames =0;
		nWins = 0;
		printf("\n");
	}
};
