#include "field.h"

int main(int argc, char** argv) {
	Field field(50, 30);
	Pixel pix(5, 5);	
	Line l(0, 8, 10, 8);
	Triangle t(15, 20, 20, 15, 25, 20, true);
	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);
	v.push_back(8);
	v.push_back(9);
	BinaryHeap hp(v);
	hp.sortHeap();
	
	Rectangle r(26, 6, 10, 10);
	//field.drawRectangle(&r);
	
	field.drawBinaryHeap(hp, 34, 15);
	field.drawField();
	//field.deleteShape(&l);
	double count = 0;
	int i = 0;

/*	while (true) {
		count++;
		if (count == 100000000) {
			i++;
			pix.setX(i);
			std::map<std::string, int> map = t.getCoordinates();
			map["x0"] = i;
			map["y0"] = i;
			l.setCoordinates(map);
			std::map<std::string, int> map = c1.getCoordinates();
			map["y0"] = map["y0"] + 1;			
			c1.setCoordinates(map);
			field.refresh();
			count = 0;
		}
	}*/
	 
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