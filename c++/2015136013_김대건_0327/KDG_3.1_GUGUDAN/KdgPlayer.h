#pragma once
#include <cstdio>
#include <cstring>
/*stdin �Է�
	stdout ���
	fopen() 
	fclose()
	r �б�	NULL
	w ���ξ���	������ ������ ������ ���� ����
	a �̾��	������ ������ ������ ���� ����
	*/
class player
{
	double score;
	char name[80];
public:
	player(void){}
	~player(void){}

	double getscore() { return score; }//Ŭ�������� ������ �ǵ帮�� ���Ͽ� �ɹ��Լ��� ����.
	void set(char *na, double scr) {//������ ������̸��� ���
		score = scr;
		strcpy(name, na);
	}

	void print(FILE* fp = stdout) {
		fprintf(fp,"%5.3f\t %s\n", score, name );//������ ����� �̸��� �ؽ�Ʈ�� ���
	}
	void read(FILE* fp) {
		char str[20]; 
		fscanf(fp, "%s%lf%s", str,&score,name);//�ؽ�Ʈ�� �ִ� ������ ����� �̸��� �����´�.
	}
};