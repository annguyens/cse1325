//An Nguyen

#ifndef __COLOR_H
#define __COLOR_H

#include <string>

class Color
{
public:
	Color(int red, int green, int blue);
	Color();
	std::string to_string();
	bool operator<(Color& rhs);
	bool operator<=(Color&rhs);
	bool operator==(Color &rhs);
	bool operator!=(Color &rhs);
	bool operator>=(Color &rhs);
	bool operator>(Color &rhs);
	friend std::ostream& operator<<(std::ostream &ost, const Color&color);
	int magnitude();
private:
	bool compare(Color& rhs);
	int _red, _green, _blue;
	int _reset;
};
#endif
