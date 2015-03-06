#include "field.h"

int main(int argc, char** argv) {
	Field field(50, 30);
	Pixel pix(5, 5, Colors::BG_YELLOW);	
	Text t(0, 10, "Hello, i am graphics lib!", Colors::FG_GREEN);

	field.clearFieldOnScreen();
	field.drawText(&t);
	field.drawPixel(&pix);
	field.drawField();
	double count = 0;
	int i = 0;

	while (true) {
		count++;
		if (count == 100000000) {
			i++;

			if (i % 2 == 0) {
				pix.setColor(Colors::BG_WHITE);				
			} else {
				pix.setColor(Colors::BG_YELLOW);
			}

			t.setX(t.getX() + 1);

			field.refresh();
			count = 0;
		}
	}
	 
	return 0;
}