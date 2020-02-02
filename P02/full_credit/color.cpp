// An Nguyen

#include <iostream>
#include <string>
#include "color.h"


Color::Color(int red, int green, int blue)
: _red{red}, _green{green}, _blue{blue} {}

std::string Color::to_string()
{
	std::string format = '(' + std::to_string(_red) + ',' + 		  std::to_string(_green) + ',' + std::to_string(_blue) + ')';
	return format;
}

std::string Color::colorize(std::string text)
{
	std::string disp =  "\033[38;2;" + std::to_string(_red) + ';' + std::to_string(_green) + ';' +std::to_string(_blue) + "177m" + text + "\033[0m";
	return disp;
}
