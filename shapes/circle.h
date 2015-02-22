#include "shape.h"

class Circle : public Shape {

public:
	Circle(int x0, int y0, int radius);
	~Circle();

	int getRadius() const;
	void setRadius(int radius);
private:
	int radius;
};