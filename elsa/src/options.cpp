//An Nguyen

#include "options.h"

Options::Options(std::string name, double cost)
: _name{name}, _cost{cost} {}

Options::~Options() {}

double Options::cost() {return _cost;}

Options::Options(std::istream& ist) {
	std::getline(ist,_name);
	ist >> _cost; ist.ignore(32767, '\n');
}

void Options::save(std::ostream& ost) {
	ost << _name << std::endl;
	ost << _cost << std::endl;
}

std::string Options::to_string() const 
{
	std::ostringstream ost;
	ost << "   " << _name << 
	" ($" << std::fixed << std::setprecision(2)<< _cost<< ")";
	return ost.str();
}

Options* Options::clone() {return new Options{*this};}

std::ostream& operator<<(std::ostream& ost, const Options& option) 
{
	ost << option.to_string();
	return ost;
}

