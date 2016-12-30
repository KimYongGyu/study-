#pragma once
#include "kygplayer.h"
class Ranking
{
	char	filename[80];
	Player list[10];
	int	length;
	int findPos(double spg){
		int pos=0;//텍스트에 등록된 플레이어의 숫자
		for( pos ; pos<length ; pos++)
			if( spg < list[pos].getPoint() )//순위 계산
				break;
		return pos;
	}
public:
	Ranking(char* fileName = "Ranking.txt"){
		strcpy(filename,fileName);
		load(filename);
	}

	~Ranking(void)
	{store(filename);
	}
	void load(char* fileName){  //파일로드함수
		strcpy(filename,fileName);
		length = 0;
		FILE *fp = fopen(filename , "r");
		if(fp == NULL ) return;
		fscanf(fp, "%d", &length);
		if( length > 10 )
			length = 10;

		for( int i = 0 ; i <length ; i++ )
			list[i].read(fp);
		fclose(fp);
	}
	void store(char* fileName ){  //파일저장함수
		strcpy(filename,fileName);
		FILE *fp = fopen(filename, "w");
		if(fp == NULL ) return;
		fprintf(fp, "%d\n", length);
		print(fp);
		fclose(fp);
	}
	void print(FILE* fp = stdout)  //파일출력함수
	{
		for( int i =0; i<length ; i++){
			fprintf(fp, "%2d:\t", i+1);
			list[i].print(fp);
		}
	}

	void add(char* name, double spg)  //랭킹을 더해주는 함수
	{
		int pos = findPos(spg);
		if( pos >= 9 )  //랭킹을 등록해야 하는 숫자보다 크면 함수를 끝냄
			return;
		if(length < 9 )  //랭킹에 등록시키고 등록된 숫자 갱신
			length++;
		for( int i=length-1 ; i > pos ; i--) {
			list[i] = list[i-1];
		}
		list[pos].set(name,spg);
	}
};
