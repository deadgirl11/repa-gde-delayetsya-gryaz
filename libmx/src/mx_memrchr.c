#include "libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
	unsigned char *s1 = (unsigned char*)s;
	int  len = mx_strlen(s) - 1;
	while(n--) {
		if(*(s1+len) == c) {
			return (void *) (s1 + len);
		}
		len--;
	}
 	return NULL;
 }
