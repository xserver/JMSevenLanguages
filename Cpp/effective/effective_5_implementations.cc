/*
	5Implementations.cpp
	T26：尽量用时才构造，懒惰模式。哪里用到则在哪里声明、创建（关注生命周期{}）。
	T27：尽量少做转型的动作。需要转型，试着放进自己类的函数里。
	T28：避免返回 refernces、pointer、iteration 指向对象内部。
	T29：？异常相关
	T30：inline 内联函数，是对编译器的申请，而不是强制命令。
	T31：文件编译依赖关系降到最低。如使用前置声明。

    常成员函数详解
    声明：<类型标志符>函数名（参数表）const；
    T3：const 对象，和对象的 const 方法。
    http://www.cnblogs.com/lzjsky/archive/2010/11/24/1886515.html
*/

#include <iostream>
#include <string>

class Person
{
public:
    Person():defaultID(88) {}
    Person(const std::string &name):name_(name), defaultID(88) {

        std::cout << "Person A " << name << std::endl;
    }
    virtual ~Person() {}

    void updateConstData() const {
		defaultID = 0;
    }

private:
    std::string name_;
    int defaultID;
};

int main(int argc, char const *argv[])
{

	return 0;
}