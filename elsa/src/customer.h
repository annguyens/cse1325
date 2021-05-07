//An Nguyen

#ifndef __CUSTOMER_H
#define __CUSTOMER_H

#include <string>
#include <iostream>

class Customer
{
public:
	Customer(std::string name, std::string phone, std::string email);
	std::string get_name() const;
	std::string get_email() const;
	std::string get_phone() const;
	bool valid_phone();
	bool valid_email();
	void set_phone(std::string s);
	void set_email(std::string s);
	friend std::ostream& operator<<(std::ostream& ost, const Customer& customer);
	Customer(std::istream& ist);
	void save(std::ostream& ost);
private:
	std::string _name;
	std::string _phone;
	std::string _email;
};

#endif 
