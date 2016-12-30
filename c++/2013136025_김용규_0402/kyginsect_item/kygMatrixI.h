#pragma once
#include <stdio.h>
#include <stdlib.h>
 
class kygMatrixI
{
protected:
	int rows; // 행의 개수
	int cols; // 열의 개수
	int** mat; // 행렬 데이터
//	friend class RandomWalk;
 
public:
 
	kygMatrixI(int r=0, int c=0):mat(NULL)	{ alloc(r,c);	}
 
	~kygMatrixI(void)
	{ reset();	}
 
	int get(int r, int c) {return mat[r][c];}
	void set(int r, int c, int val) {mat[r][c] = val;}
	
	void reset(){
		if(mat != NULL){
			for(int i=0; i<rows; i++)
				delete [] mat[i];
			delete [] mat;
		}
		rows = cols = 0;
		mat = NULL;
	}
 
	void alloc(int r, int c){
		reset();
		rows = r;
		cols = c;
		mat = new int* [ rows];
		for( int i=0 ;i<rows; i++)
			mat[i] = new int [cols];
	}
	
	void set (int val = 0){
		if(mat != NULL){
			for(int i=0; i<rows ;i++)
				for(int j=0; j<cols; j++)
					mat[i][j] = val;
		}
	}
 
	
};