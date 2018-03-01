// #include <stdio.h>
// #include <signal.h>
// #include <string.h>
#include <string>
#include <iostream>

int main(int argc, char const *argv[])
{

	std::string message = std::string("c++ string");
	printf("%s\n", message.c_str());

	message = "hello string";
	std::cout << message << std::endl;


	char ch = 'c';  
    std::string str4(5, ch);
    std::cout << str4 << std::endl; 

	return 0;
}