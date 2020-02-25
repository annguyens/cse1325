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
	std::vector<Taxed> TaxedCart;
	std::vector<Taxfree> TaxfreeCart;
	Taxfree milk{"Milk", 2.85};
	Taxfree cookies{"Cookies", 3.99};
	Taxfree cheese{"Cheese", 0.99};
	Taxed iceCream{"Ice Cream", 4.95};
	Taxed poptarts{"Poptarts", 3.49};
	Taxed fruitSnacks{"Fruit Snacks", 1.29};

	Taxed::set_tax_rate(0.0825);
	
	while(true)
	{
		double Total = 0;
		std::cout << "========================\n"
			  << "  Welcome to the Store  \n"
			  << "========================\n" << std::endl;	
		
		std::cout <<"0) " << milk;
		std::cout <<"1) " << cookies;
		std::cout <<"2) " << cheese;
		std::cout <<"3) " << iceCream;
		std::cout <<"4) " << poptarts;
		std::cout <<"5) " << fruitSnacks;
				
		if(!TaxfreeCart.empty()||!TaxedCart.empty())
		{
			std::cout << "\nCurent Order\n"
				  << "------------\n";

			for(i=0; i<TaxedCart.size();i++)
			{
				std::cout << TaxedCart[i];
				Total+=TaxedCart[i].price();
			}
			for(i=0; i<TaxfreeCart.size();i++)
			{
				std::cout << TaxfreeCart[i];
				Total+=TaxfreeCart[i].price();
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
		
		switch(index)
		{
			case 0:
				{
				Taxfree copy{milk};
				copy.set_quantity(userQuantity);
				TaxfreeCart.push_back(copy);
				break;
				}
			case 1:
				{
				Taxfree copy{cookies};
				copy.set_quantity(userQuantity);
				TaxfreeCart.push_back(copy);
				break;
				}
			case 2:
				{
				Taxfree copy{cheese};
				copy.set_quantity(userQuantity);
				TaxfreeCart.push_back(copy);
				break;
				}
			case 3:
				{
				Taxed copy{iceCream};
				copy.set_quantity(userQuantity);
				TaxedCart.push_back(copy);
				break;
				}
			case 4:
				{
				Taxed copy{poptarts};
				copy.set_quantity(userQuantity);
				TaxedCart.push_back(copy);
				break;
				}
			case 5:
				{
				Taxed copy{fruitSnacks};
				copy.set_quantity(userQuantity);
				TaxedCart.push_back(copy);
				break;
				}
		}

		std::cout << "\n";
	}
	

}
