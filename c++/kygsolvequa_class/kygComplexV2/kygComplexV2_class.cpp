#include "kygComplexV2_class.h"

void kygComplex::readkygComplex(char* msg)
{
	printf (" %s ", msg);
	scanf("%lf%lf",&real, &imag);
}
void kygComplex::printkygComplex (char* msg)
{
	printf( " %s %4.2f + %4.2fi\n",msg,real,imag);
}
void kygComplex::addkygComplex(kygComplex a, kygComplex b)
{
	real = a.real+b.real;
	imag = a.imag+b.imag;
}

