//An Nguyen

#include "customer.h"

Customer::Customer(std::string name, std::string phone, std::string email)
: _name{name}, _phone{phone}, _email{email} {}

std::ostream& operator<<(std::ostream& ost, const Customer& customer)
{
	ost << "Name: " << customer._name << ","
	<< " Phone: " << customer._phone << ","
	<< " Email: " << customer._email;

	return ost;
}
