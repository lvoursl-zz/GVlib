#include "text.h"

Text::Text(int x0, int y0, std::string text, Colors::Code color) : x0(x0), y0(y0), text(text), color(color) { }

Text::~Text() { }


int Text::getX() const {
	return x0;
}

int Text::getY() const {
	return y0;
}

std::string Text::getText() const {
	return text;
}

Colors::Code Text::getColor() const {
	return color;
}