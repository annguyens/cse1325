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

	Taxfree milk1{"Milk", 2.85};
	Taxfree cookies1{"Cookies", 3.99};
	Taxfree cheese1{"Cheese", 0.99};
	Taxed iceCream1{"Ice Cream", 4.95};
	Taxed poptarts1{"Poptarts", 3.49};
	Taxed fruitSnacks1{"Fruit Snacks", 1.29};

	Taxed::set_tax_rate(0.0825);
	
	Product *product[]{&milk, &cookies, &cheese, &iceCream, &poptarts, &fruitSnacks};
	Product *products[]{&milk1, &cookies1, &cheese1, &iceCream1, &poptarts1, &fruitSnacks1};
	int count=(sizeof(products)/sizeof(products[i]));
	
	while(true)
	{
		double Total = 0;

		std::cout << "========================\n"
			  << "  Welcome to the Store  \n"
			  << "========================\n" << std::endl;	
		
		for(i=0; i<(sizeof(products)/sizeof(products[i])); i++)
		{
			std::cout << std::to_string(i) << ") " << *products[i];
		}
				
		if(!cart.empty())
		{
			std::cout << "\nCurent Order\n"
				  << "------------\n";

			for(i=0; i<cart.size();i++)
			{
				std::cout << *cart[i];
				Total+=cart[i]->price();
			}
			std::cout << "Total price: $" << Total;
		}
	
		std::cout << "\nEnter quantity (0 to exit) and product index: ";
		std::cin >> userQuantity;
		
		if(userQuantity==0) {break;}
		else {std::cin>>index;}

		try
		{
			if(userQuantity<0 || index <0 || index>count)
			{
				throw std::runtime_error{"Bad Values!\n"};
			}
		}
		catch(std::runtime_error& e)
		{
			std::cout <<"\n";
			std::cerr << "Error: " << e.what() <<"\n";
			continue;
		}		
		
		product[index]->set_quantity(userQuantity);
		cart.push_back(product[index]);

		std::cout << "\n";
	}
	

}
