#include "libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
	if(str && sub) {
		int pos;
		char *dest = mx_strstr(str, sub);
		if(dest == NULL)
			return -1;
		pos = dest - str;
		return pos;
	}
	return -2;
}
