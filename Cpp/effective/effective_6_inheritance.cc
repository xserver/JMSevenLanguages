/*
	inheritance 继承
    virtual 的意思是，告诉编译器，这个函数可能需要重载。
    virtual = 0 的意思是，一定要重载，我什么都没做。

    C++ 支持多重继承，super不能指定哪个父类，所以使用 父类名::方法名 访问。

    T32：public继承 is-a。是否真有必要继承，而不是复合。protected private 对于继承的影响
    T33：函数重载。同名函数（函数名相同，参数不同），子类会遮挡父类所有同名函数。
        解决方法1、使用 using Base::func; 让子类可以看到父类的所有同名函数而不遮挡。
        解决方法2、函数名携带更多信息。OC 就是这样。

    T34：接口继承与实现继承（ OC 里面的区别就是 super 是否执行）
        pure virtual 必须实现。impure virtual 选择性覆盖 or 调用
        non-virtual, 子类不能重写，作为 base class 的话都会拥有相当多 virtual 函数。
    T36：子类绝不能重写父类的非虚函数！non-virtual function

    T35：NVI，使用 non-member function 函数指针 + Strategy 模式，每个对象都可以使用不同的方法。
    T37：缺省参数。virtual 里的缺省参数有时是个糟糕的设计，virtual 是动态，而缺省参数是静态绑定。
        子类绝不能重新定义virtual继承而来的缺省值！
        最好不使用缺省参数ByGoogle。
    T38：复合
    T39：private 继承是不会动态将子类转换为父类。而且所有成员都会变成 private。往往可以使用复合。
    T40：谨慎使用多重继承。

    所有继承必须是 public 的. 如果你想使用私有继承, 你应该替换成把基类的实例作为成员对象的方式.
    数据成员在任何情况下都必须是私有的.
*/

#include <iostream>
#include <string>

class Person
{
public:
    Person() {}
    Person(const std::string &name):name_(name) {
        std::cout << "Person A " << name << std::endl;
    }
    virtual ~Person() {}

    //  T34 eat() and sleep()
    virtual void eat() {    printf("person eat\n");   }
    virtual void sleep() = 0;

private:
    std::string name_;
};

// class Student : private Person // T39、T34
// class Student : protected Person
class Student : public Person
{
    int _level;
                        //  首先初始化这里，再到构造方法
public:
    Student(const std::string &name, int ssID = 0):_level(ssID)
    {
        printf("%d\n", ssID);
        // strcpy(name, pName);
        // name[sizeof(name) - 1] = '\0'; 

        // bad = Schoolbag(ssID);
    }
    ~Student()
    {
        std::cout << "Student 析构" << std::endl;
    }

    virtual void eat() {
        Person::eat();  //  OC 的 super
        printf("student eat\n");
    }
    virtual void sleep() {
        printf("student sleep\n");
    }

};


int main()
{
    Student s("Tom");
    s.eat();
    return 0;
}



