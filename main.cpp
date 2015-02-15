#include "field.h"

int main(int argc, char** argv) {
	Field field;
	field.drawCircle(10, 10, 5);
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