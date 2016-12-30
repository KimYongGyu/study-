#include "StdAfx.h"
#include "Dib.h"
#include "DibEnhancement.h"

#include <math.h>

void DibInverse(CDib& dib)
{
	register int i, j;

	int w = dib.GetWidth();
	int h = dib.GetHeight();

	BYTE** ptr = dib.GetPtr();

	for( j = 0 ; j < h ; j++ )
	for( i = 0 ; i < w ; i++ )
	{
		ptr[j][i] = 255 - ptr[j][i];
	}
}

void DibBrightness(CDib& dib, int n)
{
	register int i, j;

	int w = dib.GetWidth();
	int h = dib.GetHeight();

	BYTE** ptr = dib.GetPtr();

	for( j = 0 ; j < h ; j++ )
	for( i = 0 ; i < w ; i++ )
	{
		ptr[j][i] = limit(ptr[j][i] + n);
	}
}

void DibContrast ( CDib& dib, int n )  
{
	int w = dib.GetWidth();  // ���� ���θ� ������ ������ �����մϴ�.
	int h = dib.GetHeight();
	BYTE ** ptr = dib.GetPtr();

	for(int j = 0; j < h; j++)
	for(int i = 0; i < w; i++)
	{
		ptr[j][i] = static_cast<BYTE>(limit(ptr[j][i]+(ptr[j][i]-128)*n/100));
	}   // limit�Լ��� �̿��Ͽ� ��� ������ ������ ���� ����� �ʵ����մϴ�.
}
void DibHistogram(CDib& dib, float histo[256])
{
	register int i, j;

	int w = dib.GetWidth();
	int h = dib.GetHeight();

	BYTE** ptr = dib.GetPtr();

	// ������׷� ���

	int temp[256];
	memset(temp, 0, sizeof(int)*256);
	for( j = 0 ; j < h ; j++ )
	for( i = 0 ; i < w ; i++ )
	{
		temp[ ptr[j][i] ]++;
	}

	// ������׷� ����ȭ(histogram normalization)

	float area = (float)w*h;
	for( i = 0 ; i < 256 ; i++ )
		histo[i] = temp[i] / area;
}