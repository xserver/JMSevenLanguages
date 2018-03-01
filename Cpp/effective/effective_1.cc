/*
	术语
	non-local static
	passed by value 值传递, C++ 默认为值传递
	pass by reference to const
	
	non-member  function 非成员函数，对应的则是成员函数
	non-friend

	on the stack
	on the heap

	override 覆盖写

	pure virtual 纯虚函数 virtual = 0
	impure virtual 虚函数 virtual
	non-virtual 一般函数，不打算被覆盖（不变性凌驾特异性）

	NVI non-virtual interface
	RTTI 在运行时判断类型通常意味着设计问题. 如果你需要在运行期间确定一个对象的类型, 这通常说明你需要考虑重新设计你的类.

	static_cast C++ 显示
	const_cast

	destructor 析构函数
	constructor 构造函数
	destroy 销毁
*/

// Copyright 2014 xx Inc.
// 许可证
// Author: XuDuo | Evan

// 常量命名 在名称前加 k: kDaysInAWeek.
const int kDaysInAWeek = 7;
enum UrlTableErrors {	//	枚举也要
    kOK = 0,
    kErrorOutOfMemory,
    kErrorMalformedInput,
};

// 宏命名: MY_MACRO_THAT_SCARES_SMALL_CHILDREN.
#define PI_ROUNDED 3.0

class Person
{
public:
	Person() {}
	~Person(){}

	/* data */
};

// TODO(XQL) 对那些临时的, 短期的解决方案, 或已经够好但仍不完美的代码使用 TODO 注释.
// 函数注释
	// 函数的输入输出.
	// 对类成员函数而言: 函数调用期间对象是否需要保持引用参数, 是否会释放这些参数.
	// 如果函数分配了空间, 需要由调用者释放.
	// 参数是否可以为 NULL.
	// 是否存在函数使用上的性能隐患.
	// 如果函数是可重入的, 其同步前提是什么?

// 只使用空格, 每次缩进 2 个空格.
int main(int argc, char const *argv[])
{
  float f = 166.71;
  int i = static_cast<int>(f);

  const Person a;
  Person b = a;

	return 0;
}