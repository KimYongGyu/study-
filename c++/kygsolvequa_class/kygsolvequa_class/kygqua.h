#pragma once
#include "kygcomplex.h"

class QuadFn
{
	////������������ ���
	double a;
	double b;
	double c;

	double discriminant() { 	return (b*b)-(4*a*c) ;}

public:
	void read( char* msg = "�����������ǰ�� = " )
	{
		//2���������� �Է¹޴� �Լ�
		while(true){
			printf("%s",msg);
			scanf( "%lf%lf%lf", &a, &b, &c );
			if(a==0){
				printf("\n======�����������̾ƴմϴ�.�Է¿���!!======");
				//�����������̱⶧���� a�� 0�̵Ǹ� �Է¿����� �����
			}
			else if( a!= 0){ break;}
			//a�� 0�̾ƴҰ�� �׸���
		}
	}

	void add(QuadFn p, QuadFn q){

		a= p.a+q.a;
		b= p.b+q.b;
		c= p.c+q.c;
	}

	int solve( Complex& r1, Complex& r2 )
		//�Է¹��� abc�� ���� ���ϴ� �Լ� n�� return�ϱ⶧���� int���Լ��� �����Ͽ���
	{
		r1.set(0,0);
		r2.set(0,0);

		if(discriminant( )>0)
		{
			//�Ǻ����� 0���� ũ�� �Ǽ��� 2��������
			r1.set((-b+sqrt(discriminant()))/(2*a),0);
			r2.set((-b-sqrt(discriminant()))/(2*a),0);
			return 1;
		}

		else if(discriminant( )==0){
			//�Ǻ����� 0�̶�� �߱��Ѱ��� ����
			r1.set(-b/(2*a),0);
			r2.set(-b/(2*a),0);
			return 2;
		}
		else if(discriminant( )<0){
			//�Ǻ����� 0���� �۴ٸ� ��� 2��������
			r1.set(-b/(2*a),+sqrt(-discriminant())/(2*a));
			r2.set( -b/(2*a),-sqrt(-discriminant())/(2*a));
			return 3;
		}
	}

	void print(char* msg = " �Է¹��� ���������� = "){
		//printqqq()�Լ� �Էµ� ������������ ����ϴ��Լ�
		printf(" \n %s �� ���������� = %5.2fx^2",msg,a);
		//b�� 0�̶�� ����ġ�� 0�̾ƴ϶�� ���ǽǼ��� ���ǽǼ������� ����̴޶���
		if(b!=0){
			if(b<=0.00001)
				printf("  - %5.2fx", -b);
			if (b>=0.00001)
				printf("  + %5.2fx",b);
		}
		//���͵���
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

