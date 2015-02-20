#include "shape.h"

Shape::Shape() { }

Shape::~Shape() { }


int Shape::getId() const {
	return id;
}

void Shape::setId(int id) {
	this->id = id;
}