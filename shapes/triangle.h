#include "shape.h"

class Triangle : public Shape {

public:
	Triangle(int x0, int y0, int x1, int y1, int x2, int y2, bool filled);
	~Triangle();

	bool isFilled() const;
	bool enableFilled(bool value);

private:
	bool filled;

};