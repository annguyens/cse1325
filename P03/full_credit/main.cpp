#include "color.h"
#include <iostream>

int main() {
	Color purple{100,0,110}, gold{212,180,55}, orange{255,165,0};
	Color reset{};
	
    	std::cout << purple << "Purple " << gold << "Gold " << orange << "Orange " <<reset << std::endl;

	Color color{0,0,0};
	std::cout << "\nEnter color as (red, green, blue): ";
	std::cin >> color;
	std::cout << color << color.to_string() << std::endl;
}
