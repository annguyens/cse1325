//An Nguyen
//1001552004

#include "order.h"

Order::Order(Customer& customer)
: _customer{customer} {}

Order::~Order() {}

int Order::add_product(Desktop& desktop) 
{
	_products.push_back(desktop);
	return (_products.size()-1);//index of desktop OR size of order
}

double Order::price() const
{
	double sum = 0;
	for(auto v: _products)
		sum = sum + v.price();
	return sum;
}

std::ostream& operator<<(std::ostream& ost, const Order& order)
{
	ost << "\tCustomer Information: \n" << order._customer << "\n\n"
	<< "\tItems:\n";
	for(auto v: order._products)
		ost << v;
	ost << "\n\t***Total Cost: $" << std::fixed << std::setprecision(2)<<
	order.price() << "***\n";
	return ost;
}
