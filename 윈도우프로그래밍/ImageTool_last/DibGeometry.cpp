#include "StdAfx.h"
#include "Dib.h"
#include "DibGeometry.h"

#include <math.h>

const double PI = acos(-1.0);

void DibTranslate(CDib& dib, int sx, int sy)
{
	CDib cpy = dib;

	register int i, j;

	int w = cpy.GetWidth();
	int h = cpy.GetHeight();

	dib.CreateGrayImage(w, h, 0);

	BYTE** ptr1 = cpy.GetPtr();
	BYTE** ptr2 = dib.GetPtr();

	int x, y;

	for( j = 0 ; j < h ; j++ )
	for( i = 0 ; i < w ; i++ )
	{
		x = i - sx;
		y = j - sy;
		if( x >= 0 && x < w && y >= 0 && y < h )
			ptr2[j][i] = ptr1[y][x];
	}
}