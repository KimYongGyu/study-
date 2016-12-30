#pragma once
#include <cstdio>
#include <math.h>

class Complex
{
	double real;
	double imag;
public:
	//복소수 내용을 설정하는 함수 : inline,
	void set( double r, double i){
		real = r;
		imag = i;
	}
	void read( char* msg = "복소수 입력 = ")
	{
		printf( "  %s  ",msg);
		scanf("%lf%lf", &real, &imag);
	}
	void print(char* msg = "복소수 = ")
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
			printf("\n 실근1 = %3.2f\n",r1.real,r1.imag );
			printf("\n 실근2 = %3.2f\n",r2.real,r2.imag );
		}
		if(n==2){
			printf("\n중근 = %3.2f",r1.real);}
		if(n==3){
			//r1의 real가 0이아닐때 real과 imag출력
			if(r1.real!=0){
				if(r1.imag>=0.00001)
					printf("\n 허근1 = %3.2f + %3.2fi \n",r1.real,r1.imag);
				if(r1.imag<=0.00001)
					printf("\n 허근1 = %3.2f - %3.2fi \n" ,r1.real,-r1.imag);
			}
			//r1의real이 0일때 imag만 출력
			else if(r1.real ==0)
			{
				if(r1.imag>=0.00001)
					printf("\n 허근1 =  %3.2fi \n",r1.imag);
				if(r1.imag<=0.00001)
					printf("\n 허근1 = - %3.2fi \n" ,-r1.imag);
			}
			//위와동일
			if(r2.real!=0){
				if(r2.imag>=0.00001)
					printf("\n 허근2 = %3.2f + %3.2fi \n",r2.real,r2.imag);
				if(r2.imag<=0.00001)
					printf("\n 허근2 = %3.2f - %3.2fi \n" ,r2.real,-r2.imag);
			}
			else if(r2.real ==0)
			{
				if(r2.imag>=0.00001)
					printf("\n 허근2 =  %3.2fi \n",r2.imag);
				if(r2.imag<=0.00001)
					printf("\n 허근2 = - %3.2fi \n" ,-r2.imag);
			}
		}
	}
};
