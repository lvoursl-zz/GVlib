#include "field.h"

int main(int argc, char** argv) {
	Field field;
	//field.drawLine(6, 0, 8, 10);
	field.drawTriangle(0, 0, 6, 0, 0, 6, true);
	field.drawField();
	// app loop
	/*int count = 0;
	while (true) {
		count++;
		field.drawField();
		if (count == 20) {
			field.clearScreen();
			count = 0;
		}
	}*/
	return 0;
}