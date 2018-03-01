/*	cpp11_6_lambda.cc
	Lambda表达式

	http://msdn.microsoft.com/en-us/library/dd293603.aspx
	http://blog.csdn.net/xqs83/article/details/7612866

	1、获得外界变量的方式
	[ ]			空的，不能使用外部变量（当前作用域）。[=]值传递所有变量，包括 this[&]引用传递所有变量，包括 this[vir]值传递变量 vir
	[&vir]	引用传递变量 vir
	[this]	值传递 this ???
	[=, &vir]	所有按值传递，唯独 vir 按引用传递

	2、传进来的参数
	(int vir)		参数使用值传递
	(int &vir)	参数使用引用传递

	3、mutable 修饰 传进来的参数，使之可以修改，即使是 const的数据。
	     mutable 能修改值传递进来的数据（不是原数据）
	     mutable 是为了突破const的限制而设置的。被mutable修饰的变量，将永远处于可变的状态，即使在一个const函数中。
	4、抛出异常
	5、返回值
*/
	
#include <iostream>
#include <vector>

void lambad() {
	//	[] 传入的东西可以是 [=]（获得所有变量），[vir]（获得vir）
	std::vector<int> v = {1, 2, 3};
	 
	std::for_each(std::begin(v), std::end(v), [](int n) {std::cout << n << std::endl;});
	 
	auto is_odd = [](int n) {return n%2 == 1;};
	auto pos = std::find_if(std::begin(v), std::end(v), is_odd);

	if(pos != std::end(v)) {
		std::cout << *pos << std::endl;
	}
}

void printElem(int elem) {
	std::cout << elem << std::endl;
}

class LambdaClass
{
public:
	LambdaClass():number(20) {}
	~LambdaClass() {}

	void testLambda() {
		std::vector<int> vecTemp = {1, 2};

		// for_each 语法
		for_each (std::begin(vecTemp), std::end(vecTemp), printElem);

		// 无函数对象参数，输出：1 2
		{
			for_each ( vecTemp.begin(), vecTemp.end(), 
				[](int v) { std::cout << v << std::endl; }
			);
			printf("%s\n", "AA - - - - ");
		}

		// 以值方式传递作用域内所有可见的局部变量（包括this），输出：11 12
		{
			int a = 10;
			for_each(vecTemp.begin(), vecTemp.end(), 
				[=](int v) { 
					std::cout << v+a << std::endl; 
			});
			printf("%s\n", "BB - - - - ");
		}

		// 以引用方式传递作用域内所有可见的局部变量（包括this），输出：11 13 12
		{
			int a = 10;
			for_each(vecTemp.begin(), vecTemp.end(), 
		 		[&] (int v) mutable { 
		 			std::cout << v + a << std::endl; 
		 			a++;
		 		}
		 	);
			std::cout << a << std::endl;
			printf("%s\n", "CC - - - - ");
		}

		// 以值方式传递局部变量a，输出：11 13 10
		{
			int a = 10;
			for_each(vecTemp.begin(), vecTemp.end(), 
				[a] (int v) mutable { 
					std::cout << v+a << std::endl; a++; 
				}
			);
			std::cout << a << std::endl;
			printf("%s\n", "DD - - - - ");
		}

		// 以引用方式传递局部变量a，输出：11 13 12
		{
			int a = 10;
			for_each(vecTemp.begin(), vecTemp.end(), 
				[&a](int v) { 
					std::cout << v+a << std::endl; a++; 
				}
			);
			std::cout << a << std::endl;
			printf("%s\n", "EE - - - - ");
		}

		// 传递this，输出：21 22
		{
			for_each(vecTemp.begin(), vecTemp.end(), 
				[this] (int v) { 
					std::cout << v + number << std::endl; 
				});
			printf("%s\n", "FF - - - - ");
		}

		// 除b按引用传递外，其他均按值传递，输出：11 12 17
		{
			int a = 10;
			int b = 15;
			for_each(vecTemp.begin(), vecTemp.end(), 
				[=, &b] (int v) { 
					std::cout << v+a << std::endl; b++; 
			});
			std::cout << b << std::endl;
			printf("%s\n", "GG - - - - ");
		}

		// 操作符重载函数参数按引用传递，输出：2 3
		{
		 for_each(vecTemp.begin(), vecTemp.end(), [](int &v){ v++; });
		 for_each(vecTemp.begin(), vecTemp.end(), [](int v) { std::cout << v << std::endl; });
		 printf("%s\n", "End - - - - ");
		}

		// 空的Lambda表达式
		{
		 [](){}();
		 []{}();
		}
	}

private:
	int number;
};

int main(int argc, char const *argv[])
{
	LambdaClass lc;
	lc.testLambda();
	return 0;
}