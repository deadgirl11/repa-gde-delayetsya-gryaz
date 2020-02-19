#include "libmx.h"

char *mx_strndup(const char *s1, size_t n){
	char *dst = mx_strnew(n);

	if (!dst) {
        return NULL;
    }
    
	return mx_strncpy(dst, s1, n);;
}
