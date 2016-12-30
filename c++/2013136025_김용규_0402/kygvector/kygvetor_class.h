#pragma once
#include "cstdlib"
#include "cstdio"
class Vector
{
	int dim;// ������ ����
	double* v;

private:
	void alloc( int d){
		if (d != dim){
			reset();
			dim = d;
			v = new double [dim];
		}
	}
	void reset(){
		if(dim >0){
			dim = 0;
			delete []v;
		}
	}
public:

	Vector(int d = 0) :dim(0), v(NULL)	{ alloc(d);	}
	Vector(Vector& c)		{
		dim = c.dim;
		v = new double [dim];
		for(int i = 0; i<dim ;i++)
		{
			v[i]=c.v[i];
		}
	}
	~Vector()	{ reset(); }

	// ���Ҽ� ������ �����ϴ� �Լ� : inline
	void setRandom(){
		for(int i=0;i<dim;i++)
			v[i] = (rand() % 1000) / 10.0;
	}
	void read(char* msg = " ���� �Է� "){
		printf("  %s ���� = ",msg);
		int d;
		scanf("%d",&d);

		alloc(d);
		printf(" ������ ���� �Է�(%d��) = ", d);
		for(int i=0; i<d; i++)
			scanf("%lf", v+i);
	}
	void print(char* msg = "���� = " ){
		printf("%s\n\t[%d����] : ",msg,dim);
		for(int i =0; i<dim; i++)
			printf(" %5.1f ", v[i]);

		printf("\n",dim);
	}

	void add(Vector a, Vector b){
		if(a.dim!=b.dim)return;


		alloc(a.dim);
		for(int i = 0; i<dim ;i++)
		{
			v[i]=a.v[i]+b.v[i];
		}


	}
};

