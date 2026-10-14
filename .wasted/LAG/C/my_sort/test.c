#include <stdio.h>
#include "my_sort.h"

int intcmp(const void* e1, const void* e2) {
	return *(int*)e1 - *(int*)e2;
}
void test1() {
	int num[5] = { 2045,4,1024,2,5 };
	int sz = sizeof(num) / sizeof(num[0]);
	int i = 0;
	my_bsort(num, sz, sizeof(num[0]), intcmp);

	for (i = 0; i < sz; i++) {
		printf("%d ", num[i]);
	}
	printf("\n");
}

int floatcmp(const void* e1, const void* e2) {
	return (int)(*(float*)e1 - *(float*)e2);
}
void test2() {
	float num[5] = { 1.0,4.0,2.0,3.0,5.0 };
	int sz = sizeof(num) / sizeof(num[0]);
	int i = 0;
	my_csort(num, sz, sizeof(num[0]), floatcmp);

	for (i = 0; i < sz; i++) {
		printf("%f ", num[i]);
	}
	printf("\n");
}

typedef struct Stu {
	char name[10];
	int age;
}Stu;
int Stucmp_name(const void* e1, const void* e2) {
	return strcmp(((Stu*)e1)->name, ((Stu*)e2)->name);
}
void test3() {
	Stu Stus[3] = { {"wangwei",18},{"zhaogang",13},{"guoliang",21} };
	int sz = sizeof(Stus) / sizeof(Stus[0]);
	int i = 0;
	my_isort(Stus, sz, sizeof(Stus[0]), Stucmp_name);
	for (i = 0; i < sz; i++) {
		printf("%s ", Stus[i].name);
	}
	printf("\n");
}

void test4() {
	int num[] = { 5,6,4,3,8 };
	int sz = sizeof(num) / sizeof(num[0]);
	int i = 0;
	my_qsort(num, sz, sizeof(num[0]), intcmp);
	for (i = 0; i < sz; i++) {
		printf("%d ", num[i]);
	}
}

int main() {
	printf("Test1\n");
	test1();
	printf("Test2\n");
	test2();
	printf("Test3\n");
	test3();
	printf("Test4\n");
	test4();
	return 0;
}