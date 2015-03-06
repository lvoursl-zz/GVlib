#include <string>
#include "shape.h"
#include "../colors.h"

class Pixel : public Shape {

public:
	Pixel(int x0, int y0, Colors::Code color = Colors::FG_DEFAULT);
	~Pixel();
	
	int getX() const;
	void setX(int x);
	int getY() const;
	void setY(int y);

	Colors::Code getColor() const;
	void setColor(Colors::Code color);

private:
	int x;
	int y;
	Colors::Code color;

};