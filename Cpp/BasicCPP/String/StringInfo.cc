#include "string"
#include "iostream"

using namespace::std;

int main(int argc, char const *argv[])
{
	string str;
	cout << str << endl;
	cout << str.empty() << endl;
	cout << str.size() << endl;

	string result = str + "haha";
	cout << result << endl;

	cout<< "(str == result) => " << (str == result) << endl;
	return 0;
}