#include "libmx.h"

void *mx_realloc(void *ptr, size_t size) {
	void *p;
	if (ptr == NULL) {
        return p = mx_strnew(size);
    }
    else {
		p = mx_strnew(size);
		if (p == NULL) return NULL;
		mx_memcpy(p, ptr, size);
		free(ptr);
	}
	return p;
}
