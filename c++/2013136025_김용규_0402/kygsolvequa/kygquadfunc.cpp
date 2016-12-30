#include "kygquadfunc.h"
void readQuad( double& a, double& b, double& c )
{
//2���������� �Է¹޴� �Լ�
while(true){
	printf( "\n\n  2�� ������ ��� �Է�  : ");
	scanf( "%lf%lf%lf", &a, &b, &c );
	if(a==0){
		printf("\n======�Է¿���!!======");
		//�����������̱⶧���� a�� 0�̵Ǹ� �Է¿����� �����
	}
	else if( a!= 0){ break;}
	//a�� 0�̾ƴҰ�� �׸���
}
}

int solveQuad( double a, double b, double c,
				kygComplex& r1, kygComplex& r2 )
//�Է¹��� abc�� ���� ���ϴ� �Լ� n�� return�ϱ⶧���� int���Լ��� �����Ͽ���
{
	r1.imag =0;
	r1.real=0;
	r2.real =0;
	r2.imag=0;
	if(dter( a,  b, c)>0)
	{
	//�Ǻ����� 0���� ũ�� �Ǽ��� 2��������
		kygsetComplex(r1,(-b+sqrt((b*b)-(4*a*c)))/(2*a),0);
		kygsetComplex(r2,(-b-sqrt((b*b)-(4*a*c)))/(2*a),0);
		return 1;
	}

	else if(dter( a,  b, c)==0){
	//�Ǻ����� 0�̶�� �߱��Ѱ��� ����
		kygsetComplex(r1,-b/(2*a),0);
		kygsetComplex(r2,-b/(2*a),0);
		return 2;
	}
	else if(dter( a,  b, c)<0){
	//�Ǻ����� 0���� �۴ٸ� ��� 2��������
		kygsetComplex(r1,-b/(2*a),+sqrt((4*a*c)-(b*b))/(2*a));
		kygsetComplex(r2, -b/(2*a),-sqrt((4*a*c)-(b*b))/(2*a));
		return 3;
	}
}
void printQuadResult( kygComplex r1, kygComplex r2, int n )
	//�Ǻ��İ� Ǯ�������� ����ϴ��Լ�
{
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

void printqqq(double& a, double& b, double& c){
	//printqqq()�Լ� �Էµ� ������������ ����ϴ��Լ�
	printf("  �Էµ� ���������� = %5.2fx^2",a);
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
		printf("  - %5.2fi\n\n",-c);
	if(c>=0.00001)
		printf("  + %5.2fi\n\n",c);
	}
}
	/*
	
		if(r1.imag >0)
	printf("\n ���1 = %3.2f +%3.2f",r1.real,r1.imag );
		else if(r1.imag<0)
			printf("\n ���1 = %3.2f %3.2f",r1.real,r1.imag );
		if(r2.imag>0)
	printf("\n ���2 = %3.2f +%3.2f",r2.real,r2.imag );
		else if(r2.imag<0)
			printf("\n ���2 = %3.2f %3.2f",r2.real,r2.imag );
	
	*/

	/*
	if(b>0 && c>0)
	printf("�Էµ� ���������� = %5.2fx^2 + %5.2fx + %5.2f\n\n", a,b,c);
	else if(b<0 && c>0)	
	printf("�Էµ� ���������� = %5.2fx^2  %5.2fx + %5.2f\n\n", a,b,c);
	else if(b<0 && c<0)
	printf("�Էµ� ���������� = %5.2fx^2  %5.2fx  %5.2f\n\n", a,b,c);
	else if(b>0 &&c<0)
	printf("�Էµ� ���������� = %5.2fx^2 + %5.2fx  %5.2f\n\n", a,b,c);


	
		if(r1.real!=0){
		if(r1.imag>=0.00001)
			printf(" ���1 = %3.2f + %3.2fi \n",r1.real,r1.imag);
		if(r1.imag<=0.00001)
			printf(" ���1 = %3.2f - %3.2fi \n" ,r1.real,-r1.imag);
		}
	
		else if(r2.real ==0)
		{
			if(r1.imag>=0.00001)
			printf(" ���1 =  %3.2fi \n",r1.imag);
		if(r1.imag<=0.00001)
			printf(" ���1 = - %3.2fi \n" ,-r1.imag);
		}

		if(r2.real!=0){
		if(r2.imag>=0.00001)
			printf(" ���2 = %3.2f + %3.2fi \n",r2.real,r2.imag);
		if(r1.imag<=0.00001)
			printf(" ���2 = %3.2f - %3.2fi \n" ,r2.real,-r2.imag);
		}
	
		else if(r2.real ==0)
		{
			if(r1.imag>=0.00001)
			printf(" ���2 =  %3.2fi \n",r2.imag);
		if(r1.imag<=0.00001)
			printf(" ���2 = - %3.2fi \n" ,-r2.imag);
		}
	*/

/*
if((b*b)-(4*a*c)>0)
	{
		r1.real = (-b+sqrt((b*b)-(4*a*c)))/(2*a);
		r2.real = (-b-sqrt((b*b)-(4*a*c)))/(2*a);
		
	}

	else if((b*b)-(4*a*c)==0){
		r1.real = -b/(2*a);
		r2.real = r1.real;

}
	else if((b*b)-(4*a*c)<0){
		r1.real = -b/(2*a);
		r2.real = -b/(2*a);

		r1.imag = +sqrt((4*a*c)-(b*b))/(2*a);
		r2.imag = -sqrt((4*a*c)-(b*b))/(2*a);
	}
	*/