#pragma once
#include "kygRanking.h"

class GuguGame
{
	int nGames;  //����Ƚ��
	int nWins;   //�����̱��
	Ranking rank;
	void reset(){ nGames = 0; nWins=0;}
	int range_set(int from =1 ,int to = 9 )    // �������� ������ش�. �ζ����Լ��� ����Ʈ�� �Բ����
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
		srand(unsigned int(time(NULL)));        // �������� ������ش�.
		q=range_set(2);
		w=range_set();
		printf("\n\t[����] : %d x %d =  ",q,w);
		scanf("%d",&an);
		e=q*w;
		if(an==e){
			printf(" �����Դϴ�!!");
			nWins++;
		}
		if(an!=e){
			printf(" Ʋ�ǽ��ϴ�!! ");
		}
	}
	void play(char* name , int n){
		Player a;		
		double duration;
		reset();
		nGames=n;
		time_t start;
		time_t finish;
		start = clock();  //���۽ð�
		for(int i=1;i<=nGames;i++){
			printf("\n\n%s �� �غ� �Ǹ�  ���͸� ��������",name);
			getchar();
			system("cls");   //ȭ���� �����ϰ� �ٲ۴�.
			playOnce();
		}
		finish = clock();   //����ð���
		duration = (double)(finish-start)/CLOCKS_PER_SEC;  //����ð����� ���۽ð����A�� ȣ��Ǿ������� �ý��� �ð����� ������.
		a.set(name, duration/nGames);
		printf("\n\t\t  ��ü %d �� �߿��� %d ���� ���߼̽��ϴ�.\n",nGames,nWins);
		printf("\n\t\t   �� ������ ��� %.1lf�ʰ� �ɷȽ��ϴ�.\n",a.getPoint());
		if( nWins==nGames)	{
			printf("\n\t\t ��� ���߼����Ƿ� ��ŷ�� ��ϵ˴ϴ�.");
			rank.add(name,a.getPoint());
			rank.store("Ranking.txt");
		}
		printf("\n\t\t\t ��ŷ�� ����մϴ�.\n");
		rank.print();
		nGames =0;
		nWins = 0;
		printf("\n");
	}
};
