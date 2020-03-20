//An Nguyen
//1001552004

#ifndef __DESKTOP_H
#define __DESKTOP_H

#include "options.h"
#include <vector>
#include <iostream>

class Desktop
{
public:
	void add_option(Options& option);
	double price() const;
	friend std::ostream& operator<<(std::ostream& ost, const Desktop& desktop);
private:
	std::vector<Options*> options;
};

#endif
