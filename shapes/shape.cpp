#include "shape.h"

Shape::Shape() { }

Shape::~Shape() { }


int Shape::getId() const {
	return id;
}

void Shape::setId(int id) {
	this->id = id;
}

std::string Shape::getType() const {
	return type;
}

std::map<std::string, int> Shape::getCoordinates() const {
	return coordinates;
}

void Shape::setCoordinates(std::map<std::string, int> coordinates) {
	this->coordinates = coordinates;
}