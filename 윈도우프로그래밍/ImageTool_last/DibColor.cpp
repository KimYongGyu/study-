#include "StdAfx.h"
#include "Dib.h"
#include "RGBBYTE.h"
#include "DibColor.h"
#include "DibEnhancement.h"
#include "DibFilter.h"

#include <math.h>

const double PI = acos(-1.0);

#define RGB2GRAY(r, g, b) (0.299*(r) + 0.587*(g) + 0.114*(b))

void DibGrayscale(CDib& dib)
{
	register int i, j;

	int w = dib.GetWidth();
	int h = dib.GetHeight();

	CDib cpy = dib;
	dib.CreateGrayImage(w, h);

	BYTE** ptr1 = dib.GetPtr();
	RGBBYTE** ptr2 = cpy.GetRGBPtr();

	BYTE r, g, b;
	for( j = 0 ; j < h ; j++ )
	for( i = 0 ; i < w ; i++ )
	{
		r = ptr2[j][i].r;
		g = ptr2[j][i].g;
		b = ptr2[j][i].b;

		ptr1[j][i] = (BYTE)limit(RGB2GRAY(r, g, b));
	}
}

//-------------------------------------------------------------------------
// R, G, B, H, S, I 의 범위는 [0, 1]
//-------------------------------------------------------------------------
void RGB_TO_HSI(double R, double G, double B, double& H, double& S, double& I)
{
	I = (R + G + B) / 3;

	if( (R == G) && (G == B) ) // 그레이스케일인 경우
	{
		S = 0;
		H = 0;
	}
	else
	{
		double min_rgb;
		double temp;

		min_rgb = min(min(R, G), B);

		S = 1 - (min_rgb / I);
		temp = ((R-G) + (R-B)) / (2 * sqrt( (R-G)*(R-G) + (R-B)*(G-B) ));
		
		H = acos(temp) * 180 / PI;
		
		if( B > G ) 
			H = 360 - H;

		H /= 360;
	}
}

//-------------------------------------------------------------------------
// R, G, B, H, S, I 의 범위는 [0, 1]
//-------------------------------------------------------------------------
void HSI_TO_RGB(double H, double S, double I, double& R, double& G, double& B)
{
	if( I == 0.0 ) // 검정색
	{
		R = 0.0;
		G = 0.0;
		B = 0.0;
		return;
	}

	if( S == 0.0 ) // 그레이스케일
	{
		R = I;
		G = I;
		B = I;
		return;
	}

	H *= 360;   // [0, 1] 범위를 [0, 360] 각도 범위로 변경

	if( H <= 120 )
	{
		B = I*(1 - S);
		R = I*(1 + S*cos(H*PI/180)/cos((60-H)*PI/180));
		R = limit(R, 0., 1.);
		G = 3*I - (R + B);
	}
	else if( H <= 240 )
	{
		H -= 120;

		R = I*(1 - S);
		G = I*(1 + S*cos(H*PI/180)/cos((60-H)*PI/180));
		G = limit(G, 0., 1.);
		B = 3*I - (R + G);
	}
	else
	{
		H -= 240;

		G = I*(1 - S);
		B = I*(1 + S*cos(H*PI/180)/cos((60-H)*PI/180));
		B = limit(B, 0., 1.);
		R = 3*I - (G + B);
	}
}

//-------------------------------------------------------------------------
// R, G, B, Y, U, V 의 범위는 [0, 255]
//-------------------------------------------------------------------------
void RGB_TO_YUV(BYTE R, BYTE G, BYTE B, BYTE& Y, BYTE& U, BYTE& V)
{
	Y = (BYTE)limit( 0.299*R + 0.587*G + 0.114*B       + 0.5);
	U = (BYTE)limit(-0.169*R - 0.331*G + 0.500*B + 128 + 0.5);
	V = (BYTE)limit( 0.500*R - 0.419*G - 0.081*B + 128 + 0.5);
}

