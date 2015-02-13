#include "field.h"
#include <math.h>
#include <iostream>
#include <algorithm>

Field::Field(int w, int h) : width(w), height(h) {
	for (int i = 0; i < height; ++i) {
		std::vector<int> row(width);
		data.push_back(row);
		for (int j = 0; j < width; ++j) {
			data[i][j] = 0;
		}		
	}
}

Field::Field() : width(35), height(25) {
	for (int i = 0; i < height; ++i) {
		std::vector<int> row(width);
		data.push_back(row);
		for (int j = 0; j < width; ++j) {
			data[i][j] = 0;	
		}				
	}	
}

Field::~Field() { }

void Field::clearField() {
	std::cout << this << std::endl;
	for (int i = 0; i < width; ++i) {
		for (int j = 0; j < height; ++j) {
			data[i][j] = 0;
		}
	}
}

void Field::drawField() {
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			//std::cout << data[i][j] << " ";
			if (data[i][j] == 0) std::cout << "  ";
				else std::cout << data[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void Field::clearScreen() {
	for (int i = 0; i < 10; i++) {
		std::cout << "\n\n\n\n\n\n\n\n\n\n";
	}
}



void Field::drawLine(int x0, int y0, int x1, int y1) {
	if ((width > x0 >= 0) && (width > x1 >= 0) 
		 && (height > y0 >= 0) && (height > y1 >= 0)) {

		/* для адекватной отрисовки линий, 
		вытянутых вверх. если рисовать без него, то
		линии получаются с пробелами*/
		bool steep = false;
	    if (std::abs(x0-x1)<std::abs(y0-y1)) { 
	        std::swap(x0, y0);
	        std::swap(x1, y1);
	        steep = true;
	    }
	    /* отрисовка происходит слева направо, поэтому 
	    линии с обратными координатами нужно привести к стандатному
	    для алгоритма виду (х1 > x0) т.е. для отрисовки слева направо*/
	    if (x0>x1) { 
	        std::swap(x0, x1);
	        std::swap(y0, y1);
	    }

	    for (int x=x0; x<=x1; x++) {
	        float t = (x-x0)/(float)(x1-x0);
       		int y = round(y0*(1.-t) + y1*t);	        
	        if (steep) {
	            data[x][y] = 1;
	        } else {
	            data[y][x] = 1;
	        }
	    }

	} else {
		std::cout << "can't draw line (coordinates are out of range)" << std::endl;
	}
}

void Field::drawTriangle(int x0, int y0, int x1, int y1, int x2, int y2, bool filled) {
	int a = sqrt(pow(x0 - x1, 2) + pow(y0 - y1, 2)); 
	int b = sqrt(pow(x0 - x2, 2) + pow(y0 - y2, 2)); 
	int c = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)); 
//std::cout << a << b << c;
	if ((a + b >= c) && (a + c >= b) && (c + b >= a)) {
		drawLine(x0, y0, x1, y1);
		drawLine(x0, y0, x2, y2);
		drawLine(x1, y1, x2, y2);
	

	}
}

void Field::drawRect(int x0, int y0, int x1, int y1) { 
	if (y1 < y0) {
		std::swap(y1, y0);
		std::swap(x1, x0);
	}

	for (int y = y0; y < y1; y++) {
		drawLine(x0, y, x1, y);
	}
}