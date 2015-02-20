#include "field.h"
#include <math.h>
#include <iostream>
#include <algorithm>


Field::Field(int w, int h) : width(w), height(h) {
	for (int i = 0; i < height; ++i) {
		std::vector<std::string> row(width);
		data.push_back(row);
		for (int j = 0; j < width; ++j) {
			data[i][j] = "0";
		}		
	}
}

Field::Field() : width(35), height(25) {
	for (int i = 0; i < height; ++i) {
		std::vector<std::string> row(width);
		data.push_back(row);
		for (int j = 0; j < width; ++j) {
			data[i][j] = "0";	
		}				
	}	
}

Field::~Field() { }

void Field::clearField() {
	std::cout << this << std::endl;
	for (int i = 0; i < width; ++i) {
		for (int j = 0; j < height; ++j) {
			data[i][j] = "0";
		}
	}
}

void Field::clearField(int x0, int y0, int x1, int y1) {
	if ((width > x0) && (x0 >= 0) && (width > x1) && (x1 >= 0) 
		 && (height > y0) && (y0 >= 0) && (height > y1) && (y1 >= 0)) { 

		if ((x0 > x1) || (y0 > y1)) {
		 	std::swap(x0, x1); 
		 	std::swap(y0, y1);		
		}

		for (int x = x0; x <= x1; x++) {			
			for (int y = y0; y <= y1; y++) {
				data[y][x] = "0";
			}
		}
	}
}

void Field::drawField() {
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			if (data[i][j] == "0") std::cout << "  ";
				else std::cout << data[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void Field::clearScreen() {
	system("clear"); // THATS A RIGHT WAY + как-то настроить курсор (insert?)
}



void Field::drawLine(int x0, int y0, int x1, int y1) {
	if ((width > x0) && (x0 >= 0) && (width > x1) && (x1 >= 0) 
		 && (height > y0) && (y0 >= 0) && (height > y1) && (y1 >= 0)) {

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
	            data[x][y] = "1";
	        } else {
	            data[y][x] = "1";
	        }
	    }

	} else {
		std::cerr << "can't draw line (coordinates are out of range)" << std::endl;
	}
}

void Field::drawTriangle(int x0, int y0, int x1, int y1, int x2, int y2, bool filled) {
	
	if ((width > x0) && (x0 >= 0) && (width > x1) && (x1 >= 0) 
		 && (height > y0) && (y0 >= 0) && (height > y1) && (y1 >= 0)
		 && (width > x2) && (x2 >= 0) && (height > y2) && (y2 >= 0)) {

		int a = sqrt(pow(x0 - x1, 2) + pow(y0 - y1, 2)); 
		int b = sqrt(pow(x0 - x2, 2) + pow(y0 - y2, 2)); 
		int c = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)); 

		if ((a + b >= c) && (a + c >= b) && (c + b >= a)) {
			drawLine(x0, y0, x1, y1);
			drawLine(x0, y0, x2, y2);
			drawLine(x1, y1, x2, y2);

			/* если треугольник закрашен, то используем бароцентрический алгоритм для отрисовки*/		
			if (filled) {
				int xMax = std::max(x0, x1);
				xMax = std::max(xMax, x2);

				int xMin = std::min(x0, x1);
				xMin = std::min(xMin, x2);

				int yMax = std::max(y0, y1);
				yMax = std::max(yMax, y2);

				int yMin = std::min(y0, y1);
				yMin = std::min(yMin, y2);

				for (int x = xMin; x < xMax; x++) {
					for (int y = yMin; y < yMax; y++) {
						bool res = pointInTriangle(x0, y0, x1, y1, x2, y2, x, y);
						if (res) data[y][x] = "1";
					}
				}


			}
		}
	}
}

bool Field::pointInTriangle(int x0, int y0, int x1, int y1, 
							int x2, int y2, int pointX, int pointY) {

	double denominator = ((y1 - y2)*(x0 - x2) + (x2 - x1)*(y0 - y2));
	double a = ((y1 - y2)*(pointX - x2) + (x2 - x1)*(pointY - y2)) / denominator;
	double b = ((y2 - y0)*(pointX - x2) + (x0 - x2)*(pointY - y2)) / denominator;
	double c = 1 - a - b;
	 
	return ((0 <= a) && (a <= 1) && (0 <= b) && (b <= 1) && (0 <= c) && (c <= 1));
}

void Field::drawRect(int x0, int y0, int x1, int y1) { 
	if ((width > x0) && (x0 >= 0) && (width > x1) && (x1 >= 0) 
		 && (height > y0) && (y0 >= 0) && (height > y1) && (y1 >= 0)) {

		if (y1 < y0) {
			std::swap(y1, y0);
			std::swap(x1, x0);
		}

		for (int y = y0; y < y1; y++) {
			drawLine(x0, y, x1, y);
		}
	}
}

void Field::drawCircle(int x0, int y0, int radius) {
	if ((width > x0) && (x0 >= 0) && (height > y0) && (y0 >= 0)
		&& (x0 - radius >= 0) && (y0 - radius >= 0)
		&& (x0 + radius <= width) && (y0 + radius <= height)) {

			for (int x = x0 - radius; x < x0 + radius; x++) {
				for (int y = y0 - radius; y < y0 + radius; y++) {
					if ((x0 - x)*(x0 - x) + (y0 - y)*(y0 - y) < (radius * radius)) data[y][x] = "1";
				}
			}			

	} else {
		std::cerr << "cant draw this circle. coordinates are out of range";
	}
}

void Field::drawText(int x0, int y0, std::string text, Colors::Code color) {
	if ((x0 + text.length() <= width) && (width > x0) && (x0 >= 0) 
									  && (height > y0) && (y0 >= 0)) {
		int textCount = 0;
		for (int i = x0; i < x0 + text.length(); i++) {
			data[y0][i] = "\033[" + std::to_string(color) + "m" + text.at(textCount) + "\033[m";
			textCount++;
		}		
	}
}

void Field::drawPixel(Pixel pixel) {
	if ((width > pixel.getX()) && (pixel.getX() >= 0) && (height > pixel.getY()) && (pixel.getY() >= 0)) {
		data[pixel.getY()][pixel.getX()] = (char)254;
		globalShapesVector.push_back(pixel);	
	}
}