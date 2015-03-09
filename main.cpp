#include "field.h"

int main(int argc, char** argv) {
	Field field(50, 30);
	Pixel pix(5, 5, Colors::BG_YELLOW);	
	Text t(0, 10, "Hello, i am graphics lib!", Colors::FG_GREEN);

	field.clearFieldOnScreen();
	//field.drawText(&t);
	//field.drawPixel(&pix);
	/*for (int i = 0; i < field.getWidth(); i++) {
		for (int j = 0; j < field.getHeight(); j++) {
			if (i % 2 == 0)
			{
				
				Pixel p(j, i, Colors::BG_RED);
				field.drawPixel(&p);
			} else if (i % 7 == 0) {
				Pixel p(j, i, Colors::BG_WHITE);
				field.drawPixel(&p);
			} else if (i % 5 == 0) {
				Pixel p(j, i, Colors::BG_YELLOW);
				field.drawPixel(&p);
			} else {
				Pixel p(j, i, Colors::BG_MAGENTA);
				field.drawPixel(&p);	
			}

			
		}
	}*/
	std::vector<int> v;
	v.push_back(5);
	v.push_back(42);
	v.push_back(51312);
	v.push_back(52144);
	v.push_back(52144);
	v.push_back(5);
	v.push_back(513);
	v.push_back(1231325);
	v.push_back(5);
	v.push_back(527);
	
	field.drawVector(v, 6, 15);
	field.drawField();
	double count = 0;
	int i = 0;

/*	while (true) {
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
	}*/
	 
	return 0;
}