#include "field.h"

int main(int argc, char** argv) {
	Field field;
	//field.drawLine(6, 0, 8, 10);
	field.drawTriangle(0, 6, 7, 6, 6, 0, true);
	//field.drawRect(5, 5, 2, 2);
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