#include "my_string.h"

char* my_strcpy(char* dest, const char* src) {
    int i = 0;
	assert(dest != NULL);
	assert(src != NULL);
	while (*(dest + i) = *(src + i++));
	return dest;
}
