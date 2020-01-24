//An Nguyen
//ID:1001552004

#include <iostream>
#include <string>

int main()
{
	std::string name;
	std::cout << "What is your name? ";
	getline(std::cin, name);
	std::cout << "Hello, " << name <<"!\n" << std::endl;
	return 0;
}
