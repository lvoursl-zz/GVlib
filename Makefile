all:
	clear
	g++ -std=c++11 main.cpp field.cpp -o gl
	./gl
