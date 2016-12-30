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
	printf("\t\t\t\t������ ���ӿ� ���� ���� ȯ���մϴ�.!!!\n\t\t\t\t����� ������ �Ƿ��� Ȯ���� ������!!!\n");
	GUGUDANPrint();
	printf("\n");
	loadranking("rank.txt");
	printf("******************************************��ŷ ���*********************************\n\n");
	Printranking();
	while(true)//�ݺ���
	{
		GUGUGAME();
		storeranking("rank.txt");
		fflush(stdin);
		scanf("%c",&kdg_s);
		if( kdg_s == 'N' || kdg_s == 'n')//N,n�� �Է¹����� �ݺ��� ����
			break;
		while(kdg_s != 'Y' && kdg_s!='y'&& kdg_s!= 'N' && kdg_s!= 'n' )//�װ����Է��� ���� �ƴϸ�
		{
			printf("�ٽ� �Է��ϼ���");
			fflush(stdin);
			scanf("%c",&kdg_s);
		}
		if( kdg_s == 'N' || kdg_s == 'n')//N,n�� �Է¹����� �ݺ��� ����
			break;
		iNUMGAMEs();
		iNUMWINs();
		system("cls");//ȭ���� ����

	}
	GUGUGAME(1);
	return 0;
}