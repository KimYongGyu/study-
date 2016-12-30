#include "kygComplex.h"
kygComplex readComplex( )  // 복소수를 입력 받는 함수 
{
	kygComplex c;
	printf( "  복소수 입력: ");
	scanf( "%lf%lf", &c.real, &c.imag);
	return c;
	///kygComplex 형 c를 return 받는다
}
void printComplex( kygComplex c, char* str )  //정해진 c를 화면에 출력하는 함수
{
	printf( "  %s %5.2f + %5.2fi\n", str, c.real, c.imag );
}
kygComplex addComplex( kygComplex a, kygComplex b ) //복소수 a와 복소수 b를 더하는 함수
{
	kygComplex c;
	c.real = a.real + b.real;
	c.imag = a.imag + b.imag;
	return c;
	///kygComplex 형 c를 return 받는다
}
kygComplex subComples( kygComplex a, kygComplex b)  // 복소수 a와 복소수 b를 빼는 함수
{
	kygComplex c;
	c.real = a.real - b.real;
	if(c.real <0.00001)
		c.real = -c.real;
	c.imag = a.imag - b.imag;
	if(c.imag < 0.00001)
		c.imag = - c.imag;
	return c;
	///kygComplex 형 c를 return 받는다
}
kygComplex multComplex( kygComplex a, kygComplex b) //복소수 a와 복소수b를 곱하는 함수
{
	kygComplex c;
	c.real = (a.real*b.real-a.imag*b.imag);
	c.imag = (a.real*b.imag+a.imag*b.real);
	return c;
	///kygComplex 형 c를 return 받는다
}
kygComplex multscalar( kygComplex a,double b)  ///정해진 b와 복소수a를 곱하는 함수
{
	kygComplex c;
	c.real =a.real*b;
	c.imag= a.imag*b;
	return c;
	///kygComplex 형 c를 return 받는다
}
bool resolve()
{	
	char re ='y';
	printf("\n다시 하시겠습니까 ( Y / N )");
	fflush(stdin);
		scanf("%c",&re);
			while(re != 'Y' && re!='y'&& re!= 'N' && re!= 'n' )//네가지입력이 전부 아니면
		{
			printf("\n입력오류!!\n다시 입력하세요");
			fflush(stdin);
			scanf("%c",&re);
		}
			if(re == 'y' ||re == 'Y')
			return true;
			if(re == 'N' || re== 'n')
				return false;
}