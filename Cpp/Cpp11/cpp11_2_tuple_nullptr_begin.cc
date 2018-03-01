/*

	新的空指针 nullptr，NULL 与 0 的二义性。
	像 Lua 元组的 tuple， pair的升级版
	统一迭代器。以前只有 vector 等数据容器可以使用begin-end 迭代器循环，non-member begin() and end()

	http://www.cnblogs.com/hujian/archive/2012/12/07/2807941.html
	模板别名
	新的字符串
	包装引用
	constexpr， 泛化常数表达式
*/

#include "stdio.h"
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <tuple>

// 模板别名, 
// class Person
// {
// public:
// 	Person() {}
// 	~Person() {}

// };

// using myTypedeName = Person <>;

void nullPointer() {
	int* p1 = NULL;
	int* p2 = nullptr;	//	空指针
	if(p1 == p2) {
	}
}

void tableType() {
	//	新的容器 tuple，像 Lua 中的元组 table
	// http://www.cnblogs.com/zhuyp1015/archive/2012/04/08/2438187.html
	auto t1 = std::make_tuple(1, 2.0, "C++ 11");
	// printf("%s\n", t1);
}

void beginAndEnd() {
	std::vector<int> v = {1, 2, 3};
	for_each (v.begin(), v.end(), [](int i){std::cout << i << std::endl; });

	//	统一语法
	for_each (std::begin(v), std::end(v), [](int i){std::cout << i << std::endl; });

	//	统一语法，现在数组也可以使用 for_each 了
	int array[3] = {4, 5, 6};
	std::for_each (std::begin(array), std::end(array), [](int i){std::cout << i << std::endl; });
}

// template<typename head, typename... tail>
// void Print(Head head, typename... tail) {
//     std::cout << head << std::endl;
//     Print(tail...);
// }
// Print(1, 1.0, "C++11");

int main(int argc, char const *argv[])
{

	// lambad();
	std::vector<int> v = {1, 2, 3};
	beginAndEnd();
	return 0;
}