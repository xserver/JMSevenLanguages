#include "stdio.h"

//	初始化列表

//	const 属性 必须使用初始化列表
class ConstructorList
{
public:
	//	被 ConstructorList(int defaultID = 0) 冲突了
	// ConstructorList() {	
	// }

	ConstructorList(int defaultID = 0):id(defaultID), score(99) {

		printf("init  : %d - %d\n", this->id, this->score);
	}
	// ~ConstructorList();
	
	void print(){

		printf("print : %d - %d\n", this->id, this->score);	
	}
private:
	int id;
	int score;
};


int main(int argc, char const *argv[])
{
	ConstructorList cl;
	cl.print();
	return 0;
}