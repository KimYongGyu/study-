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
	int w = dib.GetWidth();  // ���� ���θ� ������ ������ ����
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

	// ������׷� ����ȭ

	float area = (float)w*h;
	for( i = 0 ; i < 256 ; i++ )
		histo[i] = temp[i] / area;
}
void DibHistEqual(CDib& dib) {
	int w = dib.GetWidth();
	int h = dib.GetHeight();
	BYTE** ptr = dib.GetPtr();
	float histo[256];
	DibHistogram(dib, histo);

	float cdf[256] = {0.0, };
	cdf[0] = histo[0];
	for(int i = 1; i < 256; i++)
		cdf[i] = cdf[i-1] + histo[i];

	for(int j = 1; j < h; j++)
	for(int i = 1; i < w; i++) {
		ptr[j][i] = static_cast<BYTE>(limit(cdf[ptr[j][i]] * 255));
	}
}