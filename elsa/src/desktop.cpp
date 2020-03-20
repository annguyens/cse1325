//An Nguyen
//1001552004

#include "desktop.h"

void Desktop::add_option(Options& option) 
{
	//Options* opt = new Options{option};
	options.push_back(&option);
}

double Desktop::price() const
{
	double sum = 0;
	for(auto v: options)
		sum = sum + v->cost();
	return sum;
}

std::ostream& operator<<(std::ostream& ost, const Desktop& desktop)
{
	ost << "Options for this Desktop:\n";
	for(auto v: desktop.options)
		ost<< *v <<"\n";
	ost<< "Cost: " << std::to_string(desktop.price()) <<"\n";
	return ost;
}
