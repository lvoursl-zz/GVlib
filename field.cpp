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

void Field::drawLine(int x0, int y0, int x1, int y1) {
	if ((width > x0 >= 0) && (width > x1 >= 0) 
		 && (height > y0 >= 0) && (height > y1 >= 0)) {

		bool steep = false;
	    if (std::abs(x0-x1)<std::abs(y0-y1)) { 
	        std::swap(x0, y0);
	        std::swap(x1, y1);
	        steep = true;
	    }
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

void Field::drawField() {
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			std::cout << data[i][j] << " ";
		}
		std::cout << std::endl;
	}
}