all:
	clear
	g++ -std=c++11 main.cpp field.cpp text.cpp shapes/shape.cpp shapes/pixel.cpp shapes/line.cpp shapes/triangle.cpp shapes/rectangle.cpp shapes/circle.cpp data_structures/binary_heap.cpp -o gl
	./gl
