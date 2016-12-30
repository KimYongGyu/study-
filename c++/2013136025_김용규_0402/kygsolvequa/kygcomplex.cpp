#include "kygComplex.h"
kygComplex readComplex( )  // ���Ҽ��� �Է� �޴� �Լ� 
{
	kygComplex c;
	printf( "  ���Ҽ� �Է�: ");
	scanf( "%lf%lf", &c.real, &c.imag);
	return c;
	///kygComplex �� c�� return �޴´�
}
void printComplex( kygComplex c, char* str )  //������ c�� ȭ�鿡 ����ϴ� �Լ�
{
	printf( "  %s %5.2f + %5.2fi\n", str, c.real, c.imag );
}
kygComplex addComplex( kygComplex a, kygComplex b ) //���Ҽ� a�� ���Ҽ� b�� ���ϴ� �Լ�
{
	kygComplex c;
	c.real = a.real + b.real;
	c.imag = a.imag + b.imag;
	return c;
	///kygComplex �� c�� return �޴´�
}
kygComplex subComples( kygComplex a, kygComplex b)  // ���Ҽ� a�� ���Ҽ� b�� ���� �Լ�
{
	kygComplex c;
	c.real = a.real - b.real;
	if(c.real <0.00001)
		c.real = -c.real;
	c.imag = a.imag - b.imag;
	if(c.imag < 0.00001)
		c.imag = - c.imag;
	return c;
	///kygComplex �� c�� return �޴´�
}
kygComplex multComplex( kygComplex a, kygComplex b) //���Ҽ� a�� ���Ҽ�b�� ���ϴ� �Լ�
{
	kygComplex c;
	c.real = (a.real*b.real-a.imag*b.imag);
	c.imag = (a.real*b.imag+a.imag*b.real);
	return c;
	///kygComplex �� c�� return �޴´�
}
kygComplex multscalar( kygComplex a,double b)  ///������ b�� ���Ҽ�a�� ���ϴ� �Լ�
{
	kygComplex c;
	c.real =a.real*b;
	c.imag= a.imag*b;
	return c;
	///kygComplex �� c�� return �޴´�
}
bool resolve()
{	
	char re ='y';
	printf("\n�ٽ� �Ͻðڽ��ϱ� ( Y / N )");
	fflush(stdin);
		scanf("%c",&re);
			while(re != 'Y' && re!='y'&& re!= 'N' && re!= 'n' )//�װ����Է��� ���� �ƴϸ�
		{
			printf("\n�Է¿���!!\n�ٽ� �Է��ϼ���");
			fflush(stdin);
			scanf("%c",&re);
		}
			if(re == 'y' ||re == 'Y')
			return true;
			if(re == 'N' || re== 'n')
				return false;
}