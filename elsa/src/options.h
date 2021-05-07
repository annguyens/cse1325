// An Nguyen

#ifndef __OPTIONS_H
#define __OPTIONS_H

#include <string>
#include <iostream>
#include <iomanip>

class Options
{
public:
	Options(std::string name, double cost);
	Options(std::istream& ist);
	virtual ~Options();
	double cost();
	virtual std::string to_string() const;
	virtual Options* clone();
	friend std::ostream& operator<<(std::ostream& ost, const Options& option);
	virtual void save(std::ostream& ost);
protected:
	std::string _name;
	double _cost;
};

#endif 
