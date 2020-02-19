#include "libmx.h"

char *mx_strdup(const char *str){
	char *dst;
	int len = mx_strlen(str);
	dst = mx_strnew(len);
	mx_strcpy(dst, str);
	return dst;
}
