#include "libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n) {
	char *st1 = (char*)s1;
	char *st2 = (char*)s2;

	int i = 0;
	while(st1[i] != '\0' || n > 0){
		if(st1[i] != st2[i])
			return st1[i] - st2[i];
		i++;
		n--;
	}
	return 0;
}
