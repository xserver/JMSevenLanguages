#include <stdio.h>

inline int age(int num);

int main(int argc, char const *argv[])
{
	printf("%d\n", age(5));
	return 0;
}


inline int age(int num) {
	return num + 5;
}

/*
	递归
	switch
	while
*/