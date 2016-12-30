#include "RandomItemWalk.h"
 
void main()
{
	int r,c, maxwalk;
 
	srand( (unsigned int) time(NULL) );
 
	printf(" < 술취한 딱정벌레 문제 >\n\n");
	printf(" 배열의 크기를 입력하세요 : ");
	scanf("%d%d", &r,&c);
	printf(" 최대 움직임 횟수를 입력하세요 : ");
	scanf("%d", &maxwalk);
 
	RandomWalk game(r,c);
	game.play(maxwalk);

	RandomItemWalk game1(r,c);
	game1.play(maxwalk, 50);
}