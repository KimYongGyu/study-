#include <conio.h>
#include "kygGuguGame.h"

void main(){

	GuguGame gugu ;
	int n ;
	char name[80];

	srand((unsigned)time(NULL));

	printf("*** ������ ���ӿ� ���Ű��� ȯ���մϴ�!!! ***\n\n");

	printf("������ �̸��� �Է��ϼ��� ======> ");
	scanf("%s", name);
	fflush(stdin);
	printf("��� �׽�Ʈ �Ͻðڽ��ϱ�? :   ");
	scanf("%d",&n);
	fflush(stdin);

	while (true) {
		gugu.play( name, n);

		printf("�ٽ� �Ͻðڽ��ϱ�? (y/n) ");
		if( getche() != 'y'&&'Y')
			break;
	}
	printf("\n\n������ ������ �����մϴ�!!!\n\n");
}
