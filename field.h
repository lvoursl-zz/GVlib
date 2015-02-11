#include <vector>

class Field {

public:
	Field(int w, int h);
	Field();

	void clearField();
	void drawLine(int x0, int y0, int x1, int y1);
	void drawField();

	~Field();

private: 
	int width;
	int height;
	std::vector< std::vector<int> > data;
	//int data[][];
};