#pragma once
#include <cstdio>
#include <cstdlib>
#include <cmath>

struct kygComplex
	//����ü kygComplex�����Ͽ� ȿ�������� ���Ҽ��� �ٷ�
{	double real;
	double imag;
};

inline void kygsetComplex( kygComplex& c, double r, double i ) {
	//kygsetComplex()�Լ��� ���ֻ��ǰ� �������Ǳ⿡ �ζ������� �����Ͽ���
	//�� kygComplex�� ������ �־��ִ� �Լ�
	c.real = r;
	c.imag = i;
	if(c.imag==-0)   //0�� -0�� �Ǿ ������ ���ִ� �ڵ�
		c.imag=0;
	if(c.real==-0)
		c.real=0;
}

extern kygComplex readComplex( );
extern void printComplex( kygComplex c, char* str="���Ҽ�="  ); // ���ڸ� ����������� ����Ʈ�� ����Ͽ� ���Ҽ��� ��µǰ� ������
extern kygComplex addComplex( kygComplex a, kygComplex b );
extern bool resolve(); ///�ٽý������� ������Լ� bool�Լ������� �Ͽ� true �� false�� return �޴´�

