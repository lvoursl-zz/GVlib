#include <vector>
#include <string>
#include "colors.h"

class Field {

public:
	Field(int w, int h);
	Field();

	void clearField();
	void drawField();
	void drawLine(int x0, int y0, int x1, int y1);
	void drawTriangle(int x0, int y0, int x1, int y1, int x2, int y2, bool filled);
	void drawRect(int x0, int y0, int x1, int y1);
	void drawCircle(int x0, int y0, int radius);
	void drawText(int x0, int y0, std::string text, Colors::Code color);

	bool pointInTriangle(int x0, int y0, int x1, int y1, int x2, int y2, int pointX, int pointY);
	void clearScreen(); 

	~Field();

private: 
	int width;
	int height;
	std::vector< std::vector<char> > data;
};