//An Nguyen


#ifndef __DESKTOP_H
#define __DESKTOP_H

#include "options.h"
#include <vector>
#include <iostream>
#include <cmath>

class Desktop
{
public:
	Desktop();
	void add_option(Options& option);
	double price() const;
	friend std::ostream& operator<<(std::ostream& ost, const Desktop& desktop);
	Desktop(std::istream& ist);
	void save(std::ostream& ost);
private:
	std::vector<Options*> options;
};

#endif
