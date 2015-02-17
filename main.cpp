#include "field.h"

int main(int argc, char** argv) {
	Field field;
	field.drawCircle(10, 10, 5);
	//field.drawCircle(30, 10, 5);
	//field.drawLine(10, 25, 30, 25);
	//field.drawTriangle(15, 20, 20, 15, 25, 20, true);
	field.drawText(7, 20, "i want to kiss you <3 ", Colors::FG_LIGHT_YELLOW);
	field.drawPixel(20, 21);	
	field.drawField();
	// app loop
	/*int count = 0;
	while (true) {
		count++;
		field.drawField();
		if (count == 99999999) {
			field.clearScreen();
			count = 0;
		}
	}*/
	return 0;
}