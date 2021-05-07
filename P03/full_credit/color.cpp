// An Nguyen

#include <iostream>
#include <string>
#include "color.h"

Color::Color(int red, int green, int blue)//boolean value too
: _red{red}, _green{green}, _blue{blue}, _reset{false} 
{
	if((red<0||red>255) && (blue<0||blue>255) && (green<0||green>255))
	{
		std::cerr << "Bad colors";
	}
}

Color::Color()
: _reset{true} {}

std::string Color::to_string()
{
	std::string format = "(" + std::to_string(_red) + "," +std::to_string(_green) + "," + std::to_string(_blue) + ")";
	return format;
}

std::ostream& operator<<(std::ostream& ost, const Color& color)
{
	if(color._reset)
	{
		ost << "\033[0m";
	}
	else
	{
		ost << "\033[38;2;" << std::to_string(color._red) << ";" << 			std::to_string(color._green) << ";" << 					std::to_string(color._blue) << ";177m";
	}
	
	return ost;
}

std::istream& operator>>(std::istream& ist, Color &color)
{	
	ist.ignore(1, '(');
	ist >> color._red;
	ist.ignore(1, ',');
	ist >> color._green;
	ist.ignore(1, ',');
	ist >> color._blue;
	ist.ignore(1, ')');

	return ist;
}

