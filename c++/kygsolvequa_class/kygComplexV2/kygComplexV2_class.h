#pragma once
#include <cstdio>

class kygComplex
{
	double real;
	double imag;
public:
	void setkygComplex (double r, double i){
		real = r;
		imag = i;
	}
	void readkygComplex(char* msg = " ���Ҽ� �Է� = ");
	void printkygComplex(char* msg = " ���Ҽ� = ");
	void addkygComplex (kygComplex a, kygComplex b);
};

