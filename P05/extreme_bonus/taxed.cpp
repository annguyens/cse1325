//An Nguyen

#include "taxed.h"

double Taxed::_tax;

Taxed::Taxed(std::string name, double cost)
: Product::Product{name,cost} {}

Taxed::~Taxed() {}

void Taxed::set_tax_rate(double sales_tax)
{
	Taxed::_tax = sales_tax;
}

double Taxed::price() const 
{
	return (_quantity*_cost*(1+Taxed::_tax) );
}

Product *Taxed::clone() {return new Taxed(*this);}

