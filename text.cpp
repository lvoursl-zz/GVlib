#include "text.h"

Text::Text(int x0, int y0, std::string text, Colors::Code color) : x0(x0), y0(y0), text(text), color(color) { }

Text::~Text() { }


int Text::getX() const {
	return x0;
}

void Text::setX(int x) {
	this->x0 = x;
}

int Text::getY() const {
	return y0;
}

void Text::setY(int y) {
	this->y0 = y;
}

std::string Text::getText() const {
	return text;
}

void Text::setText(std::string text) {
	this->text = text;
}

Colors::Code Text::getColor() const {
	return color;
}

void Text::setColor(Colors::Code color) {
	this->color = color;
}