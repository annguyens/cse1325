//An Nguyen

#include "customer.h"
#include <sstream>
#include <regex>

Customer::Customer(std::string name, std::string phone, std::string email)
: _name{name}, _phone{phone}, _email{email} {}

Customer::Customer(std::istream& ist) {
	std::getline(ist,_name);
	std::getline(ist,_phone);
	std::getline(ist,_email);
}

void Customer::save(std::ostream& ost) 
{
	ost << _name << std::endl;
	ost << _phone << std::endl;
	ost << _email << std::endl;
}

bool Customer::valid_phone()
{
	 std::string pattern = "xxx-xxx-xxxx" ; 

    if(_phone.size() != pattern.size()) return false ;

    for( int i = 0 ; i < _phone.size() ; i++ )
    {
        if(pattern[i] == 'x') // digit expected
        {
            if( !std::isdigit( _phone[i] ) ) return false ;
        }
        else if( pattern[i] != _phone[i] ) return false ;
    }

    return true ;
}

bool Customer::valid_email()
{
	const std::regex pattern
      ("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
   return std::regex_match(_email, pattern);
}

void Customer::set_phone(std::string s) {_phone=s;}
void Customer::set_email(std::string s) {_email=s;}

std::string Customer::get_name() const {return _name;}
std::string Customer::get_phone() const {return _phone;}
std::string Customer::get_email() const {return _email;}

std::ostream& operator<<(std::ostream& ost, const Customer& customer)
{
	ost << "Name: "<< customer.get_name() << "\n"
	<< "     Email: " << customer.get_email() << "\n"
	<< "     Phone: " << customer.get_phone() << "\n";

	return ost;
}
