// An Nguyen
// 1001552004

#ifndef __OPTIONS_H
#define __OPTIONS_H

#include <string>
#include <iostream>
#include <iomanip>

class Options
{
public:
	Options(std::string name, double cost);
	~Options();
	double cost();
	std::string to_string() const;
	friend std::ostream& operator<<(std::ostream& ost, const Options& option);
protected:
	std::string _name;
	double _cost;
};

#endif 
