#include <map>
#include <string>
#include "shape.h"

class Pixel : public Shape {

public:
	Pixel(int x, int y);
	~Pixel();
	
	int getX() const;
	void setX(int x);
	int getY() const;
	void setY(int y);

private:
	int x;
	int y;
	std::map<std::string, int> coordinates;
	std::string value;

};