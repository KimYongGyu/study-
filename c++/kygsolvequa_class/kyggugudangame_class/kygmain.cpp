#include <conio.h>
#include "kygclass.h"

void main()
{
	GuguGame gugu;
	int n;
	char name[80];

	srand((unsigned)time(NULL));//���ึ�� �ٸ� ������ ���ڹ߻�

	printf(" *** ������ ���ӿ� ���Ű��� ȯ���մϴ�!! ***\n\n");

	printf("������ �̸��� �Է��ϼ��� ===>  ");
	scanf("%s",&name);
	fflush(stdin);

	while (true){
		gugu.play(name,n);
		printf("�ٽ� �Ͻðڽ��ϱ�? (y/n)");
		if(getche() !='y' || 'Y');
		break;
	}
	printf("\n\n������ ������ �����մϴ�!!!\n\n");
}