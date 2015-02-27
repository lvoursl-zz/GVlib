#include "binary_heap.h"

BinaryHeap::BinaryHeap(std::vector<int> data) {  
	this->data.resize(data.size() + 1);
	for (int i = 1; i < data.size() + 1; i++) {
		this->data[i] = data[i - 1];
	}
}

BinaryHeap::BinaryHeap() { }


BinaryHeap::~BinaryHeap() { }

std::vector<int> BinaryHeap::getData() const {
	return data;
}

int BinaryHeap::getMin() const {
	return data[1];
}

void BinaryHeap::insert(int value) {
	data.push_back(value);
	sortHeap();
}

void BinaryHeap::sortHeap() {
	for (int i = 1; i < data.size() + 1; i++) {
		if ((i * 2 < data.size()) && (i * 2 + 1 < data.size())) {
			if (data[i] > data[i * 2]) std::swap(data[i], data[i * 2]);
			if (data[i] > data[i * 2 + 1]) std::swap(data[i], data[i * 2 + 1]);
		}
	}

	for (int i = data.size() - 1; i > 0; i--) {
		if (data[i] < data[i / 2]) std::swap(data[i], data[i / 2]);		
	}

	/*for (int i = 1; i < data.size(); i++) {
		std::cout << data[i] << " ";
	}*/

}