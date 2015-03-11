#include "field.h"

int main(int argc, char** argv) {
	
	// initialize field to draw

	Field field(50, 30);
	
	/*

	Do anyway you want! 
	Draw figures, visualize arrays, binary heaps, draw text, pixels!

	For example:	
	
	*/

	// initialize pixel and text
	Pixel pix(5, 5, Colors::BG_YELLOW);	
	Text t(0, 10, "Hello, i am graphics library!", Colors::FG_GREEN);
	
	field.drawPixel(&pix);
	field.drawText(&t);

	// and after that just draw a static field
	field.drawField();

	// if you want to clear screen 
	field.clearFieldOnScreen();
	
	// if you want to clear field data
	field.clearFieldData();

	// update you field in application loop with this command
	field.refresh(); 

	/* 
	In dynamic application you can do something like this:


	double count = 0;

	while (true) {
		count++;

		if (count == 100000000) {
			// do something, for example:

			pix.setX(pix.getX() + 1);	
			field.refresh();
			count = 0;
		}

	}	

	*/
	
	return 0;
}