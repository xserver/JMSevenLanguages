/*	
	Declarations 声明
	public protected private 的 member 调用与继承

	某个名为 foo_ 的变量, 其取值函数是 foo(). 还可能需要一个赋值函数 set_foo().
	一般在头文件中把存取函数定义成内联函数.

	每个区段内的声明通常按以下顺序:
		typedefs 和枚举
		常量
		构造函数
		析构函数
		成员函数, 含静态成员函数
		数据成员, 含静态数据成员

	T18：接口尽可能易用不误用。
	T19：class type 设计
	T20：C++ 默认为值传递，所以尽可能使用 const reference 传递，即指针传递。
		（内置类型 int 之类则用值传递，即小东西用值传递）
	T21：方法返回的对象，local stack object 面临释放的问题。heap allocated 则要显式返回 pointer，而不是 reference。
	T22：成员变量必须为 private！get、set 麻烦？不用多讲了！
	T23：考虑封装性。
	T24：？p102
	T25：void std::swap(T& a, T& b) 是 STL 中的函数，交换2个对象的值，前提是支持 copying 函数。
		考虑自定义成员函数 swap，不能吐出异常！
*/

#include "string"

// 禁止使用拷贝构造函数和 operator= 赋值操作的宏，应该类的 private: 中使用
#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
            TypeName(const TypeName&); \
            void operator=(const TypeName&)

class Person
{
public:	
	//	提供2个构造函数
	Person() {
		printf("Person() = %s\n", name.c_str());
	}
	Person(const std::string &name_):name(name_) {
		printf("Person(name) = %s\n", name.c_str());
	}

	void setName(const std::string &name) {}

private:
	std::string name;
	DISALLOW_COPY_AND_ASSIGN(Person);
};

class Schoolbag
{
public:
	Schoolbag(const int color_):color(color_) {
		printf("schoolbag color = %d\n", color);
	}
	int color;
};

class Student : public Person
{
public:
	Student() : Person("Tom"), bad(5) {	}
	virtual ~Student() {}
	//	自定义 copy
	Student *copyMyself(const Student &rhs) {
		return NULL;
	}
private:
	int level;
	Schoolbag bad;
};


int main(int argc, char const *argv[])
{
	Student Student1;

	return 0;
}