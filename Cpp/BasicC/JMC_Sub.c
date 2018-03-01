#include "JMC_Header.h"

int array[10];

void youAreNotSee() {
	printf("%s  %s\n", __FILE__, __func__);
	CurrentAddress();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - -
// # switch
void switchFunction() {

	type_tag tag = tag1;
	switch(tag) {
		case tag1 : printf("%s", "switch break 的弊端，");
		case tag2 : printf("%s\n", "就是这样！"); break;
		case tag3 : printf("%s\n", "haha");
	}
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - -
// # unsigned 的弊端，最好别用。
void unsignedBad() {

	unsigned int i = -1;
	printf("%s", "如果传入的是负数，那么结果将异常：");
	printf("%u\n", i);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - -
// # array 数组作为参数，地址 != 搜地址
void testArrayPoint2(int array2[]) {
	CurrentAddress();

	printf("array1 sizeof = %lu\n", sizeof(array));
	printf("array1 = %p\n", &array);
	printf("array1[0] = %p\n\n", &(array[0]));

	printf("array2 sizeof = %lu\n", sizeof(&array2));
	printf("array2 = %p\n", &array2);
	printf("array2[0] = %p\n\n", &(array2[0]));
}

void testArrayPoint3(int *array3) {
	CurrentAddress();

	printf("array1 sizeof = %lu\n", sizeof(array));
	printf("array1 = %p\n", &array);
	printf("array1[0] = %p\n\n", &(array[0]));

	printf("array3 sizeof = %lu\n", sizeof(array3));
	printf("array3 = %p\n", &array3);
	printf("array3[0] = %p\n\n", &(array3[0]));
}

void testArrayPoint() {

	testArrayPoint2(array);
	testArrayPoint3(array);
}

int myFunction(int number) {
	CurrentAddress();
	printf("number = %d\n", number);
	return number + 1;
}

void macroDefine() {

	#if defined(OSX)
		printf("OSX ??");
	#elif defined(OSX)
		printf("OSX = nil");
	#else
		printf("elif = else if\n");
	#endif

	#ifdef OSX
		printf(OSX);
	#else
		printf("没有OSX\n");
	#endif

	#ifndef OSX
	#define OSX "0^0"
		printf("没有则定义 ta");
	#endif
}

extern void allocMemory() {
	// malloc 与 calloc 的区别是后者会初始化为0，还有参数也不同
	// realloc 修改内存大小，无法改变大小则重新申请大块的，就旧的数据移过去，所以可能会造成性能抖动。

	// 是否成功、操作是否越界、是否释放、是否解除引用
	// calloc();
}