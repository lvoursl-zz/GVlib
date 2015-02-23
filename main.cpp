#include "field.h"

int main(int argc, char** argv) {
	Field field;
	Pixel pix(5, 5);	
	Line l(0, 8, 10, 8);
	Triangle t(15, 20, 20, 15, 25, 20, true);
	field.drawTriangle(&t);
	field.drawPixel(&pix);
	field.drawLine(&l);
	field.drawField();
		
	double count = 0;
	int i = 0;

	while (true) {
		count++;
		if (count == 100000000) {
			i++;
			pix.setX(i);
			std::map<std::string, int> map = t.getCoordinates();
			map["x0"] = i;
			map["y0"] = i;
			l.setCoordinates(map);
			field.refresh();
			count = 0;
		}
	}
	 
/*	Rectangle r(26, 6, 10, 10);
	field.drawRect(r);
	Circle c(30, 5, 5);
	Circle c1(30, 10, 5);
	field.drawCircle(c);
	field.drawCircle(c1);
	Triangle t(15, 20, 20, 15, 25, 20, true);
	field.drawTriangle(t);
	Text te(1, 18, " Dorogoi, chto zhe eto takoe? ", Colors::FG_RED);	
	field.drawText(te);
	//field.drawField();
	// app loop
	double count = 0;
	double i = 0;
	/*while (true) {
		count++;		
		if (count == 10000000) {
			i++;			
			//Pixel p(i, 21);
			pix.setX(i);
			//field.drawPixel(pix);				
			field.refresh();
			count = 0;
		}

	}*/
	return 0;
}