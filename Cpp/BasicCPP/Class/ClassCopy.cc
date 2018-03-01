// ClassCopy.cc
#include "string"
#include "iostream"
//	标准C++类std::string的Copy-On-Write

//	copy constructor
class ClassCopy
{
public:
	ClassCopy() {
		this->name = "joe";
	}
	// ~ClassCopy();

	//	一个引用对象
	ClassCopy(const ClassCopy& cc) {
		//	拷贝函数
		this->name = cc.name;
	}

	std::string name;
	
};

int main(int argc, char const *argv[])
{
	/* code */
	ClassCopy a;
	std::cout << a.name << std::endl;

	ClassCopy b = a;
	std::cout << b.name << std::endl;
	return 0;
}