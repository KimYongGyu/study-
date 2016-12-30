#include <conio.h>
#include "kygclass.h"

void main()
{
	GuguGame gugu;
	int n;
	char name[80];

	srand((unsigned)time(NULL));//실행마다 다른 무작위 숫자발생

	printf(" *** 구구단 게임에 오신것을 환영합니다!! ***\n\n");

	printf("선수의 이름을 입력하세요 ===>  ");
	scanf("%s",&name);
	fflush(stdin);

	while (true){
		gugu.play(name,n);
		printf("다시 하시겠습니까? (y/n)");
		if(getche() !='y' || 'Y');
		break;
	}
	printf("\n\n구구단 게임을 종료합니다!!!\n\n");
}