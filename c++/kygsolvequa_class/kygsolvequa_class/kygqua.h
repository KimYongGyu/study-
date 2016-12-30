#pragma once
#include "kygcomplex.h"

class QuadFn
{
	////이차방정식의 계수
	double a;
	double b;
	double c;

	double discriminant() { 	return (b*b)-(4*a*c) ;}

public:
	void read( char* msg = "이차방정식의계수 = " )
	{
		//2차방정식을 입력받는 함수
		while(true){
			printf("%s",msg);
			scanf( "%lf%lf%lf", &a, &b, &c );
			if(a==0){
				printf("\n======이차방정식이아닙니다.입력오류!!======");
				//이차방정식이기때문에 a가 0이되면 입력오류를 출력함
			}
			else if( a!= 0){ break;}
			//a가 0이아닐경우 그만함
		}
	}

	void add(QuadFn p, QuadFn q){

		a= p.a+q.a;
		b= p.b+q.b;
		c= p.c+q.c;
	}

	int solve( Complex& r1, Complex& r2 )
		//입력받은 abc로 근을 구하는 함수 n을 return하기때문에 int형함수로 구현하였다
	{
		r1.set(0,0);
		r2.set(0,0);

		if(discriminant( )>0)
		{
			//판별식이 0보다 크면 실수근 2개가나옴
			r1.set((-b+sqrt(discriminant()))/(2*a),0);
			r2.set((-b-sqrt(discriminant()))/(2*a),0);
			return 1;
		}

		else if(discriminant( )==0){
			//판별식이 0이라면 중근한개가 나옴
			r1.set(-b/(2*a),0);
			r2.set(-b/(2*a),0);
			return 2;
		}
		else if(discriminant( )<0){
			//판별식이 0보다 작다면 허근 2개가나옴
			r1.set(-b/(2*a),+sqrt(-discriminant())/(2*a));
			r2.set( -b/(2*a),-sqrt(-discriminant())/(2*a));
			return 3;
		}
	}

	void print(char* msg = " 입력받은 이차방정식 = "){
		//printqqq()함수 입력된 이차방정식을 출력하는함수
		printf(" \n %s 의 이차방정식 = %5.2fx^2",msg,a);
		//b가 0이라면 지나치고 0이아니라면 양의실수와 음의실수에따라 출력이달라짐
		if(b!=0){
			if(b<=0.00001)
				printf("  - %5.2fx", -b);
			if (b>=0.00001)
				printf("  + %5.2fx",b);
		}
		//위와동일
		if(c!=0){
			if(c<=0.00001)
				printf("  - %5.2fi",-c);
			if(c>=0.00001)
				printf("  + %5.2fi",c);
		}
	printf("\n");
	}
};

	inline void printfResult( int n,Complex r1, Complex r2 )

	{
		Complex c;
		c.resolveprint(n,r1,r2);

	}

