#include "RandomItemWalk.h"
 
void main()
{
	int r,c, maxwalk;
 
	srand( (unsigned int) time(NULL) );
 
	printf(" < ������ �������� ���� >\n\n");
	printf(" �迭�� ũ�⸦ �Է��ϼ��� : ");
	scanf("%d%d", &r,&c);
	printf(" �ִ� ������ Ƚ���� �Է��ϼ��� : ");
	scanf("%d", &maxwalk);
 
	RandomWalk game(r,c);
	game.play(maxwalk);

	RandomItemWalk game1(r,c);
	game1.play(maxwalk, 50);
}