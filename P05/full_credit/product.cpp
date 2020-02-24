//An Nguyen
//1001552004

#include "product.h"

Product::Product(std::string name, double cost=0.0)
: _name{name}, _cost{cost}, _quantity{0}
{
	if(cost<0) throw std::runtime_error("cost: Cost can't be negtive value!");
}

Product::~Product() {}

void Product::set_quantity(int quantity) {_quantity=quantity;}

double Product::price() const {}

std::ostream& operator<<(std::ostream& ost, const Product& product)
{
	if(product._quantity ==0)
	{
		ost << product._name << " ($" << std::setprecision(2) << std::fixed << 			product._cost <<")\n";
	}
	else
	{
		ost << product._name << " (" << product._quantity << " @ $" 			<< std::setprecision(2) << std::fixed << product._cost <<")\n";
	}
	return ost;
}



