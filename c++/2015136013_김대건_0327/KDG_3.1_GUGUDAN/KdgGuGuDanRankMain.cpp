#include <cstdio>
#include <ctime>
#include <stdlib.h>
extern void Printranking( FILE *fp = stdout );
extern void loadranking( char *filename );
extern void storeranking( char *filename );
extern void addranking(char* name, double spg );
extern void Printranking( FILE *fp);
extern int iNUMGAMEs(void);
extern int iNUMWINs(void);
extern void GUGUDANPrint(void);
extern void GUGUDANPrint(int);
extern inline int range_set(int from, int to);
extern void GUGUGAME(void);
extern void GUGUGAME(int);

int main()
{
	char name[20];
	char kdg_s = 'Y';
	printf("\t\t\t\t구구단 게임에 오신 것을 환영합니다.!!!\n\t\t\t\t당신의 구구단 실력을 확인해 보세요!!!\n");
	GUGUDANPrint();
	printf("\n");
	loadranking("rank.txt");
	printf("******************************************랭킹 출력*********************************\n\n");
	Printranking();
	while(true)//반복문
	{
		GUGUGAME();
		storeranking("rank.txt");
		fflush(stdin);
		scanf("%c",&kdg_s);
		if( kdg_s == 'N' || kdg_s == 'n')//N,n을 입력받으면 반복을 종료
			break;
		while(kdg_s != 'Y' && kdg_s!='y'&& kdg_s!= 'N' && kdg_s!= 'n' )//네가지입력이 전부 아니면
		{
			printf("다시 입력하세요");
			fflush(stdin);
			scanf("%c",&kdg_s);
		}
		if( kdg_s == 'N' || kdg_s == 'n')//N,n을 입력받으면 반복을 종료
			break;
		iNUMGAMEs();
		iNUMWINs();
		system("cls");//화면을 정리

	}
	GUGUGAME(1);
	return 0;
}