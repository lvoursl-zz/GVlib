#ifndef SHAPE_H_
#define SHAPE_H_

#include <vector>

class Shape {

public:
	Shape();
	~Shape();

	int getId() const;
	void setId(int id);

private:
	int id;

};


#endif