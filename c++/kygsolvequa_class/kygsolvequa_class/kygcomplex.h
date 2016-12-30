#pragma once
#include <cstdio>
#include <math.h>

class Complex
{
	double real;
	double imag;
public:
	//���Ҽ� ������ �����ϴ� �Լ� : inline,
	void set( double r, double i){
		real = r;
		imag = i;
	}
	void read( char* msg = "���Ҽ� �Է� = ")
	{
		printf( "  %s  ",msg);
		scanf("%lf%lf", &real, &imag);
	}
	void print(char* msg = "���Ҽ� = ")
	{
		printf("  %s  %4.2f + %4.2fi\n",msg,real,imag);
	}
	void add( Complex a, Complex b)
	{
		real = a.real+b.real;
		imag = a.imag+b.imag;
	}


	void resolveprint(int n,Complex r1,Complex r2){
		if(n==1){
			printf("\n �Ǳ�1 = %3.2f\n",r1.real,r1.imag );
			printf("\n �Ǳ�2 = %3.2f\n",r2.real,r2.imag );
		}
		if(n==2){
			printf("\n�߱� = %3.2f",r1.real);}
		if(n==3){
			//r1�� real�� 0�̾ƴҶ� real�� imag���
			if(r1.real!=0){
				if(r1.imag>=0.00001)
					printf("\n ���1 = %3.2f + %3.2fi \n",r1.real,r1.imag);
				if(r1.imag<=0.00001)
					printf("\n ���1 = %3.2f - %3.2fi \n" ,r1.real,-r1.imag);
			}
			//r1��real�� 0�϶� imag�� ���
			else if(r1.real ==0)
			{
				if(r1.imag>=0.00001)
					printf("\n ���1 =  %3.2fi \n",r1.imag);
				if(r1.imag<=0.00001)
					printf("\n ���1 = - %3.2fi \n" ,-r1.imag);
			}
			//���͵���
			if(r2.real!=0){
				if(r2.imag>=0.00001)
					printf("\n ���2 = %3.2f + %3.2fi \n",r2.real,r2.imag);
				if(r2.imag<=0.00001)
					printf("\n ���2 = %3.2f - %3.2fi \n" ,r2.real,-r2.imag);
			}
			else if(r2.real ==0)
			{
				if(r2.imag>=0.00001)
					printf("\n ���2 =  %3.2fi \n",r2.imag);
				if(r2.imag<=0.00001)
					printf("\n ���2 = - %3.2fi \n" ,-r2.imag);
			}
		}
	}
};
