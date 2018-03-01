#include <stdio.h>

void testReference(int age) {
	age++;
}

void testReference2(int& age) {
	age++;
}


int main(int argc, char const *argv[])
{
	int age = 1;
	testReference(age);
	printf("age = %d\n", age);


	testReference2(age);
	printf("age = %d\n", age);
	return 0;
}