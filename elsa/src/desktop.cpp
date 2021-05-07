//An Nguyen


#include "desktop.h"

void Desktop::add_option(Options& option) {
	Options* opt = new Options{option};
	options.push_back(opt);
}

Desktop::Desktop() {}

Desktop::Desktop(std::istream& ist) {
	int size = 0;
	ist >> size;
	ist.ignore(32767,'\n');
	for(int i=0; i<size;i++) 
	{
		Options option{ist};
		add_option(option);
	}
}

void Desktop::save(std::ostream& ost) {
	ost << options.size() << std::endl;
	for (auto v: options)
	{
		v->save(ost);
	}
}

double Desktop::price() const
{
	double sum = 0;
	for(auto v: options) {sum = sum + v->cost();}
	sum = std::ceil(sum*100.0)/100.0;
	return sum;
}

std::ostream& operator<<(std::ostream& ost, const Desktop& desktop)
{
	ost << "Desktop includes:\n";
	for(auto v: desktop.options)
		ost<< "  " << *v <<"\n";
	return ost;
}
