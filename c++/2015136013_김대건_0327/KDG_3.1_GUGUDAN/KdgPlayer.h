#pragma once
#include <cstdio>
#include <cstring>
/*stdin 입력
	stdout 출력
	fopen() 
	fclose()
	r 읽기	NULL
	w 새로쓰기	파일이 없으면 파일을 새로 만듬
	a 이어쓰기	파일이 없으면 파일을 새로 만듬
	*/
class player
{
	double score;
	char name[80];
public:
	player(void){}
	~player(void){}

	double getscore() { return score; }//클래스내의 변수를 건드리기 위하여 맴버함수를 썻다.
	void set(char *na, double scr) {//점수와 경기자이름을 등록
		score = scr;
		strcpy(name, na);
	}

	void print(FILE* fp = stdout) {
		fprintf(fp,"%5.3f\t %s\n", score, name );//점수와 경기자 이름을 텍스트에 기록
	}
	void read(FILE* fp) {
		char str[20]; 
		fscanf(fp, "%s%lf%s", str,&score,name);//텍스트에 있는 점수와 경기자 이름을 가져온다.
	}
};