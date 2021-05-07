//An Nguyen

#include "cart.h"

typedef std::vector<Item*>::iterator iterator;
typedef std::vector<Item*>::const_iterator const_iterator;

Cart::Cart(std::string customer) 
: _customer{customer} {}

Cart::Cart(const Cart& cart) 
: _customer{cart._customer} 
{
	for(auto v: cart._items) {_items.push_back(v->clone());}
}

Cart::~Cart() {for(auto v: _items) delete v;}

void Cart::add_item(Item& item) {_items.push_back(item.clone());}

double Cart::cost() 
{
	double cost = 0.00;
	for(auto v: _items) {cost = cost + v->cost();}
	return cost;
}

Cart& Cart::operator=(const Cart& cart) 
{
	if(this!=&cart)
	{
		_customer = cart._customer;
		for(auto v: cart._items) {_items.push_back(v->clone());}
	}
	return *this;
}

iterator Cart::begin() {return _items.begin();}

iterator Cart::end() {return _items.end();}


