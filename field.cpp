#include "field.h"


Field::Field(int w, int h) : width(w), height(h) {
	for (int i = 0; i < height; ++i) {
		std::vector<std::string> row(width);
		data.push_back(row);
		for (int j = 0; j < width; ++j) {
			data[i][j] = "NULL";
		}		
	}
}

Field::Field() : width(35), height(25) {
	for (int i = 0; i < height; ++i) {
		std::vector<std::string> row(width);
		data.push_back(row);
		for (int j = 0; j < width; ++j) {
			data[i][j] = "NULL";	
		}				
	}	
}

Field::~Field() { }

int Field::getWidth() const {
	return width;
} 

int Field::getHeight() const {
	return height;
}

void Field::clearFieldData() {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			data[i][j] = "NULL";
		}
	}
}

void Field::clearFieldData(int x0, int y0, int x1, int y1) {
	if ((width > x0) && (x0 >= 0) && (width > x1) && (x1 >= 0) 
		 && (height > y0) && (y0 >= 0) && (height > y1) && (y1 >= 0)) { 

		if ((x0 > x1) || (y0 > y1)) {
		 	std::swap(x0, x1); 
		 	std::swap(y0, y1);		
		}

		for (int x = x0; x <= x1; x++) {			
			for (int y = y0; y <= y1; y++) {
				data[y][x] = "NULL";
			}
		}
	}
}

void Field::drawField() {
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			if (data[i][j] == "NULL") std::cout << "  ";
				else std::cout << data[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void Field::clearFieldOnScreen() {
	system("clear"); 
}

void Field::refresh() {
	system("clear"); 
	clearFieldData();
	
	for (int i = 0; i < pixelVector.size(); i++) {
		drawPixel(pixelVector[i]);
 	}

 	for (int i = 0; i < lineVector.size(); i++) {
 		drawLine(lineVector[i]);
 	}
 	
 	for (int i = 0; i < triangleVector.size(); i++) {
 		drawTriangle(triangleVector[i]);
 	}


 	for (int i = 0; i < rectangleVector.size(); i++) {
 		drawRectangle(rectangleVector[i]);
 	}

	for (int i = 0; i < circleVector.size(); i++) {
 		drawCircle(circleVector[i]);
 	}

 	for (int i = 0; i < textVector.size(); i++) {
 		drawText(textVector[i]);
 	}


	drawField();
}


void Field::drawLine(Line *line) {
	std::map<std::string, int> lineCoordinates = line->getCoordinates();

	int x0 = lineCoordinates.at("x0");
	int y0 = lineCoordinates.at("y0"); 
	int x1 = lineCoordinates.at("x1");
	int y1 = lineCoordinates.at("y1");

	if ((width > x0) && (x0 >= 0) && (width > x1) && (x1 >= 0) 
		 && (height > y0) && (y0 >= 0) && (height > y1) && (y1 >= 0)) {


		bool lineInArray = false;
		for (int i = 0; i < lineVector.size(); i++) {
			if (line == lineVector[i]) {
				 lineInArray = true;
				 break;
			}
		}

		if ( !lineInArray ) lineVector.push_back(line);

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

void Field::drawTriangle(Triangle *triangle) {

	std::map<std::string, int> triangleCoordinates = triangle->getCoordinates();

	int x0 = triangleCoordinates.at("x0");
	int y0 = triangleCoordinates.at("y0"); 
	int x1 = triangleCoordinates.at("x1");
	int y1 = triangleCoordinates.at("y1");
	int x2 = triangleCoordinates.at("x2");
	int y2 = triangleCoordinates.at("y2");
	
	if ((width > x0) && (x0 >= 0) && (width > x1) && (x1 >= 0) 
		 && (height > y0) && (y0 >= 0) && (height > y1) && (y1 >= 0)
		 && (width > x2) && (x2 >= 0) && (height > y2) && (y2 >= 0)) {

		bool triangleInArray = false;
		for (int i = 0; i < triangleVector.size(); i++) {
			if (triangle == triangleVector[i]) {
				 triangleInArray = true;
				 break;
			}
		}

		if ( !triangleInArray ) triangleVector.push_back(triangle);
		

		int a = sqrt(pow(x0 - x1, 2) + pow(y0 - y1, 2)); 
		int b = sqrt(pow(x0 - x2, 2) + pow(y0 - y2, 2)); 
		int c = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)); 

		if ((a + b >= c) && (a + c >= b) && (c + b >= a)) {
			drawLine(x0, y0, x1, y1);
			drawLine(x0, y0, x2, y2);
			drawLine(x1, y1, x2, y2);

			/* если треугольник закрашен, то используем бароцентрический алгоритм для отрисовки*/		
			if (triangle->isFilled() == true) {				
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
						bool res = triangle->pointInTriangle(x, y);
						if (res) data[y][x] = "1";
					}
				}


			}
		}
	}
}


