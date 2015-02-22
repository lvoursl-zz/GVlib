#include <string>
#include "shape.h"

class Pixel : public Shape {

public:
	Pixel(int x0, int y0);
	~Pixel();
	
	int getX() const;
	void setX(int x);
	int getY() const;
	void setY(int y);

private:
	int x;
	int y;

};