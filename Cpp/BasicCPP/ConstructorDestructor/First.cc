// Test.cc
#include "iostream"

class Test
{
public:
	Test() {

	}
	~Test() {

	}
	
};

class TestTwo
{
public:
	TestTwo(std::string name) {
		this->myname = name;
	}
	~TestTwo();
	
	void print(void) {
		std::cout << this->myname << std::endl;
	}

	void haha();

private:
	std::string myname;
};


int main(int argc, char const *argv[])
{
	// TestTwo one;
	TestTwo two("haha");
	two.print();
	two.haha();
	return 0;
}

void TestTwo::haha() {
	printf("-.-\n");
}

//	和构造函数一样，没返回值
TestTwo::~TestTwo() {
	printf("~TestTwo\n");
}