//-------------------------------------------------------------------------
// R, G, B, Y, U, V 의 범위는 [0, 255]
//-------------------------------------------------------------------------
void YUV_TO_RGB(BYTE Y, BYTE U, BYTE V, BYTE& R, BYTE& G, BYTE& B)
{
	R = (BYTE)limit(Y                    + 1.4075*(V - 128) + 0.5);
	G = (BYTE)limit(Y - 0.3455*(U - 128) - 0.7169*(V - 128) + 0.5);
	B = (BYTE)limit(Y + 1.7790*(U - 128)                    + 0.5);
}

void DibColorSplitRGB(CDib& dib, CDib& dibR, CDib& dibG, CDib& dibB)
{
	register int i, j;

	int w = dib.GetWidth();
	int h = dib.GetHeight();

	dibR.CreateGrayImage(w, h);
	dibG.CreateGrayImage(w, h);
	dibB.CreateGrayImage(w, h);

	RGBBYTE** ptr = dib.GetRGBPtr();
	BYTE** ptrR = dibR.GetPtr();
	BYTE** ptrG = dibG.GetPtr();
	BYTE** ptrB = dibB.GetPtr();

	for( j = 0 ; j < h ; j++ )
	for( i = 0 ; i < w ; i++ )
	{
		ptrR[j][i] = ptr[j][i].r;
		ptrG[j][i] = ptr[j][i].g;
		ptrB[j][i] = ptr[j][i].b;
	}
}

void DibColorSplitHSI(CDib& dib, CDib& dibH, CDib& dibS, CDib& dibI)
{
	register int i, j;

	int w = dib.GetWidth();
	int h = dib.GetHeight();

	dibH.CreateGrayImage(w, h);
	dibS.CreateGrayImage(w, h);
	dibI.CreateGrayImage(w, h);

	RGBBYTE** ptr = dib.GetRGBPtr();
	BYTE** ptrH = dibH.GetPtr();
	BYTE** ptrS = dibS.GetPtr();
	BYTE** ptrI = dibI.GetPtr();

	double r, g, b, hh, ss, ii;
	for( j = 0 ; j < h ; j++ )
	for( i = 0 ; i < w ; i++ )
	{
		r = (double)ptr[j][i].r / 255;
		g = (double)ptr[j][i].g / 255;
		b = (double)ptr[j][i].b / 255;

		RGB_TO_HSI(r, g, b, hh, ss, ii);

		ptrH[j][i] = (BYTE)limit(hh*255 + 0.5);
		ptrS[j][i] = (BYTE)limit(ss*255 + 0.5);
		ptrI[j][i] = (BYTE)limit(ii*255 + 0.5);
	}
}

void DibColorSplitYUV(CDib& dib, CDib& dibY, CDib& dibU, CDib& dibV)
{
	register int i, j;

	int w = dib.GetWidth();
	int h = dib.GetHeight();

	dibY.CreateGrayImage(w, h);
	dibU.CreateGrayImage(w, h);
	dibV.CreateGrayImage(w, h);

	RGBBYTE** ptr = dib.GetRGBPtr();
	BYTE** ptrY  = dibY.GetPtr();
	BYTE** ptrU = dibU.GetPtr();
	BYTE** ptrV = dibV.GetPtr();

	BYTE y, u, v;
	for( j = 0 ; j < h ; j++ )
	for( i = 0 ; i < w ; i++ )
	{
		RGB_TO_YUV(ptr[j][i].r, ptr[j][i].g, ptr[j][i].b, y, u, v);

		ptrY[j][i] = y;
		ptrU[j][i] = u;
		ptrV[j][i] = v;
	}
}

BOOL DibColorCombineRGB(CDib& dibR, CDib& dibG, CDib& dibB, CDib& dib)
{
	register int i, j;

	int w = dibR.GetWidth();
	int h = dibR.GetHeight();

	if( dibG.GetWidth() != w || dibG.GetHeight() != h ||
		dibB.GetWidth() != w || dibB.GetHeight() != h )
		return FALSE;

	dib.CreateRGBImage(w, h);

	BYTE** ptrR = dibR.GetPtr();
	BYTE** ptrG = dibG.GetPtr();
	BYTE** ptrB = dibB.GetPtr();
	RGBBYTE** ptr = dib.GetRGBPtr();

	for( j = 0 ; j < h ; j++ )
	for( i = 0 ; i < w ; i++ )
	{
		ptr[j][i].r = ptrR[j][i];
		ptr[j][i].g = ptrG[j][i];
		ptr[j][i].b = ptrB[j][i];
	}

	return TRUE;
}

