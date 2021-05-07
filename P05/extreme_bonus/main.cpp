//An Nguyen


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

	Taxed::set_tax_rate(0.0825);
	std::vector<Product*> product{&milk, &cookies, &cheese, &iceCream, &poptarts, &fruitSnacks};
	int count = sizeof(product)/sizeof(product[i]);
	
	while(true)
	{
		double Total = 0;

		std::cout << "========================\n"
			  << "  Welcome to the Store  \n"
			  << "========================\n" << std::endl;	
		
		for(i=0; i<6; i++)
		{
			std::cout << std::to_string(i) << ") " << *product[i];
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
			if(userQuantity<0 || index <0 || index>5)
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
		
		Product *userProduct = product[index]->clone();
		userProduct->set_quantity(userQuantity);
		cart.push_back(userProduct);

		std::cout << "\n";
		
	}
		for(i=0; i<cart.size();i++)
		{
				delete cart[i];
		}

}
