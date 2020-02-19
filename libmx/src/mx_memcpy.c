#include "libmx.h"

void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n) {
	char *desti = (char*)dst;
	char *sourc = (char*)src;

	for(size_t i = 0; i < n;) {
		desti[i] = sourc[i];
		i++;
	}
	return desti;
}
