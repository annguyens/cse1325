//An Nguyen

#include "cart.h"
#include "item.h"

int main()
{
	Cart cart{"An Nguyen"};
	Item item{"",0};
	std::cout << "Enter product names and price (e.g., \"English peas 0.79\") :\n"; 

	while(std::cin >> item) //CTRL D + ENTER
	{
		cart.add_item(item);
	}
	
	std::cout << "\nRegister Receipt\n\n";
	
	for(auto it = cart.begin(); it!= cart.end(); it++)
	{
		std::cout << *(*it);
	}

	std::string s(25, '-');
	std::cout << s << "\n";
	std::cout << "$   " << std::fixed << std::setprecision(2) << cart.cost() << "  " << "Total Cost\n";
}
