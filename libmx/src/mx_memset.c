#include "libmx.h"

void *mx_memset(void *b, int c, size_t len) {
	unsigned char *dst = b;
	while(len  > 0) {
		dst[len-1] = (unsigned char)c;
		len--;
	}
	return b;
}
