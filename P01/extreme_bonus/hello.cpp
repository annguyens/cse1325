//An Nguyen

#include <iostream>
#include <string>

int main()
{
	std::string name = getenv("USER");
	std::cout << "Hello, " << name << "!\n";
}
