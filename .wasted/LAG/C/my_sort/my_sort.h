#pragma once
#include <string.h>
#include <stdlib.h>
void my_bsort(void* base, size_t nitems, size_t size, int (*compar)(const void*, const void*));
void my_csort(void* base, size_t nitems, size_t size, int (*compar)(const void*, const void*));
void my_isort(void* base, size_t nitems, size_t size, int (*compar)(const void*, const void*));
char* partition(void* base, size_t nitems, size_t size, int (*compar)(const void*, const void*));
void my_qsort(void* base, size_t nitems, size_t size, int (*compar)(const void*, const void*));