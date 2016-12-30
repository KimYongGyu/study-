#include "kygComplex.h"
#include "kygVector.h"

void main(){
	printf("\n\n\t2016년도 1학기 C++ 프로그래밍 실습과제 12 \n\n");
	kygComplex c1, c2, c3, c4(5,6), c5(5,6);
	double k = 3.0;
	
	c1.read("복소수 c1 입력 = ");
	c2.read("복소수 c2 입력 = ");

	printf("-----------------------------------------\n");
	c1.print("c1 = ");
	c2.print("c2 = ");
	printf("-----------------------------------------\n");

	printf(" c3 = c1 + c2 \n");
	c3 = c1 + c2;
	c3.print("c3 = ");

	printf(" c3 = %.1lf* c1\n",k);
	c3 = k*c1;
	c3.print("c3 = ");

	printf("c3 = c1* %.1lf\n",k);
	c3 = c1*k;
	c3.print("c3 = ");

	printf("c3 += c1\n");
	c3 += c1;
	c3.print("c3 = ");

	(c4++).print("c4(5,6)++ = ");
	(++c5).print("++c5(5,6) = ");

	printf("c3 > c1\n");
	if(c3>c1)
	printf("true\n");
	else
	printf("false\n");

	cout << c1 << c2;

	getchar();
	getchar();
	//-------------------------------------------------------------------벡터
	kygVector v1, v2, v3;
	v1.read();
	v2.read();
	printf("-----------------------------------------\n");
	v1.print("v1 = ");
	v2.print("v2 = ");
	printf("-----------------------------------------\n");

	printf(" v3 = v1 + v2 \n");
	v3 = v1 + v2;
	v3.print("v3 = ");

	printf(" v3 = %.1lf* v1\n",k);
	v3 = k*v1;
	v3.print("v3 = ");

	printf("v3 = v1* %.1lf\n",k);
	v3 = v1*k;
	v3.print("v3 = ");

	double a;
	a = v1 *v2;
	printf(" v1 * v2 = %lf \n",a);

	cout << v1 << v2;
	getchar();
	getchar();
}


