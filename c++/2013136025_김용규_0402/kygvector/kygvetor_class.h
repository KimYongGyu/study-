#pragma once
#include "cstdlib"
#include "cstdio"
class Vector
{
	int dim;// 백터의 차원
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

	// 복소수 내용을 설정하는 함수 : inline
	void setRandom(){
		for(int i=0;i<dim;i++)
			v[i] = (rand() % 1000) / 10.0;
	}
	void read(char* msg = " 벡터 입력 "){
		printf("  %s 차원 = ",msg);
		int d;
		scanf("%d",&d);

		alloc(d);
		printf(" 벡터의 내용 입력(%d개) = ", d);
		for(int i=0; i<d; i++)
			scanf("%lf", v+i);
	}
	void print(char* msg = "벡터 = " ){
		printf("%s\n\t[%d차원] : ",msg,dim);
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

