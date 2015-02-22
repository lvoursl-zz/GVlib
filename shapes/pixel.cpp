#include "pixel.h"

Pixel::Pixel(int x0, int y0) : x(x0), y(y0) {
	coordinates = {
		{ "x0", x0 } ,
		{ "y0", y0 }
	};	

	type = "pixel";
}

Pixel::~Pixel() { }


int Pixel::getX() const {
	return this->x;
}

void Pixel::setX(int x) {
	this->x = x;
}

int Pixel::getY() const {
	return this->y;
}

void Pixel::setY(int y) {
	this->y = y;
}