#include <iostream>
#include "ArithmeticTree.h"

int main()
{
	ArithmeticTree tree("2/2+4/4");
	std::cout<<tree.calculate();
	std::cout<<std::endl;
	ArithmeticTree tree2("2+2+4*4");
	std::cout << tree2.calculate();
	std::cout << std::endl;
	return 0;
}


