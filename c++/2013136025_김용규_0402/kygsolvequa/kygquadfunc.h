#pragma once
#include "kygComplex.h"
extern void	readQuad( double& a, double& b, double& c );
extern int solveQuad( double a, double b, double c,
						kygComplex& r1, kygComplex& r2 );
//return�޴°��� int���� n�̱⶧���� int���Լ��� ������
extern void printQuadResult( kygComplex r1, kygComplex r2, int n );
extern void printqqq(double& a, double& b, double& c);

 //�Ǻ����� �ѹ��� �����ִ� �Լ� ������ �����ϰ� ����ϱ⿡ �ζ������� ���
inline double dter( double a, double b, double c ) { 
	return (b*b)-(4*a*c) ;
}