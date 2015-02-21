#include "triangle.h"

Triangle::Triangle(int x0, int y0, int x1, int y1, int x2, int y2, bool filled) {
	coordinates = {
		{ "x0" , x0 },
		{ "y0" , y0 },
		{ "x1" , x1 },
		{ "y1" , y1 },
		{ "x2" , x2 },
		{ "y2" , y2 }
	};
	
	type = "triangle";
	this->filled = filled;
}


Triangle::~Triangle() { }


bool Triangle::isFilled() const {
	if (this->filled == true) {
		return true;
	} else {
		return false;
	}
}

bool Triangle::enableFilled(bool value) {
	filled = value;
}