#include <vector>
#include <iostream>

class BinaryHeap {

public:
	BinaryHeap(std::vector<int> data);
	BinaryHeap();
	~BinaryHeap();

	std::vector<int> getData() const;
	int getMin() const;
	int getMax() const;
	void insert(int value);
	void sortHeap();

private:
	std::vector<int> data;
	int x0;
	int y0;

};