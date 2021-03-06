//An Nguyen

#ifndef __TAXFREE_H
#define __TAXFREE_H

#include <string>
#include <iostream>
#include "product.h"

class Taxfree: public Product
{
public:
	Taxfree(std::string name, double cost);
	virtual ~Taxfree();
	virtual double price() const override;
};

#endif
