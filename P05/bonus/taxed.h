//An Nguyen


#ifndef __TAXED_H
#define __TAXED_H

#include <string>
#include <iostream>
#include "product.h"

class Taxed: public Product
{
public:
	Taxed(std::string name, double cost);
	virtual ~Taxed();
	static void set_tax_rate(double sales_tax);
	virtual double price() const override;
private:
	static double _tax;
};

#endif

