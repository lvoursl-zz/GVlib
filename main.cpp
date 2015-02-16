#include "field.h"

int main(int argc, char** argv) {
	Field field;
	field.drawCircle(10, 10, 5);
	//field.drawCircle(30, 10, 5);
	//field.drawLine(10, 25, 30, 25);
	//field.drawTriangle(15, 20, 20, 15, 25, 20, true);
	field.drawText(5, 20, "privet, what about you?", Colors::FG_RED);
	field.drawField();
	// app loop
	int count = 0;
	/*while (true) {
		count++;
		field.drawField();
		if (count == 20) {
			field.clearScreen();
			count = 0;
		}
	}*/
	return 0;
}