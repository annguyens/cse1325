//An Nguyen

#include "taxfree.h"

Taxfree::Taxfree(std::string name, double cost)
: Product::Product{name,cost} {}

Taxfree::~Taxfree() {}

double Taxfree::price() const 
{
	return (_quantity*_cost);
}

Product* Taxfree::clone() {return new Taxfree{*this};}

