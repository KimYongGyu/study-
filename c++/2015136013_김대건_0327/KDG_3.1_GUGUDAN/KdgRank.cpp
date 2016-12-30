#include "KdgPlayer.h"
const int NumTopPlayer = 10;

void Printranking( FILE *fp = stdout );

static player list[NumTopPlayer];
static int	nTopPlayer;

void loadranking( char *filename )
{
	nTopPlayer = 0;
	FILE *fp = fopen(filename , "r");
	if(fp == NULL ) return;
	fscanf(fp, "%d", &nTopPlayer);
	if( nTopPlayer > NumTopPlayer )
		nTopPlayer = NumTopPlayer;

	for( int i = 0 ; i <nTopPlayer ; i++ )
		list[i].read(fp);

	fclose(fp);
}
void storeranking( char *filename )
{
	FILE *fp = fopen(filename, "w");
	if(fp == NULL ) return;
	fprintf(fp, "%d\n", nTopPlayer);
	Printranking(fp);
	fclose(fp);
}
void addranking(char* name, double spg )
{
	int pos=0;//�ؽ�Ʈ�� ��ϵ� �÷��̾��� ����
	for( pos ; pos<nTopPlayer ; pos++)
		if( spg < list[pos].getscore() )//���� ���
			break;
	if( pos >= NumTopPlayer )//��ŷ�� ����ؾ� �ϴ� ���ں��� ũ�� �Լ��� ����
		return;
	if(nTopPlayer < NumTopPlayer )//��ŷ�� ��Ͻ�Ű�� ��ϵ� ���� ����
		nTopPlayer++;
	for( int i=nTopPlayer-1 ; i > pos ; i--) {
		list[i] = list[i-1];
	}
	list[pos].set(name,spg);//��ŷ�� ���
}
void Printranking( FILE *fp)
{
	for( int i =0; i<nTopPlayer ; i++){
		fprintf(fp, "%2d:\t", i+1);
		list[i].print(fp);
	}
}
