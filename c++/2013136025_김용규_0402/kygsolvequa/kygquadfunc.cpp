#include "kygquadfunc.h"
void readQuad( double& a, double& b, double& c )
{
//2차방정식을 입력받는 함수
while(true){
	printf( "\n\n  2차 방정식 계수 입력  : ");
	scanf( "%lf%lf%lf", &a, &b, &c );
	if(a==0){
		printf("\n======입력오류!!======");
		//이차방정식이기때문에 a가 0이되면 입력오류를 출력함
	}
	else if( a!= 0){ break;}
	//a가 0이아닐경우 그만함
}
}

int solveQuad( double a, double b, double c,
				kygComplex& r1, kygComplex& r2 )
//입력받은 abc로 근을 구하는 함수 n을 return하기때문에 int형함수로 구현하였다
{
	r1.imag =0;
	r1.real=0;
	r2.real =0;
	r2.imag=0;
	if(dter( a,  b, c)>0)
	{
	//판별식이 0보다 크면 실수근 2개가나옴
		kygsetComplex(r1,(-b+sqrt((b*b)-(4*a*c)))/(2*a),0);
		kygsetComplex(r2,(-b-sqrt((b*b)-(4*a*c)))/(2*a),0);
		return 1;
	}

	else if(dter( a,  b, c)==0){
	//판별식이 0이라면 중근한개가 나옴
		kygsetComplex(r1,-b/(2*a),0);
		kygsetComplex(r2,-b/(2*a),0);
		return 2;
	}
	else if(dter( a,  b, c)<0){
	//판별식이 0보다 작다면 허근 2개가나옴
		kygsetComplex(r1,-b/(2*a),+sqrt((4*a*c)-(b*b))/(2*a));
		kygsetComplex(r2, -b/(2*a),-sqrt((4*a*c)-(b*b))/(2*a));
		return 3;
	}
}
void printQuadResult( kygComplex r1, kygComplex r2, int n )
	//판별식과 풀어진값을 출력하는함수
{
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

void printqqq(double& a, double& b, double& c){
	//printqqq()함수 입력된 이차방정식을 출력하는함수
	printf("  입력된 이차방정식 = %5.2fx^2",a);
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
		printf("  - %5.2fi\n\n",-c);
	if(c>=0.00001)
		printf("  + %5.2fi\n\n",c);
	}
}
	/*
	
		if(r1.imag >0)
	printf("\n 허근1 = %3.2f +%3.2f",r1.real,r1.imag );
		else if(r1.imag<0)
			printf("\n 허근1 = %3.2f %3.2f",r1.real,r1.imag );
		if(r2.imag>0)
	printf("\n 허근2 = %3.2f +%3.2f",r2.real,r2.imag );
		else if(r2.imag<0)
			printf("\n 허근2 = %3.2f %3.2f",r2.real,r2.imag );
	
	*/

	/*
	if(b>0 && c>0)
	printf("입력된 이차방정식 = %5.2fx^2 + %5.2fx + %5.2f\n\n", a,b,c);
	else if(b<0 && c>0)	
	printf("입력된 이차방정식 = %5.2fx^2  %5.2fx + %5.2f\n\n", a,b,c);
	else if(b<0 && c<0)
	printf("입력된 이차방정식 = %5.2fx^2  %5.2fx  %5.2f\n\n", a,b,c);
	else if(b>0 &&c<0)
	printf("입력된 이차방정식 = %5.2fx^2 + %5.2fx  %5.2f\n\n", a,b,c);


	
		if(r1.real!=0){
		if(r1.imag>=0.00001)
			printf(" 허근1 = %3.2f + %3.2fi \n",r1.real,r1.imag);
		if(r1.imag<=0.00001)
			printf(" 허근1 = %3.2f - %3.2fi \n" ,r1.real,-r1.imag);
		}
	
		else if(r2.real ==0)
		{
			if(r1.imag>=0.00001)
			printf(" 허근1 =  %3.2fi \n",r1.imag);
		if(r1.imag<=0.00001)
			printf(" 허근1 = - %3.2fi \n" ,-r1.imag);
		}

		if(r2.real!=0){
		if(r2.imag>=0.00001)
			printf(" 허근2 = %3.2f + %3.2fi \n",r2.real,r2.imag);
		if(r1.imag<=0.00001)
			printf(" 허근2 = %3.2f - %3.2fi \n" ,r2.real,-r2.imag);
		}
	
		else if(r2.real ==0)
		{
			if(r1.imag>=0.00001)
			printf(" 허근2 =  %3.2fi \n",r2.imag);
		if(r1.imag<=0.00001)
			printf(" 허근2 = - %3.2fi \n" ,-r2.imag);
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