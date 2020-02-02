//An Nguyen
//ID:1001552004

#ifndef __COLOR_H
#define __COLOR_H

#include <string>

class Color
{
public:
	Color(int red, int green, int blue);
	std::string to_string();
	std::string colorize(std::string text);
	int magnitude();
	int compare(Color& rhs);
private:
	int _red, _green, _blue;
};
#endif
