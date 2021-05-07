//An Nguyen

#ifndef __CART_H
#define __CART_H

#include <string>
#include <iterator>
#include <vector>
#include <iomanip>
#include "item.h"

class Cart
{
public:
	Cart(std::string customer);
	Cart(const Cart& cart);
	~Cart();
	void add_item(Item& item);
	double cost();
	typedef std::vector<Item*>::iterator iterator;
	typedef std::vector<Item*>::const_iterator const_iterator;
	iterator begin();
	iterator end();
	Cart& operator=(const Cart& cart);
private:
	std::string _customer;
	std::vector<Item*> _items;
};

#endif
