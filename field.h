#include <vector>
#include <string>
#include "colors.h"
#include "shapes/pixel.h"
#include "shapes/line.h"
#include "shapes/triangle.h"
#include "shapes/rectangle.h"
#include "shapes/circle.h"


class Field {

public:
	Field(int w, int h);
	Field();

	void clearField();
	void clearField(int x0, int y0, int x1, int y1);

	void drawField();
	void drawLine(Line line);
	void drawLine(int x0, int y0, int x1, int y1);
	void drawTriangle(Triangle triangle);
	void drawRect(int x0, int y0, int x1, int y1);
	void drawCircle(int x0, int y0, int radius);
	void drawText(int x0, int y0, std::string text, Colors::Code color = Colors::FG_DEFAULT);
	void drawPixel(Pixel pixel);

	bool pointInTriangle(int x0, int y0, int x1, int y1, int x2, int y2, int pointX, int pointY);
	void clearScreen(); 

	int getWidth() const; 
	int getHeight() const;

	~Field();

private: 
	int width;
	int height;
	std::vector< std::vector<std::string> > data;
	std::vector<Shape> globalShapesVector; // it should be vector of smart pointers?
};