#pragma once
#include <cstdio>

class kygComplex
{
	double real;
	double imag;
public:
	void set (double r, double i){
		real = r;
		imag = i;
	}
	void read(char* msg = " 복소수 입력 = ");
	void print(char* msg = " 복소수 = ");
	void add (kygComplex a, kygComplex b);
};