void Field::drawRectangle(Rectangle *rectangle) { 

	std::map<std::string, int> rectangleCoordinates = rectangle->getCoordinates();

	int x0 = rectangleCoordinates.at("x0");
	int y0 = rectangleCoordinates.at("y0"); 
	int x1 = rectangleCoordinates.at("x1");
	int y1 = rectangleCoordinates.at("y1");

	if ((width > x0) && (x0 >= 0) && (width > x1) && (x1 >= 0) 
		 && (height > y0) && (y0 >= 0) && (height > y1) && (y1 >= 0)) {


		bool rectangleInArray = false;
		for (int i = 0; i < rectangleVector.size(); i++) {
			if (rectangle == rectangleVector[i]) {
				 rectangleInArray = true;
				 break;
			}
		}

		if ( !rectangleInArray ) rectangleVector.push_back(rectangle);


		if (y1 < y0) {
			std::swap(y1, y0);
			std::swap(x1, x0);
		}

		for (int y = y0; y < y1; y++) {
			drawLine(x0, y, x1, y);
		}
	}
}

void Field::drawCircle(Circle *circle) {

	std::map<std::string, int> circleCoordinates = circle->getCoordinates();

	int x0 = circleCoordinates.at("x0");
	int y0 = circleCoordinates.at("y0"); 
	int radius = circle->getRadius();

	if ((width > x0) && (x0 >= 0) && (height > y0) && (y0 >= 0)
		&& (x0 - radius >= 0) && (y0 - radius >= 0)
		&& (x0 + radius <= width) && (y0 + radius <= height)) {


			bool circleInArray = false;
			for (int i = 0; i < circleVector.size(); i++) {
				if (circle == circleVector[i]) {
					 circleInArray = true;
					 break;
				}
			}

			if ( !circleInArray ) circleVector.push_back(circle);

			for (int x = x0 - radius; x < x0 + radius; x++) {
				for (int y = y0 - radius; y < y0 + radius; y++) {
					if ((x0 - x)*(x0 - x) + (y0 - y)*(y0 - y) < (radius * radius)) data[y][x] = "1";
				}
			}			

	} else {
		std::cerr << "cant draw this circle. coordinates are out of range";
	}
}

void Field::drawText(Text *userText) {

	int x0 = userText->getX(); 
	int y0 = userText->getY();
	std::string text = userText->getText();
	Colors::Code color = userText->getColor();
	
	if ((x0 + text.length() <= width) && (width > x0) && (x0 >= 0) 
									  && (height > y0) && (y0 >= 0)) {

		
		bool textInArray = false;
		for (int i = 0; i < textVector.size(); i++) {
			if (userText == textVector[i]) {
				 textInArray = true;
				 break;
			}
		}

		if ( !textInArray ) textVector.push_back(userText);


		int textCount = 0;
		for (int i = x0; i < x0 + text.length(); i++) {
			data[y0][i] = "\033[" + std::to_string(color) + "m" + text.at(textCount) + "\033[m";
			textCount++;
		}		
	}
}

void Field::drawPixel(Pixel *pixel) {
	if ((width > pixel->getX()) && (pixel->getX() >= 0) && (height > pixel->getY()) && (pixel->getY() >= 0)) {
		
		bool pixelInArray = false;
		for (int i = 0; i < pixelVector.size(); i++) {
			if (pixel == pixelVector[i]) {
				 pixelInArray = true;
				 break;
			}
		}

		if ( !pixelInArray ) pixelVector.push_back(pixel);

		data[pixel->getY()][pixel->getX()] =  "\033[" +std::to_string(pixel->getColor()) + "m" +  "  " + "\033[m";
	}
}

