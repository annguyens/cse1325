#ifndef __DISK_H
#define __DISK_H

#include "options.h"

class Disk: public Options
{
public:
	Disk(int tb, std::string name, double cost);
	Disk(std::istream& ist);
	virtual ~Disk();
	std::string to_string() const override;
	void save(std::ostream& ost) override;
	virtual Options* clone();
protected:
	int _tb;
};

#endif
