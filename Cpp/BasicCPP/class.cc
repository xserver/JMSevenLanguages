#include <iostream>

class Fruit
{
public:
	// Fruit();
	// ~Fruit();
	
	int price() {
		return liveTime - 2;
	}

protected:

private:
	int liveTime = 10;
	// int liveTime;
};

int main(int argc, char const *argv[])
{

	Fruit fruit;
	std::cout << fruit.price() << std::endl;
	return 0;
}

