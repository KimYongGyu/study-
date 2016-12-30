#pragma once
#include <iostream>
#include <cstdio>
#include <cmath>
using std :: ostream;
using std :: istream;
using std :: cin;
using std :: cout;
using std :: endl;

class kygComplex
{
	double real;
	double imag;
public:

	 kygComplex& operator++();
 kygComplex operator++(int);
	kygComplex(double a = 0.0, double b = 0.0): real(a),imag(b){}
	void set(double r, double i ) {
		real = r;
		imag = i;
	}
	void read( char* msg = "복소수 입력=")
	{
		printf("	%s ", msg);
		scanf("%lf%lf",&real,&imag);
	};
	void print(char* msg = "복소수 = ")
	{
		printf("	%s %4.2f + %4.2fi\n", msg, real, imag);
	};
	void add(kygComplex a, kygComplex b)
	{
		real = a.real +b.real;
		imag = a.imag + b.imag;
	};
	double mag() {
		return sqrt(real*real + imag*imag);
	}
	friend kygComplex operator+ (kygComplex a,kygComplex b){
		kygComplex c;
		c.imag = a.imag + b.imag;
		c.real = a.real + b.real;
		return c;
	}
	friend kygComplex operator* ( double k, kygComplex a){
		kygComplex c;
		c.real = a.real*k;
		c.imag = a.imag*k;
		return c;
	}
	friend kygComplex operator* ( kygComplex a, double k){
		kygComplex c;
		c.real = a.real*k;
		c.imag = a.imag*k;
		return c;
	}
	friend kygComplex operator* ( kygComplex a, kygComplex b){
		kygComplex c;
		c.real = (a.real*b.real) - (a.imag*b.imag);
		c.imag = (a.imag*b.real)+(b.imag*a.real);
		return c;
	}
	void operator+= (kygComplex a){
		real += a.real;
		imag += a.imag;
	}
	
	

	bool operator> (kygComplex b){
		if(mag() > b.mag())
			return true;
		else
			return false;
	}
	friend ostream& operator<< (ostream& os, kygComplex c){
		os << c.real << " + " << c.imag << "i\n";
		return os;
	}
	friend istream& operator>> (istream& in, kygComplex c) {
		in >> c.real >> c.imag;
		if( !in )
			c = kygComplex(0.0, 0.0);
		return in;
	}
};

kygComplex& kygComplex::operator++()
{
 real++;
 imag++;
 return *this;
}

kygComplex kygComplex::operator++(int)
{
 kygComplex tmp(real,imag);
 real++;
 imag++;
 return tmp;
}