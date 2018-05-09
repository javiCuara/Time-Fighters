#ifndef score_h
#define score_h
#include "TexRect.h"

class score : TexRect{
	int value;
	public:
		score(const char*, float, float, float, float);
		void updateScore(int value);
		void displayScore();
};

#endif
