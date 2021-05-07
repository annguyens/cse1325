//An Nguyen

#ifndef __PRODUCT_H
#define __PRODUCT_H

#include <iomanip>
#include <string>
#include <iostream>

class Product
{
public:
	Product(std::string name, double cost);
	virtual ~Product();
	void set_quantity(int quantity);
	virtual double price() const;
	Product &operator=(const Product &);
	friend std::ostream& operator<<(std::ostream& ost, const Product& product);
protected:
	int _quantity;
	double _cost;
	std::string _name;
};

#endif
