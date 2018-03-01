// templateFunction.cc
//	函数模版

#include <iostream>

template <typename T>
T abs(T x) {
	return x < 0 ? -x : x;
}

int main(int argc, char const *argv[])
{
	std::cout << abs(-2.2) << std::endl;
	return 0;
}