void Field::drawBinaryHeap(BinaryHeap binaryHeap, int x0, int y0) {
	if ((width > x0) && (x0 >= 0) && (height > y0) && (y0 >= 0)) {
		std::vector<int> binaryHeapData = binaryHeap.getData();
		
		int h;

		for (int i = 0; i < binaryHeapData.size(); i++) {
			if (pow(2, i) > binaryHeapData.size()) {
				h = i;
				break;
			}
		}

		int x = x0;
		int y = y0;
		int degree = 0;
		int leftStep =  x0;
		int step = 0;
		for (int i = 1; i < binaryHeapData.size(); i++) {
			if (i < pow(2, degree)) { 								
				x += step;
				data[y][x] = std::to_string(binaryHeapData[i]);				
			} else if (i == 1) {
				degree++;
				data[y][x] = std::to_string(binaryHeapData[i]);				
			} else if (i == pow(2, degree)) {				
				y += 1;				
				degree++;					
				step = pow(2, (h - degree + 1));
				leftStep -= (step / 2);

				x = leftStep;
				data[y][x] = std::to_string(binaryHeapData[i]);
			}
		}

		/*int stepX = x0;
		int y = y0;
		int degree = 0;
		int leftStep = x0;
		int step = 0;
		std::string indent = "";

		for (int i = 1; i < binaryHeapData.size(); i++) {
			if (i < pow(2, degree)) { 								
				indent = createIndentForData(step);
				data[y][stepX] = indent + std::to_string(binaryHeapData[i]);				
			} else if (i == 1) {
				degree++;
				data[y][stepX] = std::to_string(binaryHeapData[i]);				
			} else if (i == pow(2, degree)) {				
				y += 1;				
				degree++;					
				step = pow(2, (h - degree + 1));
				
				leftStep -= (step / 2);				
				stepX = leftStep;
				data[y][stepX] = std::to_string(binaryHeapData[i]) ;
			}
			indent = "";
			stepX++;
		}*/
	}
}

void Field::drawVector(std::vector<int> vec, int x0, int y0) {
	if ((width > x0) && (x0 >= 0) && (height > y0) && (y0 >= 0) && 
		(x0 + vec.size() < width) && (y0 + 2 < height)) { 

		int x = x0;
		int y = y0;
		int numberInVector = 0;
		int length = 0;
		std::string leftStep = "";
		std::string rightStep = "";

		for (int i = 0; i < vec.size(); i++) {
			numberInVector = vec[i];
			while ( numberInVector != 0 ) {
				numberInVector /= 10;
				length++;
			}

			if (length % 2 == 0) {
				leftStep = createIndentForData(length / 2);
				rightStep = createIndentForData((length / 2) - 1);
			} else {
				leftStep = createIndentForData(length / 2);
				rightStep = createIndentForData(length / 2);
			}

			data[y][x] = leftStep + std::to_string(i) + rightStep;
			
			x++;			
			length = 0;
		}

		y++;
		x = x0;

		for (int i = 0; i < vec.size(); i++) {
			data[y][x] = std::to_string(vec[i]);
			x++;
		}


	}
}

std::string Field::createIndentForData(int length) {
	std::string indentForData = "";

	for (int i = 0; i < length; i++) {
		indentForData = indentForData + " ";
	}

	return indentForData;
}


void Field::deleteShape(Line *line) {
	for (int i = 0; i < lineVector.size(); i++) {
		if (line == lineVector[i]) {
			 lineVector.erase(lineVector.begin() + i);
			 break;
		}
	}
	//delete line; << segfault with it!
	line = NULL;
}

void Field::deleteShape(Triangle *triangle) {
	for (int i = 0; i < triangleVector.size(); i++) {
		if (triangle == triangleVector[i]) {
			 triangleVector.erase(triangleVector.begin() + i);
			 break;
		}
	}
	
	triangle = NULL;
}

void Field::deleteShape(Rectangle *rectangle) {
	for (int i = 0; i < rectangleVector.size(); i++) {
		if (rectangle == rectangleVector[i]) {
			 rectangleVector.erase(rectangleVector.begin() + i);
			 break;
		}
	}
	
	rectangle = NULL;
}

void Field::deleteShape(Circle *circle) {
	for (int i = 0; i < circleVector.size(); i++) {
		if (circle == circleVector[i]) {
			 circleVector.erase(circleVector.begin() + i);
			 break;
		}
	}
	
	circle = NULL;
}

void Field::deleteShape(Pixel *pixel) {
	for (int i = 0; i < pixelVector.size(); i++) {
		if (pixel == pixelVector[i]) {
			 pixelVector.erase(pixelVector.begin() + i);
			 break;
		}
	}
	
	pixel = NULL;
}