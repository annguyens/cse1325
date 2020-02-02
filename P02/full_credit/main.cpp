#include "color.h"
#include <iostream>

int main() {
    Color color1{100,0,110}, color2{212,180,55}, color3{255,165,0};
	
    std::cout << color1.colorize("Purple\n") << color2.colorize("Gold\n") << color3.colorize("Orange\n") << std::endl;

	int r{0}, g{0}, b{0};
	std::cout << "Enter red, green, and blue ints (separated by spaces): ";
	std::cin >> r >> g >> b;
	Color user_input{r,g,b};
	std::cout << user_input.colorize(user_input.to_string()) << std::endl;
}
