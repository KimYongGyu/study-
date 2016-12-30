#pragma once
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using std :: ostream;
using std :: istream;
using std :: cin;
using std :: cout;
using std :: endl;

class kygVector
{
protected:
	int dim;		// 벡터의 차원
	double* v;
public:

	kygVector(kygVector& a) : dim(0), v(NULL) {
		alloc(a.dim); 
		for( int i=0 ; i<dim ; i++ )
			v[i] =  a.v[i];
	}
	kygVector& operator=(kygVector& a) {
		alloc(a.dim); 
		for( int i=0 ; i<dim ; i++ )
			v[i] =  a.v[i];
		return *this;
	}
	void alloc(int d)	{					// 매개변수를 받아 메모리 동적 할당
		if(d != dim)	{
			reset();
			dim = d;
			v = new double [dim];
		}
	}
	void reset()	{						// 메모리 제거
		if(dim > 0)	{
			dim = 0;
			delete []v;
		}
	}
	void setRandom()	{						// 벡터 값 무작위로 생성
		for(int i = 0; i < dim; i++)
			v[i] = (rand() %1000) / 10.0;
	}
	kygVector(int a = 0):dim(a){}
	void read(char* msg = "벡터 입력 =")	{	// 벡터 값 임의로 임력 가능
		printf("  %s 차원 = ", msg);
		int d;
		scanf("%d", &d);

		alloc(d);
		printf("  벡터의 내용 입력 (%d) = ", d);
		for(int i = 0; i < d; i++)
			scanf("%lf", v+i);
	}
	void print(char* msg = "벡터 = ")	{		// 출력
		printf("%s\n\t[%d차원] : ", msg, dim);
		for(int i = 0; i < dim; i++)
			printf("  %5.1lf ", v[i]);
		printf("\n");
		//printf("%2d\n", dim);
	}	

	void add(kygVector a, kygVector b){	// 복사 생성자 없이 두 벡터 값을 더하는 add함수
		if(a.dim != dim)
			alloc(a.dim);
		if(a.dim != b.dim)
			printf("벡터 차원 오류\n");
		else
			for(int i = 0; i < a.dim; i++)	{
				v[i] = a.v[i] + b.v[i];
			}		
	}

	friend kygVector operator+ (kygVector a, kygVector b){
		kygVector c;
		c.alloc(a.dim);
		c.add(a,b);
		return c;
	}
	friend kygVector operator* ( double k, kygVector a){
		kygVector c;
		c.alloc(a.dim);
		for(int i = 0; i < a.dim; i++)
			c.v[i] = k*a.v[i];
		return c;
	}
	friend kygVector operator* ( kygVector a, double k){
		kygVector c;
		c.alloc(a.dim);
		for(int i = 0; i < a.dim; i++)
			c.v[i] = k*a.v[i];
		return c;
	}
	friend double operator* (kygVector a, kygVector b){
		double c = 0;
		if(a.dim != b.dim )
			printf("벡터 차원 오류\n");
		else{
			for(int i = 0; i<a.dim; i++)
				c += a.v[i]*b.v[i];
		}
		return c;
	}
	friend ostream& operator<< (ostream& os, kygVector c){
		os << "(";
		for(int i = 0; i < c.dim; i++){
			os <<c.v[i];
			if(i != c.dim - 1)
				os<<",";
		}
		os << ")\n";
		return os;
	}
};

