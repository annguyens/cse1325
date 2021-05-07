// An Nguyen

#include <iostream>
#include <string>
#include "color.h"

Color::Color(int red, int green, int blue)
: _red{red}, _green{green}, _blue{blue} {}

std::string Color::to_string()
{
	std::string format = "(" + std::to_string(_red) + "," +std::to_string(_green) + "," + std::to_string(_blue) + ":"+ std::to_string(this->magnitude()) +")";
	return format;
}

std::string Color::colorize(std::string text)
{
	std::string disp = "\033[38;2;" + std::to_string(_red) + ";" + std::to_string(_green) + ";" +std::to_string(_blue) + ";177m" + text + " " + std::to_string(this->magnitude()) + " " + "\033[0m";
	return disp;
}

int Color::magnitude()
{
	return (.21*_red)+(.72*_green)+(.07*_blue);
}

int Color::compare(Color& rhs)
{
	if(this->magnitude() > rhs.magnitude())
		return 1;
	else if (this->magnitude() == rhs.magnitude())
		return 0;
	else
		return -1;
}
