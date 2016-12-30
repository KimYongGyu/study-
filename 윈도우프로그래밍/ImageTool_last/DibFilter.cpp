#include "StdAfx.h"
#include "Dib.h"
#include "DibFilter.h"

#include <math.h>

const double PI = acos(-1.0);

void DibFilterMean(CDib& dib)
{
	register int i, j;

	int w = dib.GetWidth();
	int h = dib.GetHeight();

	CDib cpy = dib;

	BYTE** ptr1 = dib.GetPtr();
	BYTE** ptr2 = cpy.GetPtr();

	int temp;
	for( j = 1 ; j < h-1 ; j++ )
	for( i = 1 ; i < w-1 ; i++ )
	{
		temp = ptr2[j-1][i-1] + ptr2[j-1][i] + ptr2[j-1][i+1]
			+ ptr2[j][i-1] + ptr2[j][i] + ptr2[j][i+1]
			+ ptr2[j+1][i-1] + ptr2[j+1][i] + ptr2[j+1][i+1];

		ptr1[j][i] = (BYTE)limit(temp/9. + 0.5);
	}
}

void DibFilterWeightedMean(CDib& dib)
{
	register int i, j;

	int w = dib.GetWidth();
	int h = dib.GetHeight();

	CDib cpy = dib;

	BYTE** ptr1 = dib.GetPtr();
	BYTE** ptr2 = cpy.GetPtr();

	int temp;
	for( j = 1 ; j < h-1 ; j++ )
	for( i = 1 ; i < w-1 ; i++ )
	{
		temp = ptr2[j-1][i-1] + 2*ptr2[j-1][i] + ptr2[j-1][i+1]
			+ 2*ptr2[j][i-1] + 4*ptr2[j][i] + 2*ptr2[j][i+1]
			+ ptr2[j+1][i-1] + 2*ptr2[j+1][i] + ptr2[j+1][i+1];

		ptr1[j][i] = (BYTE)limit(temp/16. + 0.5);
	}
}

void DibFilterGaussian(CDib& dib, double sigma)
{
	register int i, j, k, x;

	int w = dib.GetWidth();;
	int h = dib.GetHeight();

	BYTE** ptr = dib.GetPtr();

	//-------------------------------------------------------------------------
	// 1차원 가우시안 마스크 생성
	//-------------------------------------------------------------------------

	int dim = (int)max(3.0, 2*4*sigma + 1.0);
	if( dim % 2 == 0 ) dim++; // 1차원 가우시안 마스크를 홀수개로 만든다.
	int dim2 = (int)dim/2;

	double* pMask = new double[dim];
	for( i = 0 ; i < dim ; i++ )
	{
		x = i - dim2;
		pMask[i] = exp(-(x*x)/(2*sigma*sigma)) / (sqrt(2*PI)*sigma);
	}

	//-------------------------------------------------------------------------
	// 임시 버퍼 메모리 공간 할당
	//-------------------------------------------------------------------------

	double** buf = new double*[h];
	for( i = 0 ; i < h ; i++ )
	{
		buf[i] = new double[w];
		memset(buf[i], 0, sizeof(double)*w);
	}

	//-------------------------------------------------------------------------
	// 세로 방향 마스크 연산
	//-------------------------------------------------------------------------

	double sum1, sum2;

	for( i = 0 ; i < w ; i++ )
	for( j = 0 ; j < h ; j++ )
	{
		sum1 = sum2 = 0.0;

		for( k = 0 ; k < dim ; k++ )
		{
			x = k - dim2 + j;

			if( x >= 0 && x < h )
			{
				sum1 += pMask[k];
				sum2 += (pMask[k] * ptr[x][i]);
			}
		}

		buf[j][i] = (sum2/sum1);
	}

	//-------------------------------------------------------------------------
	// 가로 방향 마스크 연산
	//-------------------------------------------------------------------------

	for( j = 0 ; j < h ; j++ )
	for( i = 0 ; i < w ; i++ )
	{
		sum1 = sum2 = 0.0;

		for( k = 0 ; k < dim ; k++ )
		{
			x = k - dim2 + i;

			if( x >= 0 && x < w )
			{
				sum1 += pMask[k];
				sum2 += (pMask[k] * buf[j][x]);
			}
		}

		ptr[j][i] = (BYTE)limit(sum2/sum1);
	}

	//-------------------------------------------------------------------------
	// 동적 할당했던 메모리 공간 해제
	//-------------------------------------------------------------------------

	delete [] pMask;

	for( i = 0 ; i < h ; i++ )
		delete [] buf[i];
	delete [] buf;
}

