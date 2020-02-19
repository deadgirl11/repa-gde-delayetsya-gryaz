#include "libmx.h"

char *mx_strjoin(const char *s1, const char *s2) {
	if(s1 == NULL && s2 == NULL)
		return NULL;
	if(s1 == NULL || s2 == NULL) {
		if(s1 == NULL)
			return mx_strdup(s2);
		else
			return mx_strdup(s1);
	}
	int m = mx_strlen(s1) + mx_strlen(s2);
	char *dst = mx_strnew(m);
	mx_strcpy(dst, s1);
	mx_strcat(dst, s2);
	return dst;
}
