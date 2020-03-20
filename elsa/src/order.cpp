//An Nguyen
//1001552004

#include "order.h"

Order::Order(Customer& customer)
: _customer{customer} {}

Order::~Order() {}

int Order::add_product(Desktop& desktop) 
{
_products.push_back(&desktop);
return (_products.size());//index of desktop OR size of order
}

double Order::price() const
{
	double sum = 0;
	for(auto v: _products)
		sum = sum + v->price();
	return sum;
}

std::ostream& operator<<(std::ostream& ost, const Order& order)
{
	ost << order._customer << "\n"
	<< "Order: ";
	for(auto v: order._products)
		ost<< *v;
	ost << "\nTotal Cost: " << std::to_string(order.price()) <<"\n";
	return ost;
}
