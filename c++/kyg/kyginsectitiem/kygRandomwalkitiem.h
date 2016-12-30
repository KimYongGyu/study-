#pragma once
#include "kygRandomwalk.h"
class RandomItemWalk : public RandomWalk
{
	int nitem;//������ ȹ������
public:

	RandomItemWalk(int rows = 0, int cols = 0) : RandomWalk(rows, cols)	{nitem = 0;	}

	~RandomItemWalk(void)	{	}

	//Random�ϰ� item�� �ʿ� �߰���
	void setRandomitems(int numitems) {

		for(int a=0; a<numitems; a++){
				Map(rand() % Rows(),rand() % Cols())=(rand()%4+3);
			
		}
	}

	//������ ���� ��ġ���� �������� 8���� �̿��� �ϳ��� �̵��ϴ� �Լ�
	//������ map�� ��� ������ ������ ���ϵ��� ó���ؾ���
	void move() {
		nextPosition();

		if(Map(y,x) > 1){
			Map(y,x)--;
			nitem++;
		}
		if(Map(y,x)==1)
			Map(y,x) =0;



	}
	//Random Walk map�� ���� ���¸� ȭ�鿡 �����
	void print(){
		system("cls");
		printf(" < Random Walk >\n");
		printf("\t�̵�Ƚ�� = %d\n",nMove);
		printf("\t������ ȹ�� Ƚ�� = %d\n",nitem);
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

	//Random walk�� �����Լ�
	//�Է�: �ִ� �̵� Ƚ��(maxwalk)�� �ѹ� �̵� �� ���½ð�(wait)�� �Է�
	//���� �ð��� ���� sleep(msec) �Լ� �̿� ( ������ ���ͳ� ã�ƺ� ��)
	void play( int maxwalk, int wait = 20 ){

		setPosition(rand()%Rows(), rand() % Cols());
		set(1);
		setRandomitems(9);
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
		getchar();
		getchar();
	}

};