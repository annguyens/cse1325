//An Nguyen
//1001552004

#include "options.h"

Options::Options(std::string name, double cost)
: _name{name}, _cost{cost} {}

Options::~Options() {}

double Options::cost() {return _cost;}

std::string Options::to_string() const {return std::to_string(_cost);}

std::ostream& operator<<(std::ostream& ost, const Options& option)
{
	ost << "Name: " << option._name <<"\n"
	<< "Cost: " << option.to_string() <<"\n";
	return ost;
}

