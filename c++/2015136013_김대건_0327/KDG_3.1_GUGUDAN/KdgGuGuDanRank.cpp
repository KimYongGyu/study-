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
void GUGUDANPrint(void)//������ ����Լ�
{
	int i, j, k;
	printf("\t(2��)\t\t(3��)\t\t(4��)\t\t(5��)\n");
	for(i = 1; i < 10; i++)
	{
		for(k = 2; k < 6; k++)
		{
			printf("\t%d x %d = %2d",k,i,k*i);
		}
		printf("\n");
	}
	printf("\t(6��)\t\t(7��)\t\t(8��)\t\t(9��)\n");
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

	printf("************************************���α׷� ����**********************************\n");
	getchar();
	getchar();
}
inline int range_set(int from = 1 , int to = 9 )
{
	return (rand()%(to-from+1)+from);
}
void GUGUGAME(void)//������ ������ ����ϴ� �Լ�
{
	int num;
	char name[20];
	srand((unsigned int)time(NULL));//�õ� �ʱ�ȭ
	clock_t start,finish;//�ð� ����������
	double duration;
	printf("               ����� �̸� �Է�:");
	scanf("%s",&name);
	printf("\t\t�� �� �׽�Ʈ�Ͻðڽ��ϱ�?");
		scanf("%d",&num);
		printf("\n\n\t\t%d�� �׽�Ʈ�ϰڽ��ϴ�.\n\t��ȣ���� ũ�� �ѹ� �Ͻð� �غ� �ǽø� ���͸� ��������\n",num);
		getchar();
		getchar();
		system("cls");//ȭ���� �����ϴ� �Լ�
		start = clock();//�ð���� ����
		for(;num>0;num--)
		{
			int from = range_set(2,9);
			int to = range_set(1,9);
			int answer;
			printf("[���� %d]:   %d x %d = ",NUMGAMEs+1,from,to);//������ �����Կ� ���� �������� �־��� ���� �� ���
			scanf("%d",&answer);
			if(answer == from*to)
			{
				printf("����!!!");
				NUMWINs++;//�̱�� ����
				NUMGAMEs++;//���Ӽ� ����
			}
			else
			{
				printf("��!!!");
				NUMGAMEs++;//���Ӽ��� ����
			}
			printf("(���� ����� : %.0lf%c)\n",100*(double)NUMWINs/NUMGAMEs,'%');
		}
		finish = clock();//�ð���� ��ħ
		duration = (double)(finish - start)/CLOCKS_PER_SEC;//��� �ð� ���
		printf("��ü%3d�� �߿��� %3d���� ���߼̽��ϴ�.\n�� ������ ��� %.2lf�� �ɸ��̽��ϴ�.\n",NUMGAMEs,NUMWINs,duration/NUMGAMEs);
		if(NUMWINs/NUMGAMEs == 1 )//������� 100�ۼ�Ʈ�϶�
		{
			printf("��ü ����� 100%c�� ��ŷ�� ��ϵ˴ϴ�\n",'%');
			addranking(name,duration/NUMGAMEs);//��ŷ�� �߰�
			storeranking("rank.txt");//��ŷ�� ���� ����.
		}
		printf("******************************************��ŷ ���*********************************\n\n");
		Printranking();//��ŷ�� ȭ�鿡 ���̵��� ���
		printf("�ٽ� ? (y/n)\n");
		
}