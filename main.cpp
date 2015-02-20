#include "field.h"

int main(int argc, char** argv) {
	Field field;
	field.drawCircle(10, 10, 5);
	Pixel pix(5, 5);
	//field.drawCircle(30, 10, 5);
	//field.drawLine(10, 25, 30, 25);
	//field.drawTriangle(15, 20, 20, 15, 25, 20, true);
	field.drawText(7, 20, "i want to kiss you <3 ", Colors::FG_LIGHT_YELLOW);	
	field.drawField();
	// app loop
	double count = 0;
	double i = 0;
	while (true) {
		count++;		
		if (count == 10000000) {
			i++;
			field.clearScreen();
			Pixel p(i, 21);
			field.drawPixel(p);				
			field.drawField();			
			count = 0;
		}

	}
	return 0;
}