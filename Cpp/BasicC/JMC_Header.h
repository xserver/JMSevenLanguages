/*
	什么东西应该放在 header file ？
	头文件保护
*/

#ifndef JMC_Header_H_
#define JMC_Header_H_

#include <stdio.h>
extern void macroDefine();
int *test1, test2;	//	test2 并非指针而是 缺省类型 int。所以一般一行声明一个。

//	marco 约定全大写 or 带前缀 Marco
#define CurrentAddress(); printf("\n- - - line : %3d  ||  func : %s\n",__LINE__,__func__);
#define defArrayLength 10

#define intMax(a,b) ((a)>(b)?(a):(b))
inline int intMaxFunc(int a, int b) {
	return a > b ? a : b;
}
// # typedef
typedef char * NGString;

enum type_tag {tag1 = 1, tag2 = 2, tag3};

// # struct 与 typedef

#ifndef MaxPeopleCount
#define MaxPeopleCount 56 	//	marco 的空格弊端
#endif

struct student	//	大的放上面，相同类型的放一起，用于对齐
{
	int age;
	int id;
	char *name;
	char sex;
};

#define pop stack[top--]
#define push(s) stack[++top] = s

struct student stack[MaxPeopleCount];
int top = -1;

// extern int *array;	//	指针 != 数组，这里是错误的！
extern int array[];	//	在别处定义的数组

// extern 是缺省的关键字
void switchFunction();
void unsignedBad();
extern void youAreNotSee();
extern void testArrayPoint2(int array2[]);
extern void testArrayPoint3(int *array3);
extern void testArrayPoint();

extern void allocMemory();

// - - - - - - - - - - - - - - - - - - - - - - - - - - -
// # inline 内联函数的诞生，是为了给 marco 遮羞，继承 marco 的优点。
// inline函数仅仅是一个建议,对编译器的建议,所以最后能否真正内联,看编译器的意思
// 少于10行，应该放在 header file。 -inl.h

// extern inline 与 static inline 
// 首先要明白 extern 的作用，说明对象已经声明过了。
// static 是在当前文件可见

inline int arrayLength() {	
	printf("line : %3d  ||  func : %s\n", __LINE__, __func__);	//__FILE__
	return defArrayLength;	
};

// 每个函数都有一个地址，万物皆有地址，所以可以有函数指针
// 函数操作符
// int * f();
// int (*f) ();

extern int myFunction(int number);
int (*pointFunction) (int) = &myFunction;

//	传入一个比较的方法，比较2个对象，类比 ObjC 的 block
extern int compare(void const *v1, void const *v2, int (compareP)(void const *, void const *));

#endif	//	JMC_Header_H_

