#include "kygBugWorld.h"

void main()
{
	int r,c, maxwalk;

	srand((unsigned int) time(NULL));

	printf("\n\t< �������� ���� > \n\n");
	printf("\t���� ������ ũ�⸦ �Է��ϼ��� : ");
	scanf("%d%d", &r,&c);

	printf("\t�ִ� ������ Ƚ���� �Է��ϼ��� : ");
	scanf("%d", &maxwalk);

	kygBugWorld game(r,c);
	game.Play(maxwalk, 50);
	
	getchar();
}