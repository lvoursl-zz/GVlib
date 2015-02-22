#include "rectangle.h"

Rectangle::Rectangle(int x0, int y0, int x1, int y1) {

	coordinates = {
		{ "x0" , x0 },
		{ "y0" , y0 },
		{ "x1" , x1 },
		{ "y1" , y1 }
	};

	this->type = "rectangle";
}

Rectangle::~Rectangle() { }
