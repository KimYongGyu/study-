#include <stdio.h>
#include <stdlib.h>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#pragma once
class GuguGame
{
	int test;// �׽�Ʈ�� ����
	int an;;   // ������������ 
	int num;
	int su;
	int rul;
	int q; //�տ� ��
	int w;  //�ڿ� ��
	int e;  //����
	int i;  //��������
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
		printf("\t\t��� �׽�Ʈ �Ͻðڽ��ϱ�? :   ");
		scanf("%d",&test);
		fflush(stdin);
		printf("\t\t %d �� �׽�Ʈ�ϰڽ��ϴ�.\n",test);
		printf("\t��ȣ���� ũ���ѹ� �Ͻð� �غ� �Ǹ� ���͸� ��������.");
		getchar();
		system("cls");   //ȭ���� �����ϰ� �ٲ۴�.
		time_t start;
		time_t finish;
		
		start = clock();  // ���۽ð�


		for(i=1;i<=test;i++){

			srand(unsigned int(time(NULL)));        // �������� ������ش�.
			q=range_set(2);
			w=range_set();
			printf("\n\t[����%d]: %d x %d =  ",i,q,w);
			scanf("%d",&an);
			e=q*w;
			if(an==e){

				su++;
				num++;
				printf("\t\t\t\t\t����!! <���� ����� :  %d %% >\n",100*su/num);


			}
			if(an!=e){
				num++;
				printf("\t\t\t\t\t��  !! <���� ����� :  %d %% >\n",100*su/num);
			}

		}
		rul =100*su/num;
		finish = clock();   //����ð���
		duration = (double)(finish-start)/CLOCKS_PER_SEC;  //����ð����� ���۽ð����A�� ȣ��Ǿ������� �ý��� �ð����� ������.
		printf("\t\t  ��ü %d �� �߿��� %d ���� ���߼̽��ϴ�.\n",test,su);
		printf("\t\t   �� ������ ��� %.1lf�ʰ� �ɷȽ��ϴ�.\n",duration);

		if(100*su/num == 100){
			printf("\t\t ��ü ����� %d %�� Ranking�� ��ϵ˴ϴ�!!\n\n",rul);
		}
		else{
			printf("\t\t ��ü ����� %d %�� Ranking�� ��ϵ��� �ʽ��ϴ�!!\n\n",rul);
		}
	}
};
inline int range_set(int from =1 ,int to = 9 )    // �������� ������ش�. �ζ����Լ��� ����Ʈ�� �Բ����
{
	return ( rand()%(to-from)+from );
}


