//An Nguyen
//ID:1001552004

#include <iostream>
#include <string>

int main()
{
	std::string name = getenv("USER");
	std::cout << "Hello, " << name << "!\n";
}
