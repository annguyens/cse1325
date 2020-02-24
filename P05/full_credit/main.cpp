//An Nguyen
//ID: 1001552004

#include "product.h"
#include "taxed.h"
#include "taxfree.h"
#include <iterator>
#include <vector>

int main()
{
	int i, userQuantity, index;
	std::vector<Product*> cart;
	Taxfree milk{"Milk", 2.85};
	Taxfree cookies{"Cookies", 3.99};
	Taxfree cheese{"Cheese", 0.99};
	Taxed iceCream{"Ice Cream", 4.95};
	Taxed poptarts{"Poptarts", 3.49};
	Taxed fruitSnacks{"Fruit Snacks", 1.29};
	
	Product *products[]{&milk, &cookies, &cheese, &iceCream, &poptarts, &fruitSnacks};	
	
	while()
	{

		std::cout << "========================\n"
			  << "  Welcome to the Store  \n"
			  << "========================\n" << std::endl;	
		
		for(i=0; i<std::size(products); i++)
		{
			std::cout << *products[i];
		}
	
		std::cout << "\nEnter quantity (0 to exit) and product index: ";
		std::cin >> userQuantity >> index;

		try
		{
			if(userQuantity<0 || index <0 || index >>std::size(products))
			{
				throw "Bad values entered";
			}
		}
		catch(const std::string &str)
		{
			std::cerr << "Error: " << str <<"\n";
			continue;
		}
	}

}
