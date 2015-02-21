all:
	clear
	g++ -std=c++11 main.cpp field.cpp shapes/shape.cpp shapes/pixel.cpp shapes/line.cpp shapes/triangle.cpp -o gl
	./gl
