#include "my_sort.h"
static void insert(void* dest, void* src , size_t size) {
	int i = 0;
	for (i = 0; i < size; i++) {
		*((char*)dest + i) = *((char*)src + i);
	}
}
static void swap(void* e1, void* e2, size_t size) {
	int i = 0, n = 0;
	for (i = 0; i < size; i++) {
		n = *((char*)e1 + i);
		*((char*)e1 + i) = *((char*)e2 + i);
		*((char*)e2 + i) = n;

	}
}
static char* get_p(void* base, size_t size, int data) {
	return (char*)base + data * size;
}


char* partition(void* base, size_t nitems, size_t size, int (*compar)(const void*, const void*)) {
	char* pivot = NULL, *left = NULL, *right = NULL;
	pivot = get_p(base, size, nitems - 1);
	left = base;
	right = get_p(pivot, size, -1);
	for (;;) {
		while (compar(left, pivot) < 0)left = get_p(left, size, 1);
		while (compar(pivot, right)< 0)right = get_p(right, size, -1);
		if (left >= right) 
			break;
		else  swap(left, right, size);
	}
	swap(pivot, left, size);
	return left;
}
void my_bsort(void* base, size_t nitems, size_t size, int (*compar)(const void*, const void*)) {
	int i = 0, j = 0, n = 0;
	for (i = 0; i < nitems - 1; i++) {
		for (j = 0; j < nitems - i - 1; j++) {
			if ((compar( get_p(base, size, j+1),get_p(base, size, j))) < 0) {
				swap(get_p(base, size, j), get_p(base, size, j+1), size);
			}
		}
	}
}
void my_csort(void* base, size_t nitems, size_t size, int (*compar)(const void*, const void*)) {
	char* max = NULL, * tmp = NULL, i = 0, j = 0;
	for (i = 0; i < nitems - 1; i++) {
		max = base;
		for (j = 0; j < nitems - i; j++) {
			if ((compar( max,get_p(base, size, j) ) < 0)) {
				max = get_p(base, size, j);
			}
		}
		if(max != (tmp = get_p(base,size,nitems-i-1)))
			swap(max, tmp, size);
	}
}
void my_isort(void* base, size_t nitems, size_t size, int (*compar)(const void*, const void*)) {
	int i = 0, j = 0;
	char* pointer = NULL , * n = NULL , *tmp = (char*)malloc(size);
	for (i = 1; i < nitems; i++) {
		pointer = get_p(base, size, i);
		insert(tmp, pointer, size);
		for (j = i-1 ; j >-1; j--) {
			if (compar(n = get_p(base, size, j), tmp)> 0) {
				insert(pointer, n, size);
				pointer = n;
			}
			else break;
		}
		insert(pointer, tmp, size);
	}

}
void my_qsort(void* base, size_t nitems, size_t size, int (*compar)(const void*, const void*)) {
	char* ret = partition(base, nitems, size, compar) , num = 0;

	if ((num = ret - base) > size) 
		my_qsort(base, num / size, size, compar);
	if ((num = get_p(base, size, nitems - 1) - ret) > size) 
		my_qsort(get_p(ret,size,1), num / size, size, compar);

}