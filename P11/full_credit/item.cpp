//An Nguyen

#include "item.h"

Item::Item(std::string name, double price)
: _name{name}, _price{price} {}

double Item::cost() const {return _price;}

std::ostream& operator<<(std::ostream& ost, const Item& item)
{
	ost << "$   " << std::fixed << std::setprecision(2) << item.cost() << "  " << item._name << "\n";
	return ost;
}

std::istream& operator>>(std::istream& ist, Item& item)
{
	std::string s="";
	std::string price_string="";
	try{
		getline(std::cin, s);
		auto const pos = s.find_last_of(' ');
		price_string = s.substr(pos+1);
		s = s.substr(0, pos);
		double price = std::stod(price_string);
		item._name = s;
		item._price = price;
	}catch(...)
	{
		if(s!=""&&price_string!=""){ 	
		std::cerr << "Invalid Price: '" << s << "' ==> '" << price_string << "'\n\n";
		}
	}
	return ist;
}

Item* Item::clone() {return new Item{*this};}
