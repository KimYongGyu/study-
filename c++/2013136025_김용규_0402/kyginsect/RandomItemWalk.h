#pragma once
#include "kygRandomwalk.h"
class RandomItemWalk : public RandomWalk
{
	int nitem;//������ ȹ������
public:

	RandomItemWalk(int rows = 0, int cols = 0) : RandomWalk(rows, cols)	{ntime = 0;	}

	~RandomItemWalk(void)	{	}

	//Random�ϰ� item�� �ʿ� �߰���
	void setRandomitems(int numitems) {
	}

	//������ ���� ��ġ���� �������� 8���� �̿��� �ϳ��� �̵��ϴ� �Լ�
	//������ map�� ��� ������ ������ ���ϵ��� ó���ؾ���
	void move() {
	}
	//Random Walk map�� ���� ���¸� ȭ�鿡 �����
	void print(){
	}

	//Random walk�� �����Լ�
	//�Է�: �ִ� �̵� Ƚ��(maxwalk)�� �ѹ� �̵� �� ���½ð�(wait)�� �Է�
	//���� �ð��� ���� sleep(msec) �Լ� �̿� ( ������ ���ͳ� ã�ƺ� ��)
	void play( int maxwalk, int wait = 0){
	}

};

