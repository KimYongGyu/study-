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
	int w = dib.GetWidth(); 



	int h = dib.GetHeight();
	BYTE ** ptr = dib.GetPtr();

	for(int j = 0; j < h; j++)



	for(int i = 0; i < w; i++)
	{


		//제한 설정
		ptr[j][i] = static_cast<BYTE>(limit(ptr[j][i]+(ptr[j][i]-128)*n/100));
	}  

}
