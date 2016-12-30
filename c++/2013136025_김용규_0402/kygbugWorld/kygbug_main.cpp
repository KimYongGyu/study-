#include "kygBugWorld.h"

void main()
{
	int r,c, maxwalk;

	srand((unsigned int) time(NULL));

	printf("\n\t< 벌레들의 세상 > \n\n");
	printf("\t벌레 세상의 크기를 입력하세요 : ");
	scanf("%d%d", &r,&c);

	printf("\t최대 움직임 횟수를 입력하세요 : ");
	scanf("%d", &maxwalk);

	kygBugWorld game(r,c);
	game.Play(maxwalk, 50);
	
	getchar();
}