#pragma once
#include <cstdio>
#include <cstdlib>
#include <cmath>

struct kygComplex
	//구조체 kygComplex구현하여 효과적으로 복소수를 다룸
{	double real;
	double imag;
};

inline void kygsetComplex( kygComplex& c, double r, double i ) {
	//kygsetComplex()함수는 자주사용되고 빨리사용되기에 인라인으로 구현하였다
	//각 kygComplex에 빠르게 넣어주는 함수
	c.real = r;
	c.imag = i;
	if(c.imag==-0)   //0이 -0이 되어서 오류를 없애는 코드
		c.imag=0;
	if(c.real==-0)
		c.real=0;
}

extern kygComplex readComplex( );
extern void printComplex( kygComplex c, char* str="복소수="  ); // 글자를 쓰지않을경우 디폴트를 사용하여 복소수가 출력되게 구현함
extern kygComplex addComplex( kygComplex a, kygComplex b );
extern bool resolve(); ///다시실행할지 물어보는함수 bool함수형으로 하여 true 와 false를 return 받는다

