#include <string>
#include "colors.h"

class Text {

public:
	Text(int x0, int y0, std::string text, Colors::Code color = Colors::FG_DEFAULT);
	~Text();

	int getX() const;
	void setX(int x);

	int getY() const;
	void setY(int y);

	std::string getText() const;
	void setText(std::string text);

	Colors::Code getColor() const;
	void setColor(Colors::Code color);

private:
	int x0;
	int y0;
	std::string text;
	Colors::Code color;

};