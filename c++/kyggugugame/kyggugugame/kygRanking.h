#pragma once
#include "kygplayer.h"
class Ranking
{
	char	filename[80];
	Player list[10];
	int	length;
	int findPos(double spg){
		int pos=0;//�ؽ�Ʈ�� ��ϵ� �÷��̾��� ����
		for( pos ; pos<length ; pos++)
			if( spg < list[pos].getPoint() )//���� ���
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
	void load(char* fileName){  //���Ϸε��Լ�
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
	void store(char* fileName ){  //���������Լ�
		strcpy(filename,fileName);
		FILE *fp = fopen(filename, "w");
		if(fp == NULL ) return;
		fprintf(fp, "%d\n", length);
		print(fp);
		fclose(fp);
	}
	void print(FILE* fp = stdout)  //��������Լ�
	{
		for( int i =0; i<length ; i++){
			fprintf(fp, "%2d:\t", i+1);
			list[i].print(fp);
		}
	}

	void add(char* name, double spg)  //��ŷ�� �����ִ� �Լ�
	{
		int pos = findPos(spg);
		if( pos >= 9 )  //��ŷ�� ����ؾ� �ϴ� ���ں��� ũ�� �Լ��� ����
			return;
		if(length < 9 )  //��ŷ�� ��Ͻ�Ű�� ��ϵ� ���� ����
			length++;
		for( int i=length-1 ; i > pos ; i--) {
			list[i] = list[i-1];
		}
		list[pos].set(name,spg);
	}
};
