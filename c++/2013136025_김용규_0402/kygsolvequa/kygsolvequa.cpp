#include "kygquadfunc.h"
//#include "Complex.h"
void main()
{	/*
	kygComplex ca, cb, cc, cd, cf;
	ca= readComplex ("    A=");
	cb= readComplex ("    B=");
	cc= addComplex(ca, cb);
	cd= subComplex(ca,cb);
	ce=multComplex(ca,cb);
	cf=multScalar(ca,7.0);

	printComplex(ca,"       A = ");
	printComplex(cb,"       B = ");
	printComplex(cc,"     A+B = ");
	printComplex(cd,"     A-B = ");
	printComplex(ce,"     A*B = ");
	printComplex(cf,"     A*7.0 = ");
	*/
	int n;
	bool choice = true;  //프로그램을 다시 실행시키기 위해 bool을 사용함
	double	a, b, c;
	kygComplex	r1, r2;  //구조체 kygComplex
	while(choice){
		system("cls");  //화면을 깨끗이 하는 함수
		printf("\n******* [ 2016년도 1학기 C++ 프로그래밍 실습과제 04 ] ******");
		printf("\n\n             [ 이차방정식의 근을 구하는 프로그램 ]            ");
	readQuad( a, b, c );  //이차방정식을 입력받는 함수
	printqqq(a,b,c);  // 입력받은 이차방정식을 화면에 출력하는 함수
	n = solveQuad( a, b, c, r1, r2 );  // solveQuad()함수는 abc에 따라 값을 정하고 값에따라 n을 돌려주는 함수
	printQuadResult( r1, r2, n );  //풀어진 답 두개 혹은 한개를 출력하는 함수
	choice=resolve(); //resolve() 함수는 문자값에따라 다시할지 그만할지 정하는 함수
	}
}

/*
	Complex	a, b, c;
	a = readComplex();
	b = readComplex();
	c = addComplex( a, b );
	printComplex( a, "  A  = " );
	printComplex( b, "  B  = ");
	printComplex( c, " A+B = " );
*/