#include <stdio.h>

int main(int argc, char const *argv[])
{
	int a[10] = {1};

	printf(" %p\n %p\n %p\n",a, &a[0], &a);

	printf("a[0] = %d\n", a[0]);


	char str[10] = {'A'};
	printf("str[0] = %d\n", str[2]);

	char str2[10] = "ABCD";
	printf("str2[0] = %c\n", str2[2]);
	// printf("%s\n", a);



	return 0;
}