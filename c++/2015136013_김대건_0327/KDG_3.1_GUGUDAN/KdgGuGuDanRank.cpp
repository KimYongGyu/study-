#include <cstdio>
#include <cstdlib>
#include <ctime>
static int NUMGAMEs = 0;
static int NUMWINs = 0;
extern void addranking(char* name, double spg );
extern void storeranking( char *filename );
extern void Printranking( FILE *fp = stdout);
void reset() {
}

int iNUMGAMEs(void)
{
	return NUMGAMEs;
}
int iNUMWINs(void)
{
	return NUMWINs;
}
void GUGUDANPrint(void)//구구단 출력함수
{
	int i, j, k;
	printf("\t(2단)\t\t(3단)\t\t(4단)\t\t(5단)\n");
	for(i = 1; i < 10; i++)
	{
		for(k = 2; k < 6; k++)
		{
			printf("\t%d x %d = %2d",k,i,k*i);
		}
		printf("\n");
	}
	printf("\t(6단)\t\t(7단)\t\t(8단)\t\t(9단)\n");
	for(i = 1; i < 10; i++)
	{
		for(k = 6; k < 10; k++)
		{
			printf("\t%d x %d = %2d",k,i,k*i);
		}
		printf("\n");
	}
}
void GUGUGAME(int)
{

	printf("************************************프로그램 종료**********************************\n");
	getchar();
	getchar();
}
inline int range_set(int from = 1 , int to = 9 )
{
	return (rand()%(to-from+1)+from);
}
void GUGUGAME(void)//구구단 게임을 출력하는 함수
{
	int num;
	char name[20];
	srand((unsigned int)time(NULL));//시드 초기화
	clock_t start,finish;//시간 측정을위한
	double duration;
	printf("               경기자 이름 입력:");
	scanf("%s",&name);
	printf("\t\t몇 번 테스트하시겠습니까?");
		scanf("%d",&num);
		printf("\n\n\t\t%d번 테스트하겠습니다.\n\t심호흡을 크게 한번 하시고 준비가 되시면 엔터를 누르세요\n",num);
		getchar();
		getchar();
		system("cls");//화면을 정리하는 함수
		start = clock();//시간재기 시작
		for(;num>0;num--)
		{
			int from = range_set(2,9);
			int to = range_set(1,9);
			int answer;
			printf("[문제 %d]:   %d x %d = ",NUMGAMEs+1,from,to);//게임이 시작함에 따라 랜덤으로 주어진 값을 얻어서 출력
			scanf("%d",&answer);
			if(answer == from*to)
			{
				printf("정답!!!");
				NUMWINs++;//이긴수 증가
				NUMGAMEs++;//게임수 증가
			}
			else
			{
				printf("땡!!!");
				NUMGAMEs++;//게임수만 증가
			}
			printf("(현재 정답률 : %.0lf%c)\n",100*(double)NUMWINs/NUMGAMEs,'%');
		}
		finish = clock();//시간재기 마침
		duration = (double)(finish - start)/CLOCKS_PER_SEC;//평균 시간 계산
		printf("전체%3d번 중에서 %3d번을 맞추셨습니다.\n한 문제에 평균 %.2lf초 걸리셨습니다.\n",NUMGAMEs,NUMWINs,duration/NUMGAMEs);
		if(NUMWINs/NUMGAMEs == 1 )//정답률이 100퍼센트일때
		{
			printf("전체 정답률 100%c로 랭킹에 등록됩니다\n",'%');
			addranking(name,duration/NUMGAMEs);//랭킹을 추가
			storeranking("rank.txt");//랭킹을 새로 쓴다.
		}
		printf("******************************************랭킹 출력*********************************\n\n");
		Printranking();//랭킹을 화면에 보이도록 출력
		printf("다시 ? (y/n)\n");
		
}