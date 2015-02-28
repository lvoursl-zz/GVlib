#include <vector>
#include <string>
#include <math.h>
#include <iostream>
#include <algorithm>
#include "colors.h"
#include "text.h"
#include "shapes/pixel.h"
#include "shapes/line.h"
#include "shapes/triangle.h"
#include "shapes/rectangle.h"
#include "shapes/circle.h"
#include "data_structures/binary_heap.h"


class Field {

public:
	Field(int w, int h);
	Field();

	void clearFieldData();
	void clearFieldData(int x0, int y0, int x1, int y1);
	void clearFieldOnScreen(); 
	void refresh();

	void drawField();
	void drawLine(Line *line);
	void drawLine(int x0, int y0, int x1, int y1);
	void drawTriangle(Triangle *triangle);
	void drawRectangle(Rectangle *rectangle);
	void drawCircle(Circle *circle);
	void drawText(Text text);
	void drawPixel(Pixel *pixel);

	void drawBinaryHeap(BinaryHeap binaryHeap, int x0, int y0);
	void drawArray();

	void deleteShape(Line *line);
	void deleteShape(Triangle *triangle);
	void deleteShape(Rectangle *rectangle);
	void deleteShape(Circle *circle);
	void deleteShape(Pixel *pixel);

	int getWidth() const; 
	int getHeight() const;

	~Field();

private: 
	int width;
	int height;
	std::vector< std::vector<std::string> > data;

	std::vector<Pixel *> pixelVector;
	std::vector<Line *> lineVector;
	std::vector<Triangle *> triangleVector;
	std::vector<Rectangle *> rectangleVector;
	std::vector<Circle *> circleVector;
};