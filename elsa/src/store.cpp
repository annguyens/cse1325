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

void Store::add_option(int option, int desktop)
{
	(desktops.at(desktop)).add_option(*options.at(option));
}

int Store::num_desktops() {return desktops.size();}

Desktop& Store::desktop(int index) {return desktops.at(index);}

int Store::new_order(int customer) 
{
	Order order{customers[customer]};
	orders.push_back(order);
	return (std::distance(orders.begin(),std::find(orders.begin(),orders.end(),order)));
}

void Store::add_desktop(int desktop, int order) 
{
	int x = (orders.at(order)).add_product(desktops.at(desktop));
}

int Store::num_orders() {return orders.size();}

Order& Store::order(int index) {return orders.at(index);}
