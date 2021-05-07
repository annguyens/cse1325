//An Nguyen

#ifndef __ITEM_H
#define __ITEM_H

#include <string>
#include <iomanip>
#include <iostream>


class Item{
public:
	Item(std::string name, double price);
	double cost() const;
	friend std::ostream& operator<<(std::ostream& ost, const Item& item);
	friend std::istream& operator>>(std::istream& ist, Item& item);
	Item* clone();	
private:
	std::string _name;
	double _price;
};

#endif
