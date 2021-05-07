#include "ram.h"

Ram::Ram(std::string name, double cost, int gb)
: Options(name,cost), _gb{gb} { }

Ram::~Ram() {}

Ram::Ram(std::istream& ist) : Options(ist)
{
	ist >> _gb; 
	ist.ignore(32767, '\n');
}

std::string Ram::to_string() const
{
	std::ostringstream ost;
	ost << "  " << _gb <<" GB " << _name << 
	" ($" << std::fixed << std::setprecision(2)<< _cost<< ")";
	return ost.str();
}

void Ram::save(std::ostream& ost) 
{
	ost << "RAM\n";
	Options::save(ost);
	ost << _gb << std::endl;
}

Options* Ram::clone() {return new Ram{*this};}
