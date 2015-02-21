#ifndef SHAPE_H_
#define SHAPE_H_

#include <vector>
#include <map>
#include <string>

class Shape {

public:
	Shape();
	~Shape();

	int getId() const;
	void setId(int id);

	std::string getType() const;
	std::map<std::string, int> getCoordinates() const;

protected:
	int id;
	std::string type;
	std::map<std::string, int> coordinates;

};


#endif