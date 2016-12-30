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
	int pos=0;//텍스트에 등록된 플레이어의 숫자
	for( pos ; pos<nTopPlayer ; pos++)
		if( spg < list[pos].getscore() )//순위 계산
			break;
	if( pos >= NumTopPlayer )//랭킹을 등록해야 하는 숫자보다 크면 함수를 끝냄
		return;
	if(nTopPlayer < NumTopPlayer )//랭킹에 등록시키고 등록된 숫자 갱신
		nTopPlayer++;
	for( int i=nTopPlayer-1 ; i > pos ; i--) {
		list[i] = list[i-1];
	}
	list[pos].set(name,spg);//랭킹을 등록
}
void Printranking( FILE *fp)
{
	for( int i =0; i<nTopPlayer ; i++){
		fprintf(fp, "%2d:\t", i+1);
		list[i].print(fp);
	}
}
