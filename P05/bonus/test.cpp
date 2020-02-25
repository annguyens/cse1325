//An Nguyen

#include "product.h"
#include "taxed.h"
#include "taxfree.h"
#include <sstream>

int main()
{
	Taxfree bread{"Bread", 2.50};
	std::stringstream test,test2,test3,test4;
	test.str("Bread ($2.50)\n");
	test2 << bread;
	if(test.str()!= test2.str()){std::cerr << "FAIL\n";}

	bread.set_quantity(2);
	if(bread.price() != 5) std::cerr << "FAIL\n";

	Taxed::set_tax_rate(0.0825);
	Taxed poptarts{"Poptarts", 0.99};
	test3.str("Poptarts ($0.99)\n");
	test4 << poptarts;
	if(test3.str()!= test4.str()){std::cerr << "FAIL!!!\n";}//

	poptarts.set_quantity(3);
	if(poptarts.price() != (3*0.99*1.0825)) std::cerr << "FAIL!!!!\n";//
}
