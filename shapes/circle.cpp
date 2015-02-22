#include "circle.h"

Circle::Circle(int x0, int y0, int radius) {
	coordinates = {
		{ "x0", x0 } ,
		{ "y0", y0 }
	};	

	this->radius = radius;
	this->type = "circle";
}

Circle::~Circle() { }

int Circle::getRadius() const {
	return radius;
}

void Circle::setRadius(int radius) {
	this->radius = radius;
}