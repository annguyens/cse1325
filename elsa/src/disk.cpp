#include "disk.h"

Disk::Disk(int tb, std::string name, double cost)
: Options(name, cost), _tb{tb} {}

Disk::~Disk() {}

Disk::Disk(std::istream& ist) :Options(ist)
{
	ist >> _tb;
	ist.ignore(32767, '\n');
}

std::string Disk::to_string() const
{
	std::ostringstream ost;
	ost << "  " << _tb << " TB " << _name << " ($" << std::fixed << std::setprecision(2)<< _cost<< ")";
	return ost.str();
}

void Disk::save(std::ostream& ost)
{
	Options::save(ost);
	ost << _tb << std::endl;
}

Options* Disk::clone() {return new Disk{*this};}
