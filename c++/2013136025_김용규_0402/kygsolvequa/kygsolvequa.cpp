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
	bool choice = true;  //���α׷��� �ٽ� �����Ű�� ���� bool�� �����
	double	a, b, c;
	kygComplex	r1, r2;  //����ü kygComplex
	while(choice){
		system("cls");  //ȭ���� ������ �ϴ� �Լ�
		printf("\n******* [ 2016�⵵ 1�б� C++ ���α׷��� �ǽ����� 04 ] ******");
		printf("\n\n             [ ������������ ���� ���ϴ� ���α׷� ]            ");
	readQuad( a, b, c );  //������������ �Է¹޴� �Լ�
	printqqq(a,b,c);  // �Է¹��� ������������ ȭ�鿡 ����ϴ� �Լ�
	n = solveQuad( a, b, c, r1, r2 );  // solveQuad()�Լ��� abc�� ���� ���� ���ϰ� �������� n�� �����ִ� �Լ�
	printQuadResult( r1, r2, n );  //Ǯ���� �� �ΰ� Ȥ�� �Ѱ��� ����ϴ� �Լ�
	choice=resolve(); //resolve() �Լ��� ���ڰ������� �ٽ����� �׸����� ���ϴ� �Լ�
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