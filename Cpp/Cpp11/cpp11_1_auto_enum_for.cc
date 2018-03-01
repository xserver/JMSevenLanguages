/*
	auto 和 decltype 自动类型推导 
	新的初始化列表，initializer list
	foreach	以范围为基础的 for 循环
	
	强类型枚举 Strongly-typed enums。原来的枚举1、会变成整形；2、两个枚举中有相同的枚举常量会冲突。新声明 enum class
	static_assert提供一个编译时的断言检查。
*/

#include "stdio.h"
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <tuple>

//	此种枚举为类型安全的。枚举类型不能隐式地转换为整数；也无法与整数数值做比较。 
enum class Options { None, One = 1, All };
Options opt = Options::All;

void autoType () {
	// 在编译时对变量进行了类型推导，不会影响编译速度，因为编译时本来也要右侧推导然后判断与左侧是否匹配。
	auto i = 00;	//	类型推断、相当于 OC 中的id？
	printf("autoType() = %d\n", i);

	std::vector<std::string> v = {"auto", "type", "function"};
	for (auto str : v) {
		printf("%s\n", str.c_str());
	}
	//	decltype(T) 可以返回 T 的类型。
	decltype(i) k = 8;
	printf("%d\n", k);
}


void foreach() {
	//	不关心下标、迭代器位置或者元素个数
	int array[] = {1, 2, 3, 4, 5};
	// for(int  e : array) {
	// for(int& e : array) {
	for(auto e : array) {
		printf("array[] = %d\n", e);
	}

	std::map<std::string, std::vector<int>> map;
	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	map["one"] = v;
	 
	for(const auto& kvp : map) {
	  std::cout << kvp.first << std::endl;
	  for(auto v : kvp.second) {
	     std::cout << v << std::endl;
	  }
	}
}

void newInit() {
	//	容器的初始化列表，和 OC 一样爽
// void FunctionName(std::initializer_list<float> list);
// FunctionName({1.0f, -3.45f, -0.4f});

	int array[3] = {1, 2, 3};

	// std::vector<int> iv{1, 2, 3};	//	2者是否有区别 ？
	std::vector<int> iv = {1, 2, 3};

	std::map<int, std::string> {{1, "a"}, {2, "b"}};

	std::string str{"Hello World"};

	//	结构体也有
	struct AltStruct 
	{
  	AltStruct(int _x, float _y) : x(_x), y(_y) {}
		private:
	  int x;
	  float y;
	};

	AltStruct var2{2, 4.3f};
}

void test_static_assert(int x) {
	// bool ff = x < 5 ? true : false;
	// static_assert(ff, "x > 5");
}

template <typename T1, typename T2>
auto add(T1 t1, T2 t2) -> decltype(t1 + t2) {

	// static_assert 结合 type traits 使用， 发挥更大的力量
  static_assert(std::is_integral<T1>::value, "Type T1 must be integral");
  static_assert(std::is_integral<T2>::value, "Type T2 must be integral");
 
  return t1 + t2;
}

void testAdd() {
	test_static_assert(2);
	int k = add(1, 2);
	// int k = add(1, 2.0);
	printf("%d\n", k);
}

int main(int argc, char const *argv[])
{
	autoType();
	foreach();
	newInit();
	return 0;
}