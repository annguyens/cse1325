// An Nguyen

#include <iostream>
#include <string>
#include "color.h"

Color::Color(int red, int green, int blue)
: _red{red}, _green{green}, _blue{blue} {}

Color::Color() : _reset(true) {}


bool Color::compare(Color& rhs)
{
	if(this->magnitude() > rhs.magnitude())
		return true;
	else if (this->magnitude() == rhs.magnitude())
		return true;
	else
		return false;
}

std::string Color::to_string()
{
	std::string format = "(" + std::to_string(_red) + "," +std::to_string(_green) + "," + std::to_string(_blue) +")";
	return format;
}

int Color::magnitude()
{
	return static_cast<int>((.21*_red)+(.72*_green)+(.07*_blue));
}

std::ostream& operator<<(std::ostream& ost, const Color& color)
{
	ost << "\033[38;2;" << std::to_string(color._red) << ";" << std::to_string(color._green) << ";" << std::to_string(color._blue) << ";177m";
	
	return ost;
}

bool Color::operator<(Color& rhs) {return this->compare(rhs);}

bool Color::operator<=(Color& rhs) {return this->compare(rhs);}

bool Color::operator==(Color& rhs) {return this->compare(rhs);}

bool Color::operator!=(Color& rhs) {return !(this->compare(rhs));}

bool Color::operator>=(Color& rhs) {return this->compare(rhs);}

bool Color::operator>(Color& rhs) {return this->compare(rhs);}

