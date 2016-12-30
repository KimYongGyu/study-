#include "kygComplexV3_class.h"

void kygComplex::read(char* msg)
{
	printf (" %s ", msg);
	scanf("%lf%lf",&real, &imag);
}
void kygComplex::print (char* msg)
{
	printf( " %s %4.2f + %4.2fi\n",msg,real,imag);
}
void kygComplex::add(kygComplex a, kygComplex b)
{
	real = a.real+b.real;
	imag = a.imag+b.imag;
}
