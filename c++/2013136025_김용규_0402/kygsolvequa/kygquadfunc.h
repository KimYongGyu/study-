#pragma once
#include "kygComplex.h"
extern void	readQuad( double& a, double& b, double& c );
extern int solveQuad( double a, double b, double c,
						kygComplex& r1, kygComplex& r2 );
//return받는것이 int형인 n이기때문에 int형함수로 구현함
extern void printQuadResult( kygComplex r1, kygComplex r2, int n );
extern void printqqq(double& a, double& b, double& c);

 //판별식을 한번에 구해주는 함수 빠르고 간편하게 사용하기에 인라인으로 사용
inline double dter( double a, double b, double c ) { 
	return (b*b)-(4*a*c) ;
}