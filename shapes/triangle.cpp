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

bool Triangle::pointInTriangle(int pointX, int pointY) {
	std::map<std::string, int> triangleCoordinates = this->getCoordinates();

	int x0 = triangleCoordinates.at("x0");
	int y0 = triangleCoordinates.at("y0"); 
	int x1 = triangleCoordinates.at("x1");
	int y1 = triangleCoordinates.at("y1");
	int x2 = triangleCoordinates.at("x2");
	int y2 = triangleCoordinates.at("y2");

	double denominator = ((y1 - y2)*(x0 - x2) + (x2 - x1)*(y0 - y2));
	double a = ((y1 - y2)*(pointX - x2) + (x2 - x1)*(pointY - y2)) / denominator;
	double b = ((y2 - y0)*(pointX - x2) + (x0 - x2)*(pointY - y2)) / denominator;
	double c = 1 - a - b;
	 
	return ((0 <= a) && (a <= 1) && (0 <= b) && (b <= 1) && (0 <= c) && (c <= 1));
}