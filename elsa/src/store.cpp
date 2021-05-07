//An Nguyen

#include "store.h"
#include "ram.h"

void Store::add_customer(Customer& customer) {customers.push_back(customer);}

Store::Store() {}

Store::Store(std::istream& ist) {
	int csize =0;
	ist >> csize;
	ist.ignore(32767,'\n');
	for(int i=0; i<csize; i++) 
	{
		Customer customer{ist};
		add_customer(customer);
	}

	try{
		if(!ist.good()) throw std::runtime_error{"Error writing file\n"};
	}catch (std::exception& e) {
		std::cerr << e.what();	
	}

	int opt_size = 0;
	ist >> opt_size;
	ist.ignore(32767,'\n');
	for(int i=0; i<opt_size; i++) 
	{
		Options option{ist};
		add_option(option);
	}

	try{
		if(!ist.good()) throw std::runtime_error{"Error writing file\n"};
	}catch (std::exception& e) {
		std::cerr << e.what();	
	}
	int desk_size = 0;
	ist >> desk_size;
	ist.ignore(32767,'\n');
	for(int i=0; i<desk_size; i++) 
	{
		Desktop desktop{ist};
		desktops.push_back(desktop);
	}

	try{
		if(!ist.good()) throw std::runtime_error{"Error writing file\n"};
	}catch (std::exception& e) {
		std::cerr << e.what();	
	}
	int order_num = 0;
	ist >> order_num;
	ist.ignore(32767,'\n');
	for(int i=0; i<order_num; i++) 
	{
		Order order{ist};
		orders.push_back(order);
	}

	try{
	if(!ist.good()) throw std::runtime_error{"Error writing file\n"};
	}
	catch (std::exception& e){
		std::cerr << e.what();	
	}
}

void Store::save(std::ostream& ost) {
	//Saving Customers...
	ost << customers.size() << std::endl;
	for(auto v: customers) {v.save(ost);}
	try{
		if(!ost.good()) throw std::runtime_error{"Error writing file\n"};
	}catch (std::exception& e) {
		std::cerr << e.what();	
	}

	//Saving Options...
	ost << num_options() << std::endl;
	for(auto v: options) {v->save(ost);}
		try{
		if(!ost.good()) throw std::runtime_error{"Error writing file\n"};
	}catch (std::exception& e) {
		std::cerr << e.what();	
	}

	//Saving Desktops...
	ost << num_desktops() << std::endl;
	for(auto v: desktops) {v.save(ost);}
	try{
		if(!ost.good()) throw std::runtime_error{"Error writing file\n"};
	}catch (std::exception& e) {
		std::cerr << e.what();	
	}

	//Saving Orders...
	ost << num_orders() << std::endl;
	for(auto v: orders) {v.save(ost);}

	try{
		if(!ost.good()) throw std::runtime_error{"Error writing file\n"};
	}catch (std::exception& e) {
		std::cerr << e.what();	
	}
}


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

void Store::add_option(Options& option) {options.push_back(option.clone());}

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

int Store::new_desktop() 
{
	Desktop desktop;
	desktops.push_back(desktop);
	return desktops.size()-1;
}

void Store::add_option(int option, int desktop)
{	(desktops.at(desktop)).add_option(*options.at(option));
}

int Store::num_desktops() {return desktops.size();}

Desktop& Store::desktop(int index) {return desktops.at(index);}

int Store::new_order(int customer) 
{
	Order order{customers[customer]};
	orders.push_back(order);
	return orders.size()-1;
}

void Store::add_desktop(int desktop, int order) 
{
	int x = (orders.at(order)).add_product(desktops.at(desktop));
}

int Store::num_orders() {return orders.size();}

Order& Store::order(int index) {return orders.at(index);}
