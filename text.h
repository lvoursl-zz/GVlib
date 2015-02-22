#include <string>
#include "colors.h"

class Text {

public:
	Text(int x0, int y0, std::string text, Colors::Code color = Colors::FG_DEFAULT);
	~Text();

	int getX() const;
	int getY() const;
	std::string getText() const;
	Colors::Code getColor() const;

private:
	int x0;
	int y0;
	std::string text;
	Colors::Code color;

};