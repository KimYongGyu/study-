#pragma once
#include <cstring>
#include <cstdio>
#include <ctime>
#include <cstdlib>

class Player
{
	char	name[80];
	double	point;
	
	public:
		//����Ʈ �Ű������� ����ʱ�ȭ����Ʈ�� ���ÿ� ����Ͽ� �ִ��� �ڵ带 �ٿ���.
	Player(char* playername = "ȫ�浿" ,double score = 0.0) :point(score){
		strcpy(name,playername);
	}

	~Player(void)
	{
	}
	void set(char* playername, double score){
		strcpy(name,playername);
		point = score;
		
	}
	double getPoint(){return point;}//Ŭ�������� ������ �ǵ帮�� ���Ͽ� �ɹ��Լ��� ����.
	void read(FILE* fp){
		char str[20]; 
		fscanf(fp, "%s%lf%s", str,&point,name);//�ؽ�Ʈ�� �ִ� ������ ����� �̸��� �����´�.

	}
	void print(FILE* fp = stdout){
		fprintf(fp,"%5.3f\t %s\n", point, name );//������ ����� �̸��� �ؽ�Ʈ�� ���	
	}
};



