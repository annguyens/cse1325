//An Nguyen

#include "coin.h"
#include "logger.h"
#include <iostream>
#include <string>

Coin::Coin(Coin_size size, Year year)
: _size{size}, _year{year}, _notes{NULL} {LOG("Coin::Coin")}

Coin::Coin(const Coin& coin)
: _size{coin._size}, _year{coin._year}, _notes{new std::string} {LOG("Coin::Coin copy constructor")}

Coin& Coin::operator =(const Coin& coin)
{
	this->_size = coin._size;
	this->_year = coin._year;
	this->_notes = new std::string;
	LOG("Coin::operator=");
	return *this;
}

Coin::~Coin()
{
	delete _notes;
	LOG("Coin::~Coin")
}

void Coin::add_note(std::string s)
{
	if(!_notes) 
	{
		_notes = new std::string;
		*_notes = s;
	}
	else
	{	
		_notes->append(s);
	}
}

std::ostream& operator<<(std::ostream& ost, const Coin& coin)
{
	std::string s;
	switch(coin._size)
	{
		case Coin_size::PENNY:
			s = "penny";
			break;
		case Coin_size::NICKEL:
			s = "nickel";
			break;
		case Coin_size::DIME:
			s="dime";
			break;
		case Coin_size::QUARTER:
			s="quarter";
			break;	
		default:
			throw std::runtime_error{"Bad coin value!\n"};
			break;
	}
	ost << coin._year << " "<< s << "\n" << *coin._notes;
	return ost;
}
