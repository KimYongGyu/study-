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
	void readkygComplex(char* msg = " 복소수 입력 = ");
	void printkygComplex(char* msg = " 복소수 = ");
	void addkygComplex (kygComplex a, kygComplex b);
};

