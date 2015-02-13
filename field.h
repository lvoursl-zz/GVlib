#include <vector>

class Field {

public:
	Field(int w, int h);
	Field();

	void clearField();
	void drawField();
	void drawLine(int x0, int y0, int x1, int y1);
	void drawTriangle(int x0, int y0, int x1, int y1, int x2, int y2, bool filled);
	void drawRect(int x0, int y0, int x1, int y1);

	void clearScreen(); // эта функция должна быть в классе application

	~Field();

private: 
	int width;
	int height;
	std::vector< std::vector<int> > data;
};