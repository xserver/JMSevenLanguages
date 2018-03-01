/*	C 语言的规范和陷阱	
	# 关键字的作用
	# 声明与定义
	代码段、数据和内存
	函数指针
	声明与定义，多个 extern 的声明，但只能有一个定义，定义就是分配内存的阶段。
*/

/*	代码风格
	https://code.google.com/p/google-styleguide/
	http://zh-google-styleguide.readthedocs.org/en/latest/contents/
*/

/*
	缺省的关键字：
	auto, automatic, 会自动回收。
	static, 对方法和变量的作用不同。是作用的范围，还是生命周期。
	extern, 全局变量，说明在别处已经存在，已经定义。

	欠缺 P355 抽象数据类型 By《C和指针》
*/

#include <stdio.h>
#include <assert.h>
 
#include "JMC_Header.h"
#include "JMC_Sub.c"

// #include <iostream>
// using namespace std;	//	不建议使用 using，而是使用 std::xx

// - - - - - - - - - - - - - - - - - - - - - - - - - - -
// # char * & enum
const char * stackData = "这种字符串是在栈上，不能修改，所以要加 const 修饰";

// - - - - - - - - - - - - - - - - - - - - - - - - - - -
// # extern 对于方法是默认缺省，对于变量是说明其在别处定义；
extern char *shareValue;
extern void shareFunction() {
	printf("%s\n", "默认函数都加了 extern 缺省关键字，全局的意思");
}

void externFunction() {

	CurrentAddress();
	int *p = array;	//	指针与数组的不同 P86
	int count = arrayLength();
	for (int i = 0; i < count; ++i)
	{
		array[i] = i;
		printf("%d  ", p[i]);
	}
	printf("\n");
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - -
// # array 数组作为参数，如何确定长度？ 想函数传递数组 P226，3维以上的数组无法作为参数

void arrayParameter(int argc, char const *argv[]) {

// 方法 A，传多一个参数，main 就是这样的。
// 延伸，多维数组，第一组放置其它组的长度。

// 方法 B，在数组最后以某个特殊值结尾，字符串就是以'\0'。
// 总之特殊的值不会作为正常的元素值出现。多维数组就是这么玩的。

// int k[][]   int k[1][]无法作为参数
// int k[1][1] int k[][1] 可以作为参数
}
// - - - - - - - - - - - - - - - - - - - - - - - - - - -
// # static 对于方法，是本文件可见。对于变量，是保持延续性，即only 全局。
static const char *currentFile = "当前文件可见";
static int * staticFunction() {

	static int dangling[3] = {1, 2, 3};	//	如果不加 static，堆栈将会销毁，指针变为悬垂指针 dangling point
	static int count = 0;
	count ++;
	printf("%s\n", currentFile);
	return dangling;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - -
// # const
void constFunction() {
	char const * pointReadonly = "pointReadonly";
	const char * valueReadonly = "valueReadonly";
	const char * const readonly = "all readonly";

	printf("%s\n", readonly);
}

int main(int argc, char const *argv[])
{
	// printf("%d\n", argc);
	// for (int i = 0; i < argc; ++i) {
	// 	printf("%s\n", argv[i]);
	// }

	pointFunction(88);
	// youAreNotSee();
	// externFunction();
	// unsignedBad();

	// switchFunction();
	
	// CurrentAddress();

	// testArrayPoint();

	// int k = intMaxFunc(1,2);
	// printf("%d\n", k);
	// k = intMax(4, 3);
	// printf("%d\n", k);


	macroDefine();
	printf("%s\n", "!! end !!");

	assert (0 == 0);
	assert (1 == 0);

	return 0;
};