BOOL DibColorCombineHSI(CDib& dibH, CDib& dibS, CDib& dibI, CDib& dib)
{
	register int i, j;

	int w = dibH.GetWidth();
	int h = dibH.GetHeight();

	if( dibS.GetWidth() != w || dibS.GetHeight() != h ||
		dibI.GetWidth() != w || dibI.GetHeight() != h )
		return FALSE;

	dib.CreateRGBImage(w, h);

	BYTE** ptrH = dibH.GetPtr();
	BYTE** ptrS = dibS.GetPtr();
	BYTE** ptrI = dibI.GetPtr();
	RGBBYTE** ptr = dib.GetRGBPtr();

	double r, g, b, hh, ss, ii;
	for( j = 0 ; j < h ; j++ )
	for( i = 0 ; i < w ; i++ )
	{
		hh = (double)ptrH[j][i] / 255;
		ss = (double)ptrS[j][i] / 255;
		ii = (double)ptrI[j][i] / 255;

		HSI_TO_RGB(hh, ss, ii, r, g, b);

		ptr[j][i].r = (BYTE)limit(r*255 + 0.5);
		ptr[j][i].g = (BYTE)limit(g*255 + 0.5);
		ptr[j][i].b = (BYTE)limit(b*255 + 0.5);
	}

	return TRUE;
}

BOOL DibColorCombineYUV(CDib& dibY, CDib& dibU, CDib& dibV, CDib& dib)
{
	register int i, j;

	int w = dibY.GetWidth();
	int h = dibY.GetHeight();

	if( dibU.GetWidth() != w || dibU.GetHeight() != h ||
		dibV.GetWidth() != w || dibV.GetHeight() != h )
		return FALSE;

	dib.CreateRGBImage(w, h);

	BYTE** ptrY = dibY.GetPtr();
	BYTE** ptrU = dibU.GetPtr();
	BYTE** ptrV = dibV.GetPtr();
	RGBBYTE** ptr = dib.GetRGBPtr();

	BYTE r, g, b;
	for( j = 0 ; j < h ; j++ )
	for( i = 0 ; i < w ; i++ )
	{
		YUV_TO_RGB(ptrY[j][i], ptrU[j][i], ptrV[j][i], r, g, b);

		ptr[j][i].r = r;
		ptr[j][i].g = g;
		ptr[j][i].b = b;
	}

	return TRUE;
}

void DibColorEdge(CDib& dib)
{
	CDib dibY, dibU, dibV;
	DibColorSplitYUV(dib, dibY, dibU, dibV);

	DibEdgePrewitt(dibY);
	DibEdgePrewitt(dibU);
	DibEdgePrewitt(dibV);

	register int i, j;

	int w = dib.GetWidth();
	int h = dib.GetHeight();

	dib.CreateGrayImage(w, h);
	BYTE** ptr = dib.GetPtr();

	BYTE** ptrY = dibY.GetPtr();
	BYTE** ptrU = dibU.GetPtr();
	BYTE** ptrV = dibV.GetPtr();

	for( j = 0 ; j < h ; j++ )
	for( i = 0 ; i < w ; i++ )
	{
		ptr[j][i] = (BYTE)limit(CalcDist(ptrY[j][i], ptrU[j][i]*0.5, ptrV[j][i]*0.5));
	}
}

double CalcDist(double x, double y, double z)
{
	return sqrt( x*x + y*y + z*z );
}

void DibColorHistEqual(CDib& dib)
{
	CDib dibY, dibU, dibV;
	DibColorSplitYUV(dib, dibY, dibU, dibV);

	DibHistEqual(dibY);

	DibColorCombineYUV(dibY, dibU, dibV, dib);
}

