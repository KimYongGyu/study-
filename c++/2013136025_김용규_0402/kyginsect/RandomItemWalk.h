#pragma once
#include "kygRandomwalk.h"
class RandomItemWalk : public RandomWalk
{
	int nitem;//아이템 획득점수
public:

	RandomItemWalk(int rows = 0, int cols = 0) : RandomWalk(rows, cols)	{ntime = 0;	}

	~RandomItemWalk(void)	{	}

	//Random하게 item을 맵에 추가함
	void setRandomitems(int numitems) {
	}

	//벌레가 현재 위치에서 무작위로 8방향 이웃중 하나로 이동하는 함수
	//벌레가 map의 경계 밖으로 나가지 못하도록 처리해야함
	void move() {
	}
	//Random Walk map의 현재 상태를 화면에 출력함
	void print(){
	}

	//Random walk의 메인함수
	//입력: 최대 이동 횟수(maxwalk)와 한번 이동 후 쉬는시간(wait)을 입력
	//쉬는 시간을 위해 sleep(msec) 함수 이용 ( 사용법은 인터넷 찾아볼 것)
	void play( int maxwalk, int wait = 0){
	}

};

