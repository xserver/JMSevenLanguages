/*	cpp11_5_class.cc

  override，子类用来显式重载父类的 virtual 函数。解决 T33：同名函数遮挡问题。
  final，表示派生类不能重写这个虚函数了。也可以用于 class Person final {}; 就不能继承 Person 。

  委托构造函数，多个构造函数公共部分一般编写带参数的函数，在构造函数中调用这个函数。现在可以在初始化列表中调用别的构造函数。
  类成员变量初始化
  默认 or 禁用函数

  ?? 继承构造函数：可以使用 using Base::Base 导入基类的构造函数。此时子类变量没有进行初始化，需要注意使之初始化。

  constexpr， 泛化常数表达式
*/

#include <iostream>
#include <string>
#include <vector>

class Person
{
public:

    Person(const std::string &name):name_(name) {
        std::cout << "Person A " << name << std::endl;
    }

    Person() = default; //  使用系统默认的构造函数
    Person(const Person &per) = delete; //  取消 copy 函数，原来是需要在 private 里面写的。见 T6
    void operator=(const Person&) = delete; //  取消 等号 重载

    virtual ~Person() {}
    virtual void eat() {    printf("person eat\n");   }
    virtual void sleep() = 0;

private:
	std::string name_ = "nothing"; //  类成员变量初始化
    int id = 0;
};

class Student : public Person
{
public:
    // using Person::Person;
    Student(const std::string &name, int ssID = 0):Person(name), level_(ssID) {

    }
    ~Student() {
        std::cout << "Student 析构" << std::endl;
    }

    virtual void eat() override {
        Person::eat();  //  OC 的 super
        printf("student eat\n");
    }
    virtual void sleep() {
        printf("student sleep\n");
    }
private:
	int level_;
};

class BigStudent : public Student {
public:

    BigStudent():BigStudent("kiki") {}  //  委托构造函数
	BigStudent(const std::string &name):Student(name) {

	}
	virtual void eat() override {
		Person::eat();  //  OC 的 super
		Student::eat();
		printf("BigStudent eat\n");
    }
	virtual void sleep() {
		printf("BigStudent sleep\n");
	}

    // constexpr int getBig() {return 100;}
};

int main(int argc, char const *argv[])
{
    // std::vector< std::vector<int> > v = {{1,2,3}};

	BigStudent stu("Tom");
	stu.eat();
    BigStudent stu2;
	return 0;
}