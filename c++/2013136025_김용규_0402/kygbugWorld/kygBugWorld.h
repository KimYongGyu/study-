#pragma once
#include "kygMatrixI.h"
#include "kygDrunkenBug.h"
#include "kygLadyBug.h"
#include "kygManBug.h"
#include "kygBugs.h"
#include "kygsuperLadyBug.h"

class kygBugWorld : public kygMatrixI
{
	kygBug* bugs[100];
	int nBugs;
	kygMatrixI screen;

public:

	kygBugWorld(int rows =0, int cols =0)
		: kygMatrixI(rows, cols) , screen(rows, cols) {}

	int Rows() {return rows;}
	int Cols() {return cols;}
	int& Map(int i, int j) {return mat[i][j];}
	int& Display(int i, int j) {return screen.get(i,j);}

	void setRandomItems( int numItems){
		for(int a=0; a<numItems; a++){
			Map(rand() % Rows(),rand() % Cols())=(rand()%4+2);
		}
	}

	void Move(){
		
		int dir = rand() % nBugs;
		bugs[dir]->Move(Rows() ,Cols());
		int a,b;
		bugs[dir]->GetPosition(a,b);
		if(Map(b,a) >0){
			Map(b,a)--;
			bugs[dir]->Eat();
		}



	}

	void print(){
		int x,y;
		for(int i =0; i<Rows();i++){
			for(int j =0; j<Cols();j++){
				if(Map(i,j) ==0 )	Display(i,j) = '.';
				else		Display(i,j) = '0' +Map(i,j);	}}
		for(int i =0; i<nBugs; i++) {
			bugs[i]->GetPosition(x,y);
			Display(y,x) = bugs[i]->GetName();		}
		system("cls");
		printf("\n\t< 벌레들의 세상 by KYG >\n");
		printf("------------------------------------\n");
		for( int i = 0; i<Rows(); i++){
			printf("\t");
			for( int j =0; j<Cols(); j++)
				printf("%c",Display(i,j));
			printf("\n");	}
		printf("------------------------------------\n");		
		for( int i =0; i< nBugs; i++)
			bugs[i]->PrintStatus();
		printf("\n");	}





	void Play(int maxwalk, int wait =0){
		set(0);
		setRandomItems(10);

		bugs[0] = new kygLadyBug ('L', rand()%Rows(), rand()%Cols());
		bugs[1] = new kygDrunkenBug('D', rand()%Rows(), rand()%Cols());
		bugs[2] = new kygManBug ('M', rand()%Rows(), rand()%Cols());
		bugs[3] = new kygBugs ('K', rand()%Rows(), rand()%Cols());
		bugs[4] = new kygsuperLadyBug ('S', rand()%Rows(), rand()%Cols());
		nBugs = 5;
		print();
		fflush(stdin);
		printf("엔터를 누르면 시작합니다.");
		getchar();

		for(int i = 0; i<maxwalk ;i++) {
			Move();
			print();
			printf("Total Move %d \n\n ", i+1);
			Sleep(wait);
		}
	}
};