/*
	Life.cpp
	基类子对象，成员对象，引用，const成员必须放到成员初始化列表里面初始化。

	T5：系统默认提供：构造函数、析构、拷贝、拷贝赋值。
	T6：明确取消系统默认方法
	T7：为多态的基类声明 virtual 析构函数。virtual 说明子类和父类的方法具有关联性。
		// parent p = child(); delete p; 
		// 删除 parent，只会执行 parent 的析构方法。而不会执行 child 的析构方法。
		// 而提供了 virtual，编译器就会懂得需要找 child 的同名方法。

	T8：别让析构函数吐出异常，导致不确定。 不使用异常ByGoogle
	T9：在构造和析构过程中，不能调用任何 virtual 方法
	T11：operator = 自我赋值。除少数特定环境外，不要重载运算符。尤其是赋值操作 (operator=) 比较诡异, 应避免重载。
	T12：复制所有成员变量，包括父类的

	http://zh-google-styleguide.readthedocs.org/en/latest/google-cpp-styleguide/classes/#id2

	相关：virtual.cpp
*/

#include "string"

// 禁止使用拷贝构造函数和 operator= 赋值操作的宏
// 应该类的 private: 中使用
#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
            TypeName(const TypeName&); \
            void operator=(const TypeName&)

#define DISALLOW_COPY_FUNC(TypeName) TypeName(const TypeName&)
#define DISALLOW_ASSIGN_FUNC(TypeName) void operator=(const TypeName&)
            

class Bitmap	{};

class Person
{
public:	
	//	提供2个构造函数
	Person() {
		printf("Person() = %s\n", name_.c_str());
	}
	Person(const std::string &name):name_(name) {
		printf("Person(name) = %s\n", name.c_str());
	}
	//	这个是拷贝函数
	Person(const Person& rhs) {
		printf("%s\n", name_.c_str());
	}
	Person& operator = (const Person& rhs) {
		return *this;
	}
	void setName(const std::string &name) {}

private:
	// 变量名一律小写, 单词之间用下划线连接. 类的成员变量以下划线结尾
	std::string name_;	//	结束跟下划线
};

class Schoolbag
{
public:
	Schoolbag(const int color):color_(color) {
		printf("schoolbag init color = %d\n", color_);
	}
	Schoolbag(const Schoolbag& sb) {
		color_ = sb.color_;	
		printf("%s %d\n", "Schoolbag copy color = ", color_);
	}
	int getColor() {
		return color_;
	}
private:
	int color_;
	DISALLOW_ASSIGN_FUNC(Schoolbag);
};

class Student : public Person
{
	std::string name;
	Bitmap *pb;	//	指向 heap
	int level;
	Schoolbag bad;

public:
	Student() : Person("Tom"), bad(5) {	}

	virtual ~Student() {
    	// T8：C++不喜欢在析构函数吐出异常。
    	// 如果异常不终止，向上层扩散，会导致不明确的 bug
    	// 异常不幸出现，解决：A、std::abort();死亡。B、catch(...){仅仅记录，吞下它} C、...T8反正别出现异常
	}

	//	copy
	Student(const Student& rhs, int color = 3) : Person(rhs), bad(color) {
		//	T12：千万别忘记 copy||init 任何一个成员，因为 CPP 没有帮我们做 init 的操作。
		//	父类的成员变量... 需要调用父类的
		//	copy all parts of an object.
	}

	//	重定义赋值，有拷贝函数一样。
	Student& operator = (const Student& rhs) {

		//	T11：自我赋值的问题，copy and swap
		if (this == &rhs){	//	超低出现率
			return *this;
		}

		Person::operator = (rhs);//	T12：调用父类的

		Bitmap *old = pb;//	T11，赋值后再删除旧数据。
		pb = new Bitmap(*rhs.pb);
		delete old;	//	OC 的味道

		this->name = rhs.name;
		return *this;
	}

	Schoolbag getSchoolbag() {
		printf("stu getSchoolbag %p\n", &bad);
		return bad;
	}

private:
	//	T6：将函数声明为 private并不需实现，系统就不提供默认方法了。
	// Student(const Student& rhs);
};


int main(int argc, char const *argv[])
{
	Student stu1;
	// Student *Student2(stu1);
	printf("main getSchoolbag = %d\n", stu1.getSchoolbag().getColor());

	Schoolbag sb = stu1.getSchoolbag();
	printf("main %p\n", &sb);
	return 0;
}