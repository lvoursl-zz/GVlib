#include "pixel.h"

Pixel::Pixel(int x, int y) : x(x), y(y) {
	coordinates = {
		{ "x", x } ,
		{ "y", y }
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