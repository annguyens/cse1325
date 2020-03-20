//An Nguyen

#include "customer.h"

Customer::Customer(std::string name, std::string phone, std::string email)
: _name{name}, _phone{phone}, _email{email} {}

std::ostream& operator<<(std::ostream& ost, const Customer& customer)
{
	ost << "Name: " << customer._name << "\n"
	<< "Phone: " << customer._phone <<"\n"
	<< "Email: " << customer._email <<"\n";
	return ost;
}
