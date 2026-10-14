#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include"my_string.h"

int main() {
	char a[] = "I love C";
	char b[] = "I love Python";
	char c[] = "I love Java";
	char* (*string[])(char*, const char*) = { my_strcpy ,&my_strcpy};

	printf("a = %s , b = %s , c = %s\n", a, b, c);

	my_strcpy(c, b);
	printf("a = %s , b = %s , c = %s\n", a, b,c);

	string[0](c, a);
	printf("a = %s , b = %s , c = %s\n", a, b, c);

	string[1](b, c);
	printf("a = %s , b = %s , c = %s\n", a, b, c);

	return 0;
}