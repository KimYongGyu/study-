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
	void read(char* msg = " ���Ҽ� �Է� = ");
	void print(char* msg = " ���Ҽ� = ");
	void add (kygComplex a, kygComplex b);
};

