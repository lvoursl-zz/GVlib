#include "field.h"

int main(int argc, char** argv) {
	Field field;
	//field.drawCircle(10, 10, 5);
	Pixel pix(5, 5);	
	Rectangle r(26, 6, 10, 10);
	field.drawRect(r);
	Circle c(30, 5, 5);
	Circle c1(30, 10, 5);
	field.drawCircle(c);
	field.drawCircle(c1);
	//field.drawLine(10, 25, 30, 25);
	Triangle t(15, 20, 20, 15, 25, 20, true);
	field.drawTriangle(t);
	Text te(1, 18, " Dorogoi, chto zhe eto takoe? ", Colors::FG_RED);	
	field.drawText(te);
	field.drawField();
	// app loop
	double count = 0;
	double i = 0;
	while (true) {
		count++;		
		if (count == 10000000) {
			i++;			
			Pixel p(i, 21);
			field.drawPixel(p);				
			field.refresh();
			count = 0;
		}

	}
	return 0;
}