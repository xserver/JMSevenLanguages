#include <string>
#include <iostream>

using std::string;
// using namespace::std;


namespace myRoom {
	int num = 10;
}

namespace yourRoom {
	int num = 20;
}

// namespace 避免污染，一般不使用
int main(int argc, char const *argv[])
{

	myRoom::num = 2;
	yourRoom::num = 3;


	string str = "string 不用 std::";

	std::cout << str << std::endl;
	/* code */
	return 0;
}