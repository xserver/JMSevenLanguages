#include "stdio.h"
// NewDelete.cc

class NewDelete
{
public:
	NewDelete() {
		printf("NewDelete\n");
	}
	~NewDelete() {
		printf("~NewDelete\n");
	}
	
};

//	malloc 是函数，new 是关键字 操作符
int main(int argc, char const *argv[])
{
	NewDelete *x = new NewDelete();
	delete x;


	NewDelete *array = new NewDelete[2];
	delete[] array;

	return 0;
}