void DibFilterLaplacian(CDib& dib)
{
	register int i, j;

	int w = dib.GetWidth();
	int h = dib.GetHeight();

	CDib cpy = dib;
	dib.CreateGrayImage(w, h, 0);

	BYTE** ptr1 = dib.GetPtr();
	BYTE** ptr2 = cpy.GetPtr();

	int temp;
	for( j = 1 ; j < h-1 ; j++ )
	for( i = 1 ; i < w-1 ; i++ )
	{
		temp = 4*ptr2[j][i] - ptr2[j-1][i] - ptr2[j][i+1] - ptr2[j+1][i] - ptr2[j][i-1];

		ptr1[j][i] = (BYTE)limit(temp);
	}
}

void DibFilterUnsharpMask(CDib& dib)
{
	register int i, j;

	int w = dib.GetWidth();
	int h = dib.GetHeight();

	CDib cpy = dib;

	BYTE** ptr1 = dib.GetPtr();
	BYTE** ptr2 = cpy.GetPtr();

	for( j = 1 ; j < h-1 ; j++ )
	for( i = 1 ; i < w-1 ; i++ )
	{
		ptr1[j][i] = (BYTE)limit(5*ptr2[j][i] - ptr2[j-1][i] - ptr2[j][i-1] - ptr2[j+1][i] - ptr2[j][i+1]);
	}
}

void DibNoiseGaussian(CDib& dib, int amount)
{
	register int i, j;

	int w = dib.GetWidth();
	int h = dib.GetHeight();

	BYTE** ptr = dib.GetPtr();

	srand( (unsigned)time(NULL) );

	double rnd;
	for( j = 0 ; j < h ; j++ )
	for( i = 0 ; i < w ; i+=2 )
	{
		rnd = GaussianRand(0, amount);

		ptr[j][i] = (BYTE)limit(ptr[j][i] + rnd);
	}
}

// Polar form of the Box-Muller transformation.
// 평균이 mean이고, 표준편차가 std인 가우시안 랜덤 숫자를 생성한다.
double GaussianRand(double mean, double std)
{
	double x1, x2, radius, factor, y1;
	static double y2;
	static int use_last = 0;

	if( use_last )
	{
		y1 = y2;
		use_last = 0;
	}
	else
	{
		do {
			x1 = 2.0 * rand() / RAND_MAX - 1.0;
			x2 = 2.0 * rand() / RAND_MAX - 1.0;
			radius = x1 * x1 + x2 * x2;
		} while ( radius < 0.00000001 || radius >= 1.0 );

		factor = sqrt( (-2.0 * log(radius)) / radius );

		y1 = x1 * factor;
		y2 = x2 * factor;

		use_last = 1;
	}

	return (mean + y1*std);
}

void DibNoiseSaltNPepper(CDib& dib, int amount)
{
	register int i, j;

	int w = dib.GetWidth();
	int h = dib.GetHeight();

	BYTE** ptr = dib.GetPtr();

	srand( (unsigned)time(NULL) );

	int rnd;
	for( j = 0 ; j < h ; j++ )
	for( i = 0 ; i < w ; i++ )
	{
		rnd = (int)(rand() * 100 / RAND_MAX);

		if( rnd < amount/2 )
			ptr[j][i] = 0;
		else if( rnd < amount )
			ptr[j][i] = 255;
	}
}

void DibFilterMedean(CDib& dib)
{
	register int i, j;

	int w = dib.GetWidth();
	int h = dib.GetHeight();

	CDib cpy = dib;

	BYTE** ptr1 = dib.GetPtr();
	BYTE** ptr2 = cpy.GetPtr();

	int m[9];
	for( j = 1 ; j < h-1 ; j++ )
	for( i = 1 ; i < w-1 ; i++ )
	{
		m[0] = ptr2[j-1][i-1]; m[1] = ptr2[j-1][i]; m[2] = ptr2[j-1][i+1];	
		m[3] = ptr2[j  ][i-1]; m[4] = ptr2[j  ][i]; m[5] = ptr2[j  ][i+1];
		m[6] = ptr2[j+1][i-1]; m[7] = ptr2[j+1][i]; m[8] = ptr2[j+1][i+1];

		// Insertion sort
		InsertSort(m, 9);

		ptr1[j][i] = (BYTE)m[4];
	}
}

void InsertSort(int* d, int n)
{
	register int i, j;
	int temp;

	for( i = 1 ; i < n ; i++ )
	{
		temp = d[i];
		j = i - 1;

		while( j > -1 && d[j] > temp )
		{
			d[j+1] = d[j];
			j--;
		}

		d[j+1] = temp;
	}
}

