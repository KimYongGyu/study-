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
	int dim;		// ������ ����
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
	void alloc(int d)	{					// �Ű������� �޾� �޸� ���� �Ҵ�
		if(d != dim)	{
			reset();
			dim = d;
			v = new double [dim];
		}
	}
	void reset()	{						// �޸� ����
		if(dim > 0)	{
			dim = 0;
			delete []v;
		}
	}
	void setRandom()	{						// ���� �� �������� ����
		for(int i = 0; i < dim; i++)
			v[i] = (rand() %1000) / 10.0;
	}
	kygVector(int a = 0):dim(a){}
	void read(char* msg = "���� �Է� =")	{	// ���� �� ���Ƿ� �ӷ� ����
		printf("  %s ���� = ", msg);
		int d;
		scanf("%d", &d);

		alloc(d);
		printf("  ������ ���� �Է� (%d) = ", d);
		for(int i = 0; i < d; i++)
			scanf("%lf", v+i);
	}
	void print(char* msg = "���� = ")	{		// ���
		printf("%s\n\t[%d����] : ", msg, dim);
		for(int i = 0; i < dim; i++)
			printf("  %5.1lf ", v[i]);
		printf("\n");
		//printf("%2d\n", dim);
	}	

	void add(kygVector a, kygVector b){	// ���� ������ ���� �� ���� ���� ���ϴ� add�Լ�
		if(a.dim != dim)
			alloc(a.dim);
		if(a.dim != b.dim)
			printf("���� ���� ����\n");
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
			printf("���� ���� ����\n");
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

