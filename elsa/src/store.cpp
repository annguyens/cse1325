//An Nguyen

#include "store.h"

void Store::add_customer(Customer& customer) {customers.push_back(customer);}

int Store::num_customers() {return customers.size();}

Customer& Store::customer(int index) 
{
	try{
		customers.at(index);
	}
	catch(std::out_of_range& e)
	{
		std::cerr<< "Error: " <<e.what() << "\n";
	}
	return customers.at(index);
}

void Store::add_option(Options& option) {options.push_back(&option);}// Pass by reference

int Store::num_options() {return options.size();}

Options& Store::option(int index) 
{
	try{
		options.at(index);
	}
	catch(std::out_of_range& e)
	{
		std::cerr << "Error: " << e.what() << "\n";
	}
	return *options.at(index);
}

////////////////////////////
///////////////////////////

int Store::new_desktop() 
{
	Desktop desktop;
	desktops.push_back(desktop);
	return (std::distance(desktops.begin(),std::find(desktops.begin(),desktops.end(),desktop)));
}

/*
add_option / add_desktop, which is given the index of the option to add to the desktop at the
provided index / the index of the desktop to add to the order at the provided index. Thus,
these two methods are used to add an existing option / desktop to an existing desktop / order.
*/

void Store::add_option(int option, int desktop)
{
	desktops.insert(desktops.begin()+desktop, options.at(option));
}

int Store::num_desktops() {return desktops.size();}

Desktop& Store::desktop(int index) {return desktops.at(index);}

int Store::new_order(int customer) 
{
	Order order{customer};
	orders.push_back(order);
	return (std::distance(orders.begin(),std::find(orders.begin(),orders.end(),order)));
}

void Store::add_desktop(int desktop, int order) 
{
	orders.insert(orders.begin()+order, desktops.at(desktop));
}

int Store::num_orders() {return orders.size();}

Order& Store::order(int index) {return orders.at(index);}
