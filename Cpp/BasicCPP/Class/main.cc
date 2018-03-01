#include "Fruit.h"
#include <iostream>

// g++ main.cc Fruit.cc -o main
int main(int argc, char const *argv[])
{
	Fruit fruit;
	std::cout << fruit.price() << std::endl;

	fruit.printPrice();
	return 0;
}