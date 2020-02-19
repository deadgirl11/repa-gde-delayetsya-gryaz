#include "libmx.h"

void *mx_memchr(const void *s, int c, size_t n) {
	unsigned char *s1 = (unsigned char*)s;
	unsigned long i = 1;
 	while(*s1 && i < n) {
 		if(*s1 == (unsigned char)c)
 			return s1;
 		s1++;
 		i++;
 	}
 	return NULL;
}
