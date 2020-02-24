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
	double Total = 0;
	Taxfree milk{"Milk", 2.85};
	Taxfree cookies{"Cookies", 3.99};
	Taxfree cheese{"Cheese", 0.99};
	Taxed iceCream{"Ice Cream", 4.95};
	Taxed poptarts{"Poptarts", 3.49};
	Taxed fruitSnacks{"Fruit Snacks", 1.29};
	
	Product *products[]{&milk, &cookies, &cheese, &iceCream, &poptarts, &fruitSnacks};	
	
	while(true)
	{

		std::cout << "========================\n"
			  << "  Welcome to the Store  \n"
			  << "========================\n" << std::endl;	
		
		for(i=0; i<std::size(products); i++)
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
				Total = Total + cart[i]->price();
			}
			std::cout << "Total price: $" << Total;
		}
	
		std::cout << "\nEnter quantity (0 to exit) and product index: ";
		std::cin >> userQuantity;
		
		if(userQuantity==0) {break;}
		else {std::cin>>index;}

		try
		{
			if(userQuantity<0 || index <0 || index>std::size(products))
			{
				throw "Bad values entered";
			}
		}
		catch(const std::string &str)
		{
			std::cerr << "Error: " << str <<"\n";
			continue;
		}		

		Product* userProduct= new Product{*products[index]};
		userProduct->set_quantity(userQuantity);
		cart.push_back(userProduct);

		std::cout << "\n";
		
	}
	

}
