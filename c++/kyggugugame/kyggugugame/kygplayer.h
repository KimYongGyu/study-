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
		//디폴트 매개변수와 멤버초기화리스트를 동시에 사용하여 최대한 코드를 줄였다.
	Player(char* playername = "홍길동" ,double score = 0.0) :point(score){
		strcpy(name,playername);
	}

	~Player(void)
	{
	}
	void set(char* playername, double score){
		strcpy(name,playername);
		point = score;
		
	}
	double getPoint(){return point;}//클래스내의 변수를 건드리기 위하여 맴버함수를 썻다.
	void read(FILE* fp){
		char str[20]; 
		fscanf(fp, "%s%lf%s", str,&point,name);//텍스트에 있는 점수와 경기자 이름을 가져온다.

	}
	void print(FILE* fp = stdout){
		fprintf(fp,"%5.3f\t %s\n", point, name );//점수와 경기자 이름을 텍스트에 기록	
	}
};



