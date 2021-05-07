//An Nguyen


#include "order.h"

Order::Order(Customer& customer)
: _customer{&customer} {}

Order::~Order() {}

Order::Order(std::istream& ist) {
	_customer = new Customer{ist};
	int products_size;
	ist >> products_size;
	ist.ignore(32767,'\n');
	for(int i=0; i<products_size; i++){
		Desktop desktop{ist}; 
		_products.push_back(desktop);
	}
}

void Order::save(std::ostream& ost) {
	_customer->save(ost);
	ost << _products.size() <<std::endl;
	for(auto v: _products) {v.save(ost);}
}

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
	ost << "<span size='medium' weight='bold'>Customer Information: </span>\n" 
	<< "     Name: "<< (order._customer)->get_name() << "\n"
	<< "     Email: " <<(order._customer)->get_email() << "\n"
	<< "     Phone: " <<(order._customer)->get_phone() << "\n"
	<< "\n"
	<< "<span size='medium' weight='bold'>    Order Details:</span>\n";
	for(auto v: order._products)
		ost << "   - " << v;
	ost << "\n<span size='medium' weight='bold'>   Order Total: $" << std::fixed << std::setprecision(2)<<
	order.price() << "</span>\n\n";
	return ost;
}
