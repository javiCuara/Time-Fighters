#include "score.h"
#include <string>
#include <sstream>

score::score(const char* label, float x = 0.1, float y = 0.1, float w = 0.5, float h = 0.5) : TexRect(label, x, y, w, h) {
	
}

void score::updateScore(int value) {
	//use for loop to create number objects
	//maybe try glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str ing[i]);
	this->value = value;
	std::ostringstream ss;
	ss << this->value;
	glColor3d(1.0,1.0,1.0);
	glRasterPos2f(-0.77, 0.96);
	std::string s = ss.str();
	const char* c = s.c_str();
	glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, (const unsigned char*)c);
}

void score::displayScore() {
	draw();
}
