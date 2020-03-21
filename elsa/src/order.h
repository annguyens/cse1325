//An Nguyen
//1001552004

#ifndef __ORDER_H
#define __ORDER_H

#include "customer.h"
#include "desktop.h"
#include <vector>
#include <iostream>
#include <iomanip>

class Order
{
public:
	Order(Customer& customer);
	~Order();
	int add_product(Desktop& desktop);
	double price() const;
	friend std::ostream& operator<<(std::ostream& ost, const Order& order);
private:
	Customer& _customer;
	std::vector<Desktop> _products;
};

#endif
