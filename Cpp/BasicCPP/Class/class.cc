#include <iostream>
using std::string;
class Fruit
{
public:
	// Fruit();
	// ~Fruit();
	
	int price() {
		return liveTime - 2;
	}

	string xx() {
		return "aaaaaa";
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
	std::cout << fruit.xx() << std::endl;
	return 0;
}