void DibFilterDiffusion(CDib& dib, float lambda, float k, int iter) 
{
	register int i, x, y;

	int w  = dib.GetWidth();
	int h  = dib.GetHeight();

	BYTE** ptr = dib.GetPtr();

	float k2 = k * k;

	float gradn, grads, grade, gradw;
	float gcn, gcs, gce, gcw;
	float tmp;

	// 연산을 실수형으로 하기 위하여 실수형 2차원 배열 동적 생성
	float** cpy = new float*[h];
	for( i = 0 ; i < h ; i++ )
	{
		cpy[i] = new float[w];
		memset(cpy[i], 0, sizeof(float)*w);
	}

	float** buf = new float*[h];
	for( i = 0 ; i < h ; i++ )
	{
		buf[i] = new float[w];
		memset(buf[i], 0, sizeof(float)*w);
	}

	// 입력 영상의 정보를 복사
	for( y = 0 ; y < h ; y++ )
	for( x = 0 ; x < w ; x++ )
	{
		cpy[y][x] = buf[y][x] = (float)ptr[y][x];
	}

	for( i = 0 ; i < iter ; i++ )
	{
		for( y = 1 ; y < h-1 ; y++ )
		for( x = 1 ; x < w-1 ; x++ )
		{
			tmp = cpy[y][x];

			gradn = cpy[y-1][x  ] - tmp;
			grads = cpy[y+1][x  ] - tmp;
			grade = cpy[y  ][x-1] - tmp;
			gradw = cpy[y  ][x+1] - tmp;

			gcn = gradn / (1.0f + gradn*gradn/k2);
			gcs = grads / (1.0f + grads*grads/k2);
			gce = grade / (1.0f + grade*grade/k2);
			gcw = gradw / (1.0f + gradw*gradw/k2);

			buf[y][x] = cpy[y][x] + lambda*(gcn + gcs + gce + gcw);
		}

		// 버퍼 복사
		for( y = 0 ; y < h ; y++ )
			memcpy(cpy[y], buf[y], sizeof(float)*w);
	}

	// 입력 영상의 값 갱신
	for( y = 0 ; y < h ; y++ )
	for( x = 0 ; x < w ; x++ )
	{
		ptr[y][x] = (BYTE)limit(buf[y][x] + 0.5f);
	}

	// 동적 할당한 메모리 해제
	for( i = 0 ; i < h ; i++ )
	{
		delete [] buf[i];
		delete [] cpy[i];
	}

	delete [] buf;
	delete [] cpy;
}

void DibEdgeRoberts(CDib& dib)
{
	register int i, j;

	int w = dib.GetWidth();
	int h = dib.GetHeight();

	CDib cpy = dib;
	dib.CreateGrayImage(w, h, 0);

	BYTE** ptr1 = dib.GetPtr();
	BYTE** ptr2 = cpy.GetPtr();

	int h1, h2;
	double hval;
	for( j = 1 ; j < h-1 ; j++ )
	for( i = 1 ; i < w-1 ; i++ )
	{
		h1 = ptr2[j][i] - ptr2[j-1][i-1];
		h2 = ptr2[j][i] - ptr2[j-1][i+1];

		hval = sqrt( (double)h1*h1 + h2*h2 );

		ptr1[j][i] = (BYTE)limit(hval);
	}
}

void DibEdgePrewitt(CDib& dib)
{
	register int i, j;

	int w = dib.GetWidth();
	int h = dib.GetHeight();

	CDib cpy = dib;
	dib.CreateGrayImage(w, h, 0);

	BYTE** ptr1 = dib.GetPtr();
	BYTE** ptr2 = cpy.GetPtr();

	int h1, h2;
	double hval;
	for( j = 1 ; j < h-1 ; j++ )
	for( i = 1 ; i < w-1 ; i++ )
	{
		h1 = - ptr2[j-1][i-1] - ptr2[j-1][i] - ptr2[j-1][i+1]
			 + ptr2[j+1][i-1] + ptr2[j+1][i] + ptr2[j+1][i+1];

		h2 = - ptr2[j-1][i-1] - ptr2[j][i-1] - ptr2[j+1][i-1]
			 + ptr2[j-1][i+1] + ptr2[j][i+1] + ptr2[j+1][i+1];

		hval = sqrt( (double)h1*h1 + h2*h2 );

		ptr1[j][i] = (BYTE)limit(hval);
	}
}

void DibEdgeSobel(CDib& dib)
{
	register int i, j;

	int w = dib.GetWidth();
	int h = dib.GetHeight();

	CDib cpy = dib;
	dib.CreateGrayImage(w, h, 0);

	BYTE** ptr1 = dib.GetPtr();
	BYTE** ptr2 = cpy.GetPtr();

	int h1, h2;
	double hval;
	for( j = 1 ; j < h-1 ; j++ )
	for( i = 1 ; i < w-1 ; i++ )
	{
		h1 = - ptr2[j-1][i-1] - 2*ptr2[j-1][i] - ptr2[j-1][i+1]
			 + ptr2[j+1][i-1] + 2*ptr2[j+1][i] + ptr2[j+1][i+1];

		h2 = - ptr2[j-1][i-1] - 2*ptr2[j][i-1] - ptr2[j+1][i-1]
			 + ptr2[j-1][i+1] + 2*ptr2[j][i+1] + ptr2[j+1][i+1];
		
		hval = sqrt( (double)h1*h1 + h2*h2 );

		ptr1[j][i] = (BYTE)limit(hval);
	}
}