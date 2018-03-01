#include "Fruit.h"
#include <stdio.h>

int Fruit::price() {
	return liveTime - 2;
}

void Fruit::printPrice() {


	printf("printPrice = %d\n", this->price());	//	√ 对象空间
	printf("printPrice = %d\n", Fruit::price());	//	类